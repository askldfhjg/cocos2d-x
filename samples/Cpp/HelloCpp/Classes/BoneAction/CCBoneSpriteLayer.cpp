#include "cocos2d.h"
#include "Function.h"
#include "CCBoneSpriteLayer.h"
#include "CCBoneActionManager.h"
#include "CCBoneTextureManager.h"
#include "CCBone.h"
#include "CCEffect.h"
#include "../../extensions/spine/Json.h"
USING_NS_CC;
using namespace cocos2d::extension;

CCBoneSpriteLayer::~CCBoneSpriteLayer(void)
{
	m_bone->removeAllObjects();
	m_effect->removeAllObjects();
	CC_SAFE_RELEASE(m_bone);
	CC_SAFE_RELEASE(m_effect);
}

CCBoneSpriteLayer *CCBoneSpriteLayer::create(const char *spriteName)
{
	CCBoneSpriteLayer *pRet = new CCBoneSpriteLayer();
	if (pRet && pRet->init(spriteName, false))
	{
		pRet->autorelease();
		return pRet; 
	}
	else
	{
		delete pRet;
		pRet = NULL;
		return NULL;
	}
}
CCBoneSpriteLayer *CCBoneSpriteLayer::create(const char *spriteName, char *animationName)
{
	CCBoneSpriteLayer *pRet = new CCBoneSpriteLayer();
	if (pRet && pRet->init(spriteName, false))
	{
		pRet->autorelease();
		pRet->setAnimation(animationName);
		return pRet; 
	}
	else
	{
		delete pRet;
		pRet = NULL;
		return NULL;
	}
}

CCBoneSpriteLayer *CCBoneSpriteLayer::createWithBatch(const char *spriteName)
{
	CCBoneSpriteLayer *pRet = new CCBoneSpriteLayer();
	if (pRet && pRet->init(spriteName, true))
	{
		pRet->autorelease();
		return pRet; 
	}
	else
	{
		delete pRet;
		pRet = NULL;
		return NULL;
	}
}

CCBoneSpriteLayer *CCBoneSpriteLayer::createWithBatch(const char *spriteName, char *animationName)
{
	CCBoneSpriteLayer *pRet = new CCBoneSpriteLayer();
	if (pRet && pRet->init(spriteName, true))
	{
		pRet->autorelease();
		pRet->setAnimation(animationName);
		return pRet; 
	}
	else
	{
		delete pRet;
		pRet = NULL;
		return NULL;
	}
}

void CCBoneSpriteLayer::setAnimation(char *name)
{
	Json *animation = CCBoneActionManager::sharedManager()->getAnimation(name);
	this->m_label = Json_getItem(animation, "label");
	CCObject* child = NULL;
	CCARRAY_FOREACH(m_bone, child)
	{
		CCBone *ch = (CCBone *)child;
		ch->m_frame = Json_getItem(animation, ch->getName());
	}

	bool effect = (bool)Json_getItem(animation, "effect")->valueint;
	if(effect)
	{
		Json *effectAnimation = CCBoneActionManager::sharedManager()->getEffectAnimation(name);

		CCObject* child = NULL;
		CCARRAY_FOREACH(m_effect, child)
		{
			CCEffect *ch = (CCEffect *)child;
			ch->removeFromParent();
		}
		m_effect->removeAllObjects();
		isEffect = true;

		Json *motion = Json_getItem(effectAnimation, "motion");
		Json *info = Json_getItem(effectAnimation, "effect");
		int count = Json_getSize(motion);
		for(int i = 0;i < count;i++)
		{
			Json *tmp = Json_getItemAt(motion, i);
			std::string tmpString = tmp->name;
			CCEffect *effect = CCEffect::create(tmpString);
			effect->m_frame = tmp;
			effect->m_effectInfo = info;
			effect->setStartStatus(false);
			effect->setVisible(false);
			this->addChild(effect, 1000 - i);
			m_effect->addObject(effect);
		}
	}
}

bool CCBoneSpriteLayer::haveEffect()
{
	return isEffect;
}

bool CCBoneSpriteLayer::getLabel(const char *name, int &startFrame, int &endFrame)
{
	Json *tmp = Json_getItem(m_label, name);
	if(tmp == NULL)
	{
		return false;
	}
	startFrame = Json_getItemAt(tmp, 0)->valueint;
	endFrame = Json_getItemAt(tmp, 1)->valueint;
	return true;
}

