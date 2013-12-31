#include "cocos2d.h"
#include "Function.h"
#include "CCBoneSpriteLayer.h"
#include "CCBoneActionManager.h"
#include "CCBoneTextureManager.h"
#include "CCBones.h"
#include "CCEffect.h"
#include "../../extensions/spine/Json.h"
USING_NS_CC;
using namespace cocos2d::extension;


CCBoneSpriteLayer::~CCBoneSpriteLayer(void)
{
	CC_SAFE_RELEASE(m_bone);
	CC_SAFE_RELEASE(m_effect);
}

CCBoneSpriteLayer *CCBoneSpriteLayer::create(const char *animationName, const char *defaultSkl)
{
	CCBoneSpriteLayer *pRet = new CCBoneSpriteLayer();
	if (pRet && pRet->init(animationName, defaultSkl, false))
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

CCBoneSpriteLayer *CCBoneSpriteLayer::createWithBatch(const char *animationName, char *defaultSkl)
{
	CCBoneSpriteLayer *pRet = new CCBoneSpriteLayer();
	if (pRet && pRet->init(animationName, defaultSkl, true))
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

const char *CCBoneSpriteLayer::getLabelNamebyFrame(int frame)
{
	int count = Json_getSize(m_label);
	for(int i = 0;i < count;i++)
	{
		Json *lb = Json_getItemAt(m_label, i);
		int start = Json_getItemAt(lb, 0)->valueint;
		int end = Json_getItemAt(lb, 1)->valueint;
		if(frame >= start && frame <= end)
		{
			return lb->name;
		}
	}
	return NULL;
}
CCBones *CCBoneSpriteLayer::getBoneByName(const char *name)
{
    if(m_bone != NULL && m_bone->count() > 0)
    {
        CCObject* child;
        CCARRAY_FOREACH(m_bone, child)
        {
            CCBones* pNode = (CCBones*) child;
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
	if(textureName == NULL || equipName == NULL || !strcmp(textureName,"0") || !strcmp(equipName,"0"))
	{
		CCLog("resetBoneTexture parame error %s %s", textureName, equipName);
		return ;
	}
	Json* root = CCBoneTextureManager::sharedManager()->getEquip(const_cast<char*>(textureName));
	if(root == NULL)
	{
		return;
	}
	Json *source = Json_getItem(root, equipName);
	int type = Json_getItem(source, "type")->valueint;
	source = Json_getItem(source, "part");
	if(!source)
	{
		return;
	}
	if(m_bone != NULL && m_bone->count() > 0)
    {
        CCObject* child;
        CCARRAY_FOREACH(m_bone, child)
        {
            CCBones* tmpBone = (CCBones*) child;
			Json *info = Json_getItem(source, tmpBone->getName());
			if(info == NULL)
			{
				continue;
			}
			CC_SAFE_DELETE(tmpBone->m_weightList[type]);
			tmpBone->m_weightList[type] = NULL;
			tmpBone->removeFromParentAndCleanup(false);

			if(tmpBone->m_weightList[0])
			{
				CCSpriteFrameCache *cache = CCSpriteFrameCache::sharedSpriteFrameCache();
				tmpBone->setDisplayFrame(cache->spriteFrameByName(tmpBone->m_weightList[0]->pic));
				CCRect rect = tmpBone->getTextureRect();
				float archX = (tmpBone->m_weightList[0]->leftOffset + tmpBone->getLeftOffset()) / rect.size.width;
				float archY = (tmpBone->m_weightList[0]->topOffset + tmpBone->getTopOffset()) / rect.size.height;
				tmpBone->setAnchorPoint(ccp(archX , 1- archY));
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
	if(textureName == NULL || equipName == NULL || !strcmp(textureName,"0") || !strcmp(equipName,"0"))
	{
		CCLog("resetBoneTexture parame error %s %s", textureName, equipName);
		return ;
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
	int isFull = Json_getItem(root, "full")->valueint;
	int type = Json_getItem(source, "type")->valueint;
	int prevent = Json_getItem(source, "prevent")->valueint;
	source = Json_getItem(source, "part");
	int *boneOrderList = CCBoneSpriteConfig::getBoneOrder();
	int boneOrderLen = CCBoneSpriteConfig::getBoneOrderLen();
	if(m_bone != NULL && m_bone->count() > 0)
    {
        CCObject* child;
        CCARRAY_FOREACH(m_bone, child)
        {
            CCBones* tmpBone = (CCBones*) child;
			Json *info = Json_getItem(source, tmpBone->getName());
			if(info == NULL)
			{
				continue;
			}
			tmpBone->removeFromParentAndCleanup(false);
			int fCount = Json_getSize(info);
			int shareBone = Json_getItemAt(info, 0)->valueint;

			CCBonePicWeight *tp = NULL;
			if(fCount > 1)
			{
				const char *pic = Json_getItemAt(info, 1)->valuestring;
				float leftOffset = Json_getItemAt(info, 2)->valuefloat;
				float topOffset = Json_getItemAt(info, 3)->valuefloat;
				tp = new CCBonePicWeight();
				tp->pic = pic;
				tp->topOffset = topOffset;
				tp->leftOffset = leftOffset;
				tp->isFull = isFull;
				tp->prevent = prevent;
			}
			CC_SAFE_DELETE(tmpBone->m_weightList[type]);
			tmpBone->m_weightList[type] = tp;
			tmpBone->m_preventList[type] = prevent; 
			bool found = false;
			for(int i = 0; i <boneOrderLen;i++)
			{
				int order = boneOrderList[i];
				if(tmpBone->m_weightList[order])
				{
					if(!shareBone && order != type)
					{
						continue;
					}
					if(tmpBone->m_weightList[order]->isFull)
					{
						tmpBone->setDisplayFrame(cache->spriteFrameByName(tmpBone->m_weightList[order]->pic));
					}
					else
					{
						std::string tt = CCBoneSpriteConfig::getEquipUrl()+std::string(tmpBone->m_weightList[order]->pic);
						CCTexture2D * texture = CCTextureCache::sharedTextureCache()->addImage(tt.c_str());
						tmpBone->changeTexture(texture);
					}
					CCRect rect = tmpBone->getTextureRect();
					float archX = (tmpBone->m_weightList[order]->leftOffset + tmpBone->getLeftOffset()) / rect.size.width;
					float archY = (tmpBone->m_weightList[order]->topOffset + tmpBone->getTopOffset()) / rect.size.height;
					tmpBone->setAnchorPoint(ccp(archX , 1- archY));
					this->addChild(tmpBone, tmpBone->m_startZOrder);
					found = true;
					break;
				}
				else
				{
					if(tmpBone->m_preventList[order])
					{
						found = true;
						break;
					}
				}
			}

			if(tmpBone->m_weightList[0] && !found)
			{
				tmpBone->setDisplayFrame(cache->spriteFrameByName(tmpBone->m_weightList[0]->pic));
				CCRect rect = tmpBone->getTextureRect();
				float archX = (tmpBone->m_weightList[0]->leftOffset + tmpBone->getLeftOffset()) / rect.size.width;
				float archY = (tmpBone->m_weightList[0]->topOffset + tmpBone->getTopOffset()) / rect.size.height;
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
	CCBoneActionData *animation = CCBoneActionManager::sharedManager()->getAnimation(animationName);
	if(!animation)
	{
		return false;
	}

	Json *root = animation->skl;
	int count = Json_getSize(root);
	m_bone = CCArray::create();
	m_effect = CCArray::create();
	CC_SAFE_RETAIN(m_bone);
	CC_SAFE_RETAIN(m_effect);

	CCSpriteBatchNode *batchNode = NULL;
	Json* skl = NULL;
	int type = 0;
	int prevent = 1;
	bool haveSkl = false;
	if(defaultSkl)
	{
		skl = CCBoneTextureManager::sharedManager()->getEquip(const_cast<char*>(defaultSkl));
		if(skl)
		{
			skl = Json_getItem(skl, defaultSkl);
			type = Json_getItem(skl, "type")->valueint;
			prevent = Json_getItem(skl, "prevent")->valueint;
			skl = Json_getItem(skl, "part");

			
			if(skl)
			{
				haveSkl = true;
			}
		}
		else
		{
			return false;
		}
	}
	if(isBatch && haveSkl)
	{
		std::string pngPath = CCBoneSpriteConfig::getEquipUrl() +std::string(defaultSkl)+".png";
		CCTexture2D::setDefaultAlphaPixelFormat(kCCTexture2DPixelFormat_RGBA4444);
		batchNode = CCSpriteBatchNode::create(pngPath.c_str(), 40);
		CCTexture2D::setDefaultAlphaPixelFormat(kCCTexture2DPixelFormat_RGBA8888);
		batchNode->setAnchorPoint(ccp(0, 0));
		batchNode->setPosition(ccp(0, 0));
		this->addChild(batchNode, 0);
		this->isBatch = true;
	}

	this->m_label = animation->label;
	int haveMask = 0;
	if(animation->effect)
	{
		isEffect = true;
		char_frame *motion = animation->effectMotion;
		char_effect *info = animation->effect;
		Json *effectOrder = animation->effectOrder;
		haveMask = animation->mask;
		char_frame::iterator iter;
		for(iter = motion->begin(); iter != motion->end();)
		{
			const char* name = iter->first->getCString();
			Json * tt = Json_getItem(effectOrder, name);
			std::string layerT = Json_getItemAt(tt, 0)->valuestring;
			int od = Json_getItemAt(tt, 1)->valueint;
			if(layerT == "mask")
			{
				m_clip = CCBoneClip::create();
				m_clip->setAnchorPoint(ccp(0,0));
				m_clip->m_boneData = motion->find(CCString::create(name))->second;
				m_clip->m_effectInfo = info;
				this->addChild(m_clip, od);
			}
			else
			{
				CCEffect *effect = CCEffect::create(name);
				effect->m_boneData = motion->find(CCString::create(name))->second;
				effect->m_effectInfo = info;
				effect->setStartStatus(false);
				effect->setVisible(false);
				this->addChild(effect, od);
				m_effect->addObject(effect);
			}
			iter++;
		}
		if(m_clip)
		{
			m_clip->setFrame(0);
		}
		CCEffect::setFrame(m_effect, 0, 0, true);
	}

	for(int i = 0; i< count; i++)
	{
		Json *tmp = Json_getItemAt(root, i);
		std::string tmpString = tmp->name;
		if(tmpString == "picture" || tmpString == "effect")
		{
			continue;
		}
		std::string layerType = Json_getItemAt(tmp, 0)->valuestring;
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
		Json *color = Json_getItemAt(tmp, 12);

		bool havePic = false;
		CCBones *heads = NULL;
		if(haveSkl)
		{
			Json *info = Json_getItem(skl, tmpString.c_str());
			if(info)
			{
				int fCount = Json_getSize(info);
				if(fCount > 1)
				{
					const char *pic = Json_getItemAt(info, 1)->valuestring;
					float picLeftOffset = Json_getItemAt(info, 2)->valuefloat;
					float picTopOffset = Json_getItemAt(info, 3)->valuefloat;

					heads = CCBones::createWithSpriteFrame(cache->spriteFrameByName(pic), tmpString);

					CCRect rect = heads->getTextureRect();
					float archX = (picLeftOffset + leftOffset) / rect.size.width;
					float archY = (picTopOffset + topOffset) / rect.size.height;
					heads->setAnchorPoint(ccp(archX , 1- archY));
					havePic = true;

					CCBonePicWeight *tp = new CCBonePicWeight();
					tp->pic = pic;
					tp->topOffset = picTopOffset;
					tp->leftOffset = picLeftOffset;
					tp->isFull = 1;
					tp->prevent = prevent;
					heads->m_weightList[type] = tp;
				}
			}
		}
		if(!havePic)
		{
			heads = CCBones::create(tmpString);
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
		heads->setRedPercent(Json_getItemAt(color, 0)->valuefloat);
		heads->setGreenPercent(Json_getItemAt(color, 1)->valuefloat);
		heads->setBluePercent(Json_getItemAt(color, 2)->valuefloat);
		if(havePic)
		{
			if(this->isBatch)
			{
				batchNode->addChild(heads, order);
			}
			else
			{
				if(haveMask && layerType == "masked")
				{
					heads->m_masked = true;
					m_clip->addChild(heads, order);
				}
				else
				{
					this->addChild(heads, order);
				}
				
				//CCRenderTexture* tex = createStroke(heads, 2, ccc3(0, 255, 0), 50);
				//this->addChild(tex, heads->getZOrder() - 1);
			}
		}
		heads->m_boneData = animation->frame->find(CCString::create(heads->getName()))->second;
		heads->m_preventList[type] = prevent; 
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
	struct cc_timeval now; 
	CCTime::gettimeofdayCocos2d(&now, NULL); 
	CCLog("%d,%d", now.tv_sec, now.tv_usec);
	CCRenderTexture* rt = CCRenderTexture::create(label->getTexture()->getContentSize().width + size * 2,
                                                    label->getTexture()->getContentSize().height+size * 2);
    CCPoint originalPos = label->getPosition();
    ccColor3B originalColor = label->getColor();
    GLubyte originalOpacity = label->getOpacity();
    label->setColor(color);
    label->setOpacity(opacity);
    bool originalVisibility = label->isVisible();
    ccBlendFunc originalBlend = label->getBlendFunc();
    ccBlendFunc bf = {GL_SRC_ALPHA, GL_ONE};
    label->setBlendFunc(bf);
    CCPoint bottomLeft = ccp(
                                label->getTexture()->getContentSize().width * label->getAnchorPoint().x + size,
                                label->getTexture()->getContentSize().height * label->getAnchorPoint().y + size);
    CCPoint positionOffset = CCPointZero;
	positionOffset.x = (label->getAnchorPoint().x - 0.5)*label->getTexture()->getContentSize().width;
	positionOffset.y = (label->getAnchorPoint().y - 0.5)*label->getTexture()->getContentSize().height;
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
    rt->setPosition(position);
    rt->getSprite()->getTexture()->setAntiAliasTexParameters();
	CCTime::gettimeofdayCocos2d(&now, NULL); 
	CCLog("%d,%d", now.tv_sec, now.tv_usec);
	CCLog("++++++++++++++++++++++++");
    return rt;
}

CCSize CCBoneSpriteLayer::getLayerSize()
{
	CCObject* child = NULL;
	float minY = 66666666.0f;
	float maxY = -8888888;
	float minX = 88888888;
	float maxX = -8888888;
	CCARRAY_FOREACH(m_bone, child)
	{
		CCBones *ch = (CCBones *)child;
		CCRect rect = ch->boundingBox();
		if(rect.getMinY() < minY)
		{
			minY = rect.getMinY();
		}
		if(rect.getMinX() < minX)
		{
			minX = rect.getMinX();
		}
		if(rect.getMaxY() > maxY)
		{
			maxY = rect.getMaxY();
		}
		if(rect.getMaxX() > maxX)
		{
			maxX = rect.getMaxX();
		}
		ch->getContentSize();
	}

	return CCSizeMake(maxX - minX, maxY);
}
void CCBoneSpriteLayer::setBoneAction(const char *name)
{
	int count = 0;
	int start, end;

	bool hasLabel = getLabel(name, start, end);
	if(hasLabel)
	{
		CCBones::setFrame(m_bone, start, 0);
		if(m_clip)
		{
			m_clip->setFrame(start);
		}
		if(haveEffect())
		{
			CCEffect::setFrame(m_effect, start, 0, false);
		}
		frameIndex = start;
	}
	else
	{
		CCLog("no label %s", name);
	}
}

const char *CCBoneSpriteLayer::getBoneAction()
{
	const char *name = getLabelNamebyFrame(frameIndex);
	if(!name)
	{
		CCLog("frameindex %d no label", frameIndex);
		return "";
	}
	else
	{
		return name;
	}
}
