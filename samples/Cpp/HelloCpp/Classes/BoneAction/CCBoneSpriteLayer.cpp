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

CCBoneSpriteLayer *CCBoneSpriteLayer::create(const char *animationName, const char *defaultSkl)
{
	CCBoneSpriteLayer *pRet = new CCBoneSpriteLayer();
	if (pRet && pRet->init(animationName, defaultSkl, false))
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

CCBoneSpriteLayer *CCBoneSpriteLayer::createWithBatch(const char *animationName, char *defaultSkl)
{
	CCBoneSpriteLayer *pRet = new CCBoneSpriteLayer();
	if (pRet && pRet->init(animationName, defaultSkl, true))
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

void CCBoneSpriteLayer::setAnimation(const char *name)
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

void CCBoneSpriteLayer::resetBoneTexture(const char *textureName, const char *equipName)
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
	Json *source = Json_getItem(root, equipName);
	if(!source)
	{
		return;
	}
	if(m_bone != NULL && m_bone->count() > 0)
    {
        CCObject* child;
        CCARRAY_FOREACH(m_bone, child)
        {
            CCBone* tmpBone = (CCBone*) child;
			Json *info = Json_getItem(source, tmpBone->getName());
			if(info == NULL)
			{
				continue;
			}
			tmpBone->removeFromParentAndCleanup(false);
			if(tmpBone->m_pic != NULL)
			{
				tmpBone->setDisplayFrame(tmpBone->m_pic);
				tmpBone->setAnchorPoint(tmpBone->m_startArch);
				this->addChild(tmpBone, tmpBone->m_startZOrder);
			}
		}
	}
}

void CCBoneSpriteLayer::changeBoneTexture(const char *textureName, const char *equipName)
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
	Json *source = Json_getItem(root, equipName);
	if(!source)
	{
		return;
	}
	bool isFull = (bool)Json_getItem(root, "full")->valueint;
	int type = Json_getItem(source, "type")->valueint;
	source = Json_getItem(source, "part");
	if(m_bone != NULL && m_bone->count() > 0)
    {
        CCObject* child;
        CCARRAY_FOREACH(m_bone, child)
        {
            CCBone* tmpBone = (CCBone*) child;
			Json *info = Json_getItem(source, tmpBone->getName());
			if(info == NULL)
			{
				continue;
			}
			
			tmpBone->removeFromParentAndCleanup(false);
			int fCount = Json_getSize(info);
			if(fCount <= 0)
			{
				if(tmpBone->m_pic != NULL)
				{
					tmpBone->setDisplayFrame(tmpBone->m_pic);
					tmpBone->setAnchorPoint(tmpBone->m_startArch);
					this->addChild(tmpBone, tmpBone->m_startZOrder);
				}
			}
			else
			{
				const char *pic = Json_getItemAt(info, 0)->valuestring;
				float leftOffset = Json_getItemAt(info, 1)->valuefloat;
				float topOffset = Json_getItemAt(info, 2)->valuefloat;

				if(fCount == 4)
				{
					int weight = Json_getItemAt(info, 3)->valueint;
					if(tmpBone->m_picNowWeight && tmpBone->m_picLowWeight)
					{
						if(tmpBone->m_picNowWeight->type != type && tmpBone->m_picLowWeight->type != type)
						{
							continue;
						}
					}
					CCBonePicWeight *weightInfo = new CCBonePicWeight();
					weightInfo->pic = pic;
					weightInfo->topOffset = topOffset;
					weightInfo->leftOffset = leftOffset;
					weightInfo->weight = weight;
					weightInfo->isFull = isFull;
					weightInfo->type = type;
					if(tmpBone->m_picNowWeight)
					{
						if(type != tmpBone->m_picNowWeight->type && weight < tmpBone->m_picNowWeight->weight)
						{
							CC_SAFE_DELETE(tmpBone->m_picLowWeight);
							tmpBone->m_picLowWeight = weightInfo;
							continue;
						}
					}
					if(!tmpBone->m_picNowWeight)
					{
						tmpBone->m_picNowWeight = weightInfo;
					}
					else
					{
						if(type == tmpBone->m_picNowWeight->type)
						{
							CC_SAFE_DELETE(tmpBone->m_picNowWeight);
							tmpBone->m_picNowWeight = weightInfo;
						}
						else
						{
							tmpBone->m_picLowWeight = tmpBone->m_picNowWeight;
							tmpBone->m_picNowWeight = weightInfo;
						}
					}
				}


				if(isFull)
				{
					tmpBone->setDisplayFrame(cache->spriteFrameByName(pic));
				}
				else
				{
					std::string tt = CCBoneSpriteConfig::getEquipUrl()+std::string(pic);
					CCTexture2D * texture = CCTextureCache::sharedTextureCache()->addImage(tt.c_str());
					tmpBone->changeTexture(texture);
				}
				CCRect rect = tmpBone->getTextureRect();
				float archX = (leftOffset + tmpBone->getLeftOffset()) / rect.size.width;
				float archY = (topOffset + tmpBone->getTopOffset()) / rect.size.height;
				tmpBone->setAnchorPoint(ccp(archX , 1- archY));
				this->addChild(tmpBone, tmpBone->m_startZOrder);
			}
			
		}
	}
}

