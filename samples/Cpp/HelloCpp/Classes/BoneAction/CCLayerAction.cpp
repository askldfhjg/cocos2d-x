#include "cocos2d.h"
#include "CCBones.h"
#include "CCEffect.h"
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

CCLayerAction* CCLayerAction::create(const char *name, CCNode *node, double interval, float time)
{
    CCLayerAction *pAction = new CCLayerAction();
    pAction->initWithFrame(name, node, interval, time);
    pAction->autorelease();
    return pAction;
}
/*
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
*/
bool CCLayerAction::initWithFrame(const char *name, CCNode *node, double interval, float time)
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
		if(time <= 0)
		{
			setDuration(totalFrameCount * interval);
		}
		else
		{
			setDuration(time);
		}
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
	/*bool actionDone = false;
	if(action == NULL)
	{
		actionDone = true;
	}
	if(action != NULL && action->isDone())
	{
		actionDone = true;
	}

	return m_isDone && actionDone;*/
	return m_isDone;
}

void CCLayerAction::setSameNameContinue(bool flag)
{
	sameNameContinue = flag;
}

void CCLayerAction::step(float dt)
{
	if (m_bFirstTick)
    {
        m_bFirstTick = false;
		m_elapsed = 0;
		CCBoneSpriteLayer  *layer = (CCBoneSpriteLayer *)m_pTarget;
		if(sameNameContinue && layer->lastFrame >= startFrame[nowStage] && layer->lastFrame <= endFrame[nowStage])
		{
			float n = layer->lastFrame - startFrame[nowStage];
			m_elapsed += n * 1.0/24;
		}
        sameNameContinue = false;
    }
    else
    {
        m_elapsed += dt;
    }
    
    this->update(MAX (0,                                  // needed for rewind. elapsed could be negative
                      MIN(1, m_elapsed /
                          MAX(m_fDuration, FLT_EPSILON)   // division by 0
                          )
                      )
                 );
}

void CCLayerAction::update(float frame)
{
	/*if(action != NULL && !action->isDone())
	{
		action->setTarget(m_pTarget); 
		action->setOriginalTarget(m_pTarget);
		action->update(frame);
	}*/
	if(m_isDone)
	{
		return;
	}
	CCBoneSpriteLayer  *layer = (CCBoneSpriteLayer *)m_pTarget;

	int n = (int)(frame * totalFrameCount);
	nowFrame = n + startFrame[nowStage];
	//nowFrame = 7;
	layer->frameIndex = nowFrame;
	if(layer->m_clip)
	{
		layer->m_clip->setFrame(nowFrame);
	}
	CCBones::setFrame(layer->m_bone, nowFrame, n);
	int frm = nowFrame;
	nowFrame++;
	layer->lastFrame = nowFrame;
	if(nowFrame > endFrame[nowStage])
	{
		nowStage++;
		if(nowStage >= totalStage)
		{
			m_isDone = true;
			layer->lastFrame = startFrame[nowStage-1];
		}
		else
		{
			nowFrame = startFrame[nowStage];
		}
	}
	if(layer->haveEffect())
	{
		CCEffect::setFrame(layer->m_effect, frm, n, m_isDone);
	}
}