CCBone *CCBoneSpriteLayer::getBoneByName(const char *name)
{
    if(m_bone != NULL && m_bone->count() > 0)
    {
        CCObject* child;
        CCARRAY_FOREACH(m_bone, child)
        {
            CCBone* pNode = (CCBone*) child;
			const char * tmp = pNode->getName();
			if(pNode && !strcmp(tmp,name))
                return pNode;
        }
    }
    return NULL;
}
void CCBoneSpriteLayer::changeBoneTexture(CCDictionary *info)
{
	if(isBatch)
	{
		return;
	}
	CCSpriteFrameCache *cache = CCSpriteFrameCache::sharedSpriteFrameCache();
    if(m_bone != NULL && m_bone->count() > 0)
    {
        CCObject* child;
        CCARRAY_FOREACH(m_bone, child)
        {
            CCBone* tmpBone = (CCBone*) child;
			const char * tmp = tmpBone->getName();
			CCString *texture = (CCString *)info->objectForKey(tmp);
			if(texture == NULL)
			{
				continue;
			}
			Json* root = CCBoneTextureManager::sharedManager()->getEquip(const_cast<char*>(texture->getCString()));
			if(root == NULL)
			{
				continue;
			}
			Json *source = Json_getItem(root, tmp);
			if(!source)
			{
				continue;
			}
			source = Json_getItemAt(source, 0);
			if(source)
			{
				const char *pic = Json_getItemAt(source, 0)->valuestring;
				float scaleX = Json_getItemAt(source, 1)->valuefloat;
				float scaleY = Json_getItemAt(source, 2)->valuefloat;
				float leftOffset = Json_getItemAt(source, 3)->valuefloat;
				float topOffset = Json_getItemAt(source, 4)->valuefloat;

				tmpBone->setDisplayFrame(cache->spriteFrameByName(pic));
				CCRect rect = tmpBone->getTextureRect();
				float archX = (leftOffset + tmpBone->getLeftOffset()) / rect.size.width;
				float archY = (topOffset + tmpBone->getTopOffset()) / rect.size.height;
				tmpBone->setAnchorPoint(ccp(archX , 1 - archY));
				tmpBone->setScaleX(scaleX);
				tmpBone->setScaleY(scaleX);
				tmpBone->setPosition(tmpBone->m_startPosition);
				tmpBone->setRotationX(tmpBone->m_fStartAngleX);
				tmpBone->setRotationY(tmpBone->m_fStartAngleY);
				tmpBone->setVisible(tmpBone->m_startVisable);
			}
			else
			{
				tmpBone->setDisplayFrame(tmpBone->m_pic);
				tmpBone->setAnchorPoint(tmpBone->m_startArch);
				tmpBone->setScaleX(tmpBone->m_fStartScaleX);
				tmpBone->setScaleY(tmpBone->m_fStartScaleY);
				tmpBone->setPosition(tmpBone->m_startPosition);
				tmpBone->setRotationX(tmpBone->m_fStartAngleX);
				tmpBone->setRotationY(tmpBone->m_fStartAngleY);
				tmpBone->setVisible(tmpBone->m_startVisable);
			}
			ccBlendFunc blend2 = {GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA};
			tmpBone->setShaderProgram(CCBone::getShader());
			tmpBone->setBlendFunc(blend2);
        }
    }
}

void CCBoneSpriteLayer::changeBoneTexture(const char *textureName, const char *boneName, const char* equipName)
{
	if(isBatch)
	{
		return;
	}
	CCSpriteFrameCache *cache = CCSpriteFrameCache::sharedSpriteFrameCache();
	Json* root = CCBoneTextureManager::sharedManager()->getEquip(const_cast<char*>(textureName));
	if(root == NULL)
	{
		return;
	}
	CCBone* tmpBone = getBoneByName(boneName);
    if(tmpBone != NULL)
    {
		Json *source = Json_getItem(root, boneName);
		if(!source)
		{
			return;
		}
		int size = Json_getSize(source);

		if(size > 1)
		{
			if(equipName == NULL)
			{
				return;
			}
			source = Json_getItem(source, equipName);
		}
		else
		{
			source = Json_getItemAt(source, 0);
		}
		if(source)
		{
			const char *pic = Json_getItemAt(source, 0)->valuestring;
			float scaleX = Json_getItemAt(source, 1)->valuefloat;
			float scaleY = Json_getItemAt(source, 2)->valuefloat;
			float leftOffset = Json_getItemAt(source, 3)->valuefloat;
			float topOffset = Json_getItemAt(source, 4)->valuefloat;

			tmpBone->setDisplayFrame(cache->spriteFrameByName(pic));
			CCRect rect = tmpBone->getTextureRect();
			float archX = (leftOffset + tmpBone->getLeftOffset()) / rect.size.width;
			float archY = (topOffset + tmpBone->getTopOffset()) / rect.size.height;
			tmpBone->setAnchorPoint(ccp(archX , 1- archY));
			tmpBone->setScaleX(scaleX);
			tmpBone->setScaleY(scaleX);
			tmpBone->setPosition(tmpBone->m_startPosition);
			tmpBone->setRotationX(tmpBone->m_fStartAngleX);
			tmpBone->setRotationY(tmpBone->m_fStartAngleY);
			tmpBone->setVisible(tmpBone->m_startVisable);
		}
		else
		{
			tmpBone->setDisplayFrame(tmpBone->m_pic);
			tmpBone->setAnchorPoint(tmpBone->m_startArch);
			tmpBone->setScaleX(tmpBone->m_fStartScaleX);
			tmpBone->setScaleY(tmpBone->m_fStartScaleY);
			tmpBone->setPosition(tmpBone->m_startPosition);
			tmpBone->setRotationX(tmpBone->m_fStartAngleX);
			tmpBone->setRotationY(tmpBone->m_fStartAngleY);
			tmpBone->setVisible(tmpBone->m_startVisable);
		}
		ccBlendFunc blend2 = {GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA};
		tmpBone->setShaderProgram(CCBone::getShader());
		tmpBone->setBlendFunc(blend2);
    }
}

