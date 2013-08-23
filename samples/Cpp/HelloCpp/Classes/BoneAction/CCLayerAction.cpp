#include "cocos2d.h"
#include "CCBone.h"
#include "CCLayerAction.h"
#include "Function.h"
#include "CCBoneSpriteLayer.h"
#include "../../extensions/spine/Json.h"
USING_NS_CC;
using namespace cocos2d::extension;

int CCLayerAction::obj = 99999;
CCLayerAction::~CCLayerAction(void)
{
	CC_SAFE_DELETE_ARRAY(startFrame);
	CC_SAFE_DELETE_ARRAY(endFrame);
	CC_SAFE_RELEASE(action);
}

CCLayerAction* CCLayerAction::create(const char *name, CCNode *node, double interval)
{
    CCLayerAction *pAction = new CCLayerAction();
    pAction->initWithFrame(name, node, interval);
    pAction->autorelease();
    return pAction;
}
CCLayerAction* CCLayerAction::create(const char *name, CCFiniteTimeAction *layerMove, BoneMotion actionType, CCNode *node, double interval)
{
	CCLayerAction *pAction = new CCLayerAction();
    pAction->initWithFrame(name, node, interval);
    pAction->autorelease();
	pAction->action = layerMove;
	CC_SAFE_RETAIN(layerMove);
	if(actionType == BoneMotionTypeSlow && layerMove != NULL)
	{
		pAction->actionTime = layerMove->getDuration();
		pAction->setDuration(pAction->actionTime);
	}
	if(layerMove != NULL && layerMove->getDuration() > pAction->getDuration())
	{
		pAction->setDuration(layerMove->getDuration());
	}
	return pAction;
}

bool CCLayerAction::initWithFrame(const char *name, CCNode *node, double interval)
{
    m_bFirstTick = true;
	CC_SAFE_DELETE_ARRAY(startFrame);
	CC_SAFE_DELETE_ARRAY(endFrame);
	int count = 0;
	int start, end;

	CCBoneSpriteLayer *tmp = (CCBoneSpriteLayer *)node;
	bool hasLabel = tmp->getLabel(name, start, end);
	if(hasLabel)
	{
		startFrame = new int[10];
		endFrame = new int[10];
		startFrame[count] = start;
		endFrame[count] = end;
		count++;
		m_isDone = false;
		totalStage = count;
		nowStage = 0;
		nowFrame = startFrame[0];
		totalFrameCount = end - start + 1;
		setDuration(totalFrameCount * interval);
	}
	else
	{
		CCLog("no label %s", name);
	}

	
	return true;
}

void CCLayerAction::startWithTarget(CCNode* pTarget)
{
	if(action != NULL)
	{
		action->startWithTarget(pTarget);
	}
	if(startFrame != NULL)
	{
		nowFrame = startFrame[0];
		m_isDone = false;
		CCActionInterval::startWithTarget(pTarget);
	}
	else
	{
		m_isDone = true;
		nowFrame = 0;
	}
	nowStage = 0;
}

bool CCLayerAction::isDone(void)
{
	bool actionDone = false;
	if(action == NULL)
	{
		actionDone = true;
	}
	if(action != NULL && action->isDone())
	{
		actionDone = true;
	}
	if(m_isDone && actionDone)
	{

	}
	return m_isDone && actionDone;
}

void CCLayerAction::update(float frame)
{
	if(action != NULL && !action->isDone())
	{
		action->setTarget(m_pTarget); 
		action->setOriginalTarget(m_pTarget);
		action->update(frame);
	}
	if(m_isDone)
	{
		return;
	}
	CCBoneSpriteLayer  *layer = (CCBoneSpriteLayer *)m_pTarget;

	int n = (int)(frame * totalFrameCount);
	nowFrame = n + startFrame[nowStage];
	//nowFrame = 17;
    char str[256]={0};
	Func::itostr(nowFrame, str);
	CCObject* child = NULL;
	CCARRAY_FOREACH(layer->m_bone, child)
	{
		CCBone *ch = (CCBone *)child;
		if(nowFrame > ch->endFrame)
		{
			ch->setVisible(false);
			continue;
		}
		Json *source = Json_getItem(ch->m_frame, str);
		if (source)
		{
			int c = Json_getSize(source);
			if(c <= 0)
			{
				return;
			}
			CCAssert(c == 8, "count error");
			float posX = Json_getItemAt(source, 0)->valuefloat;
			float posY = Json_getItemAt(source, 1)->valuefloat;
			float scaleX = Json_getItemAt(source, 2)->valuefloat;
			float scaleY = Json_getItemAt(source, 3)->valuefloat;
			float skewX = Json_getItemAt(source, 4)->valuefloat;
			float skewY = Json_getItemAt(source, 5)->valuefloat;
			float visable = Json_getItemAt(source, 6)->valuefloat;
			float brightness = Json_getItemAt(source, 7)->valuefloat;

			ch->setBrightness(brightness);
			ch->setPosition(ccp(ch->m_startPosition.x + posX, ch->m_startPosition.y + posY));
			ch->setRotationX(ch->m_fStartAngleX + skewX);
			ch->setRotationY(ch->m_fStartAngleY + skewY);
			ch->setScaleX(ch->m_fStartScaleX * scaleX);
			ch->setScaleY(ch->m_fStartScaleY * scaleY);

			bool vis = ch->isVisible();

			float alf = ch->getAlpha();
			if(vis != (bool)(int)visable || alf != visable)
			{ 
				if((bool)(int)visable)
				{
					ch->setVisible(true);
					ch->setAlpha(1.0f);
				}
				else if(visable <= 0)
				{
					ch->setVisible((bool)false);
					ch->setAlpha(0);
				}
				else
				{
					ch->setVisible(true);
					ch->setAlpha(visable);
				}
			}
		}
		else
		{
			if(n == 0)
			{
				ch->setPosition(ccp(ch->m_startPosition.x, ch->m_startPosition.y));
				ch->setRotationX(ch->m_fStartAngleX);
				ch->setRotationY(ch->m_fStartAngleY);
				ch->setScaleX(ch->m_fStartScaleX);
				ch->setScaleY(ch->m_fStartScaleY);
				ch->setVisible((bool)ch->m_startVisable);
			}
		}

	}
	nowFrame++;
	if(nowFrame > endFrame[nowStage])
	{
		nowStage++;
		if(nowStage >= totalStage)
		{
			m_isDone = true;
		}
		else
		{
			nowFrame = startFrame[nowStage];
		}
	}
}
