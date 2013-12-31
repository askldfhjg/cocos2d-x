#include "cocos2d.h"
#include "CCEffect.h"
#include "Function.h"

USING_NS_CC;

CCEffect *CCEffect::create(const char *name)
{
	CCEffect *pobSprite = new CCEffect();
    if (pobSprite && pobSprite->init())
    {
        pobSprite->autorelease();
		pobSprite->name = std::string(name);

		pobSprite->setShaderProgram(CCBones::getShader());
        return pobSprite;
    }
    CC_SAFE_DELETE(pobSprite);
    return NULL;
}

CCEffect::~CCEffect(void)
{
	
}

bool CCEffect::setAnimatime(const char *name, bool show, int index, bool done)
{
	if(!show || !name)
	{
		m_frameIndex = -1;
		m_lastFrame = -1;
		return false;
	}
	if(m_lastFrame != index)
	{
		m_lastFrame = index;
		m_frameIndex++;
	}
	if(m_lastFrame == index && index == 0)
	{
		m_frameIndex = 0;
	}
	char_effect::iterator it = m_effectInfo->find(CCString::create(name));
	if(it == m_effectInfo->end())
	{
		setVisible(false);
		return false;
	}
	float archX = it->second->archX;
	float archY = it->second->archY;
	setAnchorPoint(ccp(archX , archY));

	//ÔÚeffectÖÐÅÅ³ýtypeºÍinfo
	if(m_frameIndex >= it->second->info->size())
	{
		m_frameIndex = 0;
	}
	
	CCBoneJson *source = it->second->info->find(m_frameIndex)->second;
	const char *pic = source->pic;
	float scaleX = source->scaleX;
	float scaleY = source->scaleY;
	float positionX = source->posX;
	float positionY = source->posY;
	if(strlen(pic) <= 0)
	{
		setVisible(false);
		return true;
	}
	setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(pic));
	CCPoint anch = getAnchorPoint();
	setPositionX(getPositionX() + positionX * getScaleX() + (anch.x - 0.5) * getTextureRect().size.width);
	setPositionY(-(getPositionY() + positionY * getScaleY()) + (anch.y - 0.5) * getTextureRect().size.height);
	setScaleX(getScaleX() * scaleX);
	setScaleY(getScaleY() * scaleY);
	if(done)
	{
		m_frameIndex = it->second->info->size();
	}
	return true;
}

bool CCEffect::getAdd()
{
	return m_add;
}
void CCEffect::setAdd(bool add)
{
	m_add = add;
}

void CCEffect::setFrame(CCArray *effectArray, int frameInAll, int frameInAction, bool done)
{
	CCObject* child = NULL;
	CCARRAY_FOREACH(effectArray, child)
	{
		CCEffect *ch = (CCEffect *)child;
		int_json::iterator it = ch->m_boneData->find(frameInAll);
		bool found = false;
		if (it != ch->m_boneData->end())
		{
			found = true;
		}
		if(found || ch->m_lastData)
		{
			CCBoneJson *dd;
			if(found)
			{
				dd = it->second;
			}
			else
			{
				dd = ch->m_lastData;
			}
			float posX = dd->posX;
			float posY = dd->posY;
			float scaleX = dd->scaleX;
			float scaleY = dd->scaleY;
			float skewX = dd->skewX;
			float skewY = dd->skewY;
			float visable = dd->visable;
			ch->setRedPercent(dd->colorRed);
			ch->setGreenPercent(dd->colorGreen);
			ch->setBluePercent(dd->colorBlue);
			const char *pic = dd->pic;
			ch->setPosition(ccp(ch->m_startPosition.x + posX, ch->m_startPosition.y + posY));
			ch->setRotationX(ch->m_fStartAngleX + skewX);
			ch->setRotationY(ch->m_fStartAngleY + skewY);
			ch->setScaleX(ch->m_fStartScaleX * scaleX);
			ch->setScaleY(ch->m_fStartScaleY * scaleY);
			ch->m_lastData = dd;
			if(done)
			{
				ch->m_lastData = NULL;
			}
			bool vis = ch->isVisible();
			bool boolVisable = (bool)(int)visable;

			float alf = ch->getAlpha();
			if(vis != boolVisable || alf != visable)
			{ 
				if(boolVisable)
				{
					ch->setVisible(true);
					ch->setAlpha(1.0f);
				}
				else if(visable <= 0)
				{
					ch->setVisible(false);           
					ch->setAlpha(0);
				}
				else
				{
					ch->setVisible(true);
					ch->setAlpha(visable);
				}
			}
			ch->setAnimatime(pic, ch->isVisible(), frameInAll, done);
		}
		else
		{
			if(frameInAction == 0)
			{
				ch->setVisible(false);
			}
		}
		
	}
}

CCBoneClip *CCBoneClip::create()
{
	CCBoneClip *pRet = new CCBoneClip();
    if (pRet && pRet->init())
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    
    return pRet;
}

CCBoneClip::~CCBoneClip()
{

}

void CCBoneClip::onEnter()
{
    CCNode::onEnter();
	if(m_pStencil)
	{
		m_pStencil->onEnter();
	}
}

void CCBoneClip::onEnterTransitionDidFinish()
{
    CCNode::onEnterTransitionDidFinish();
	if(m_pStencil)
	{
		m_pStencil->onEnterTransitionDidFinish();
	}
    
}

void CCBoneClip::onExitTransitionDidStart()
{
    if(m_pStencil)
	{
		m_pStencil->onExitTransitionDidStart();
	}
	CCNode::onExitTransitionDidStart();
}

void CCBoneClip::onExit()
{
	if(m_pStencil)
	{
		m_pStencil->onExit();
	}
    CCNode::onExit();
}

void CCBoneClip::visit()
{
	if(!getStencil() || !m_visable)
	{
		CCNode::visit();
	}
	else
	{
		CCClippingNode::visit();
	}
}

void CCBoneClip::setBoneStencil(const char *name, float posX, float posY, bool visable)
{
	if(!getStencil() && name)
	{
		char_effect::iterator it = m_effectInfo->find(CCString::create(name));
		if(it == m_effectInfo->end())
		{
			return;
		}
		float archX = it->second->archX;
		float archY = it->second->archY;
		int width = it->second->width;
		int height = it->second->height;
		float poX = it->second->posX;
		float poY = it->second->posY;
		setContentSize(CCSizeMake(width, height));
		m_offsetX = poX-archX*width;
		m_offsetY = poY-archY*height;
		setPosition(ccp(m_offsetX, m_offsetY));

		CCDrawNode *stencil = CCDrawNode::create();
		CCPoint rectangle[4];
		rectangle[0] = ccp(0, 0);
		rectangle[1] = ccp(width, 0);
		rectangle[2] = ccp(width, height);
		rectangle[3] = ccp(0, height);
		ccColor4F white = {1, 1, 1, 1};
		stencil->drawPolygon(rectangle, 4, white, 1, white);
		setStencil(stencil);
	}
	m_visable = visable;
}

void CCBoneClip::setFrame(int frame)
{
	int_json::iterator it = m_boneData->find(frame);
	if (it != m_boneData->end())
	{
		float posX = it->second->posX;
		float posY = it->second->posY;
		int visable = it->second->visable;
		const char *pic = it->second->pic;
		this->setBoneStencil(pic, posX, posY, visable);
	}
}