void CCBoneSpriteLayer::changeBoneTexture(const char *textureName)
{
	if(isBatch)
	{
		return;
	}
	CCSpriteFrameCache *cache = CCSpriteFrameCache::sharedSpriteFrameCache();
	Json* root = CCBoneTextureManager::sharedManager()->getEquip(const_cast<char*>(textureName));
	if(root == NULL)
	{
		return;
	}
    if(m_bone != NULL && m_bone->count() > 0)
    {
        CCObject* child;
        CCARRAY_FOREACH(m_bone, child)
        {
            CCBone* tmpBone = (CCBone*) child;
			const char * tmp = tmpBone->getName();
			Json *source = Json_getItem(root, tmp);
			if(!source)
			{
				continue;
			}
			source = Json_getItemAt(source, 0);
			if(source)
			{
				const char *pic = Json_getItemAt(source, 0)->valuestring;
				float scaleX = Json_getItemAt(source, 1)->valuefloat;
				float scaleY = Json_getItemAt(source, 2)->valuefloat;
				float leftOffset = Json_getItemAt(source, 3)->valuefloat;
				float topOffset = Json_getItemAt(source, 4)->valuefloat;

				tmpBone->setDisplayFrame(cache->spriteFrameByName(pic));
				CCRect rect = tmpBone->getTextureRect();
				float archX = (leftOffset + tmpBone->getLeftOffset()) / rect.size.width;
				float archY = (topOffset + tmpBone->getTopOffset()) / rect.size.height;
				tmpBone->setAnchorPoint(ccp(archX , 1 - archY));
				tmpBone->setScaleX(scaleX);
				tmpBone->setScaleY(scaleX);
				tmpBone->setPosition(tmpBone->m_startPosition);
				tmpBone->setRotationX(tmpBone->m_fStartAngleX);
				tmpBone->setRotationY(tmpBone->m_fStartAngleY);
				tmpBone->setVisible(tmpBone->m_startVisable);
			}
			else
			{
				tmpBone->setDisplayFrame(tmpBone->m_pic);
				tmpBone->setAnchorPoint(tmpBone->m_startArch);
				tmpBone->setScaleX(tmpBone->m_fStartScaleX);
				tmpBone->setScaleY(tmpBone->m_fStartScaleY);
				tmpBone->setPosition(tmpBone->m_startPosition);
				tmpBone->setRotationX(tmpBone->m_fStartAngleX);
				tmpBone->setRotationY(tmpBone->m_fStartAngleY);
				tmpBone->setVisible(tmpBone->m_startVisable);
			}
			ccBlendFunc blend2 = {GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA};
			tmpBone->setShaderProgram(CCBone::getShader());
			tmpBone->setBlendFunc(blend2);
        }
    }
}