bool CCBoneSpriteLayer::init(const char *animationName, const char *defaultSkl, bool isBatch)
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    CCSpriteFrameCache *cache = CCSpriteFrameCache::sharedSpriteFrameCache();
	Json *animation = CCBoneActionManager::sharedManager()->getAnimation(animationName);
	Json *root = Json_getItem(animation, "skl");
	int count = Json_getSize(root);
	m_bone = CCArray::create();
	m_effect = CCArray::create();
	CC_SAFE_RETAIN(m_bone);
	CC_SAFE_RETAIN(m_effect);

	CCSpriteBatchNode *batchNode = NULL;
	Json* skl = NULL;
	bool haveSkl = false;
	if(defaultSkl)
	{
		skl = CCBoneTextureManager::sharedManager()->getEquip(const_cast<char*>(defaultSkl));
		if(skl)
		{
			skl = Json_getItem(skl, defaultSkl);
			skl = Json_getItem(skl, "part");
			if(skl)
			{
				haveSkl = true;
			}
		}
	}
	if(isBatch && haveSkl)
	{
		std::string pngPath = CCBoneSpriteConfig::getEquipUrl() +std::string(defaultSkl)+".png";
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
		int order = Json_getItemAt(tmp, 1)->valueint;;
		float posX = Json_getItemAt(tmp, 2)->valuefloat;
		float posY = Json_getItemAt(tmp, 3)->valuefloat;
		float scaleX = Json_getItemAt(tmp, 4)->valuefloat;
		float scaleY = Json_getItemAt(tmp, 5)->valuefloat;
		float skewX = Json_getItemAt(tmp, 6)->valuefloat;
		float skewY = Json_getItemAt(tmp, 7)->valuefloat;
		int isShow = Json_getItemAt(tmp, 8)->valueint;
		float leftOffset = Json_getItemAt(tmp, 9)->valuefloat;
		float topOffset = Json_getItemAt(tmp, 10)->valuefloat;
		int endFrame = Json_getItemAt(tmp, 11)->valueint;
		float brightness = Json_getItemAt(tmp, 12)->valuefloat;

		bool havePic = false;
		CCBone *heads = NULL;
		if(haveSkl)
		{
			Json *info = Json_getItem(skl, tmpString.c_str());
			if(info)
			{
				int fCount = Json_getSize(info);
				if(fCount > 0)
				{
					const char *pic = Json_getItemAt(info, 0)->valuestring;
					float picLeftOffset = Json_getItemAt(info, 1)->valuefloat;
					float picTopOffset = Json_getItemAt(info, 2)->valuefloat;

					heads = CCBone::createWithSpriteFrame(cache->spriteFrameByName(pic), tmpString);

					CCRect rect = heads->getTextureRect();
					float archX = (picLeftOffset + leftOffset) / rect.size.width;
					float archY = (picTopOffset + topOffset) / rect.size.height;
					heads->setAnchorPoint(ccp(archX , 1- archY));
					heads->setStartArch(ccp(archX , 1- archY));
					havePic = true;
				}
			}
		}
		if(!havePic)
		{
			heads = CCBone::create(tmpString);
		}
		heads->setPosition(ccp(posX, posY));
		heads->setScaleX(scaleX);
		heads->setScaleY(scaleY);
		heads->setRotationX(skewX);
		heads->setRotationY(skewY);
		heads->setVisible((bool)isShow);
		heads->setOffset(topOffset, leftOffset);
		heads->setAlpha(1.0f);
		heads->endFrame = endFrame;
		heads->m_startZOrder = order;
		heads->setStartStatus(false);
		if(havePic)
		{
			if(this->isBatch)
			{
				batchNode->addChild(heads, order);
			}
			else
			{
				this->addChild(heads, order);
				//CCRenderTexture* tex = createStroke(heads, 2, ccc3(0, 255, 0), 50);
				//this->addChild(tex, heads->getZOrder() - 1);
			}
		}
		m_bone->addObject(heads);
	}
	this->ignoreAnchorPointForPosition(true);
	this->setAnchorPoint(ccp(0,0));
    return true;
}