bool CCBoneSpriteLayer::init(const char *spriteName, bool isBatch)
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    CCSpriteFrameCache *cache = CCSpriteFrameCache::sharedSpriteFrameCache();
	Json *root = CCBoneTextureManager::sharedManager()->getSkl(const_cast<char*>(spriteName));
	int count = Json_getSize(root);
	m_bone = CCArray::create();
	m_effect = CCArray::create();
	CC_SAFE_RETAIN(m_bone);
	CC_SAFE_RETAIN(m_effect);

	CCSpriteBatchNode *batchNode = NULL;
	if(isBatch)
	{
		Json *source = Json_getItem(root, "picture");
		CCAssert(source != NULL, "source error");
		std::string pngPath = "pic/"+std::string(source->valuestring)+".png";
		batchNode = CCSpriteBatchNode::create(pngPath.c_str(), 40);
		batchNode->setAnchorPoint(ccp(0, 0));
		batchNode->setPosition(ccp(0, 0));
		this->addChild(batchNode, 0);
		this->isBatch = true;
	}

	for(int i = 0; i< count; i++)
	{
		Json *tmp = Json_getItemAt(root, i);
		std::string tmpString = tmp->name;
		if(tmpString == "picture" || tmpString == "effect")
		{
			continue;
		}
		const char *pic = Json_getItemAt(tmp, 0)->valuestring;
		int order = Json_getItemAt(tmp, 2)->valueint;
		float archX = Json_getItemAt(tmp, 3)->valuefloat;
		float archY = Json_getItemAt(tmp, 4)->valuefloat;
		float posX = Json_getItemAt(tmp, 5)->valuefloat;
		float posY = Json_getItemAt(tmp, 6)->valuefloat;
		float scaleX = Json_getItemAt(tmp, 7)->valuefloat;
		float scaleY = Json_getItemAt(tmp, 8)->valuefloat;
		float skewX = Json_getItemAt(tmp, 9)->valuefloat;
		float skewY = Json_getItemAt(tmp, 10)->valuefloat;
		int isShow = Json_getItemAt(tmp, 11)->valueint;
		float leftOffset = Json_getItemAt(tmp, 12)->valuefloat;
		float topOffset = Json_getItemAt(tmp, 13)->valuefloat;
		int endFrame = Json_getItemAt(tmp, 14)->valueint;
		float brightness = Json_getItemAt(tmp, 15)->valuefloat;

		CCBone *heads = CCBone::createWithSpriteFrame(cache->spriteFrameByName(pic), tmpString);
		heads->setAnchorPoint(ccp(archX, archY));
		heads->setStartArch(ccp(archX, archY));
		heads->setPosition(ccp(posX, posY));
		heads->setScaleX(scaleX);
		heads->setScaleY(scaleY);
		heads->setRotationX(skewX);
		heads->setRotationY(skewY);
		heads->setVisible((bool)isShow);
		heads->setOffset(topOffset, leftOffset);
		heads->setAlpha(1.0f);
		heads->endFrame = endFrame;

		heads->setStartStatus(false);
		if(this->isBatch)
		{
			batchNode->addChild(heads, order);
		}
		else
		{
			this->addChild(heads, order);
		}
		m_bone->addObject(heads);
	}
	this->ignoreAnchorPointForPosition(true);
	this->setAnchorPoint(ccp(0,0));
    return true;
}

CCLayerAction *CCBoneSpriteLayer::createAction(const char *BoneMove, CCFiniteTimeAction *layerMove, BoneMotion boneMotionType)
{
	CCLayerAction *tmp = CCLayerAction::create(BoneMove, layerMove, boneMotionType, this, interval);
	return tmp;
}

CCLayerAction *CCBoneSpriteLayer::createAction(const char *BoneMove, CCFiniteTimeAction *layerMove)
{
	CCLayerAction *tmp = CCLayerAction::create(BoneMove, layerMove, BoneMotionTypeSlow, this, interval);
	return tmp;
}

void CCBoneSpriteLayer::setAnimationInterval(double interval)
{
	if(interval > 0)
	{
		this->interval = interval;
	}
}

CCAction *CCBoneSpriteLayer::testLayerAction()
{
	int count = Json_getSize(m_label);
	CCArray *ar = CCArray::create();
	for(int i = 0; i< count; i++)
	{
		Json *tmp = Json_getItemAt(m_label, i);
		ar->addObject(createAction(tmp->name, NULL));
	}
	return CCSequence::create(ar);
}

CCArray* CCBoneSpriteLayer::allLabel()
{
	CCArray *ar = CCArray::create();
	int count = Json_getSize(m_label);
	for(int i = 0; i< count; i++)
	{
		Json *tmp = Json_getItemAt(m_label, i);
		ar->addObject(CCString::create(tmp->name));
	}
	return ar;
}
CCAction *CCBoneSpriteLayer::randomLayerAction()
{
	int count = Json_getSize(m_label);
	int index = rand() % count;
	Json *tmp = Json_getItemAt(m_label, index);
	return createAction(tmp->name, NULL);
}

CCAction *CCBoneSpriteLayer::indexLayerAction(int index)
{
	int count = Json_getSize(m_label);
	if(index >= count)
	{
		index = count - 1;
	}
	Json *tmp = Json_getItemAt(m_label, index);
	return createAction(tmp->name, NULL);
	return createAction(tmp->name, NULL);
}

CCAction *CCBoneSpriteLayer::runAction(CCAction* action, bool stopBefore)
{
	CCAssert( action != NULL, "Argument must be non-nil");
	if(stopBefore)
	{
		m_pActionManager->removeAllActionsFromTarget(this);
	}
    m_pActionManager->addAction(action, this, !m_bRunning);
    return action;
}