CCLayerAction *CCBoneSpriteLayer::createAction(const char *BoneMove, float time)
{
	CCLayerAction *tmp = CCLayerAction::create(BoneMove, this, interval, time);
	return tmp;
}

CCLayerAction *CCBoneSpriteLayer::createAction(const char *BoneMove)
{
	CCLayerAction *tmp = CCLayerAction::create(BoneMove, this, interval);
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


CCRenderTexture* CCBoneSpriteLayer::createStroke(CCSprite* label, int size, ccColor3B color, GLubyte opacity)
{
    CCRenderTexture* rt = CCRenderTexture::create(
        label->getTexture()->getContentSize().width + size * 2,
        label->getTexture()->getContentSize().height+size * 2
        );

    CCPoint originalPos = label->getPosition();
    ccColor3B originalColor = label->getColor();
    GLubyte originalOpacity = label->getOpacity();
    bool originalVisibility = label->isVisible();
    label->setColor(color);
    label->setOpacity(opacity);
    label->setVisible(true);
    ccBlendFunc originalBlend = label->getBlendFunc();
    ccBlendFunc bf = {GL_SRC_ALPHA, GL_ONE};
    label->setBlendFunc(bf);
    CCPoint bottomLeft = ccp(
        label->getTexture()->getContentSize().width * label->getAnchorPoint().x + size, 
        label->getTexture()->getContentSize().height * label->getAnchorPoint().y + size);
    CCPoint positionOffset= ccp(
        - label->getTexture()->getContentSize().width / 2,
        - label->getTexture()->getContentSize().height / 2);
    CCPoint position = ccpSub(originalPos, positionOffset);
    rt->begin();
    for (int i=0; i<360; i+= 15) // you should optimize that for your needs
    {
        label->setPosition(
            ccp(bottomLeft.x + sin(CC_DEGREES_TO_RADIANS(i))*size, bottomLeft.y + cos(CC_DEGREES_TO_RADIANS(i))*size)
            );
        label->visit();
    }
    rt->end();

    label->setPosition(originalPos);
    label->setColor(originalColor);
    label->setBlendFunc(originalBlend);
	label->setVisible(originalVisibility);
    label->setOpacity(originalOpacity);
    rt->setPosition(ccp(0,0));
	//rt->setAnchorPoint(label->getAnchorPoint());
    return rt;
}
