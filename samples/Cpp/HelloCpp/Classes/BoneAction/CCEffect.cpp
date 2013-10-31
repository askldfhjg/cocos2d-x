#include "cocos2d.h"
#include "CCEffect.h"
#include "Function.h"

USING_NS_CC;

CCEffect *CCEffect::create(std::string &name)
{
	CCEffect *pobSprite = new CCEffect();
    if (pobSprite && pobSprite->init())
    {
        pobSprite->autorelease();
		pobSprite->name = name;
		pobSprite->m_pic = NULL;

		pobSprite->setShaderProgram(CCBone::getShader());
        return pobSprite;
    }
    CC_SAFE_DELETE(pobSprite);
    return NULL;
}

CCEffect::~CCEffect(void)
{
	
}

bool CCEffect::setAnimatime(std::string name, bool show, int index)
{
	if(!show || name.length() <= 0)
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
	Json *animation = Json_getItem(m_effectInfo, name.c_str());
	if(animation == NULL)
	{
		setVisible(false);
		return false;
	}
	Json *arch = Json_getItem(animation, "info");
	float archX = Json_getItemAt(arch, 0)->valuefloat;
	float archY = Json_getItemAt(arch, 1)->valuefloat;
	setAnchorPoint(ccp(archX , archY));
	int count = Json_getSize(animation);
	//ÔÚeffectÖÐÅÅ³ýtypeºÍinfo
	if(m_frameIndex + 2 >= count)
	{
		m_frameIndex = 0;
	}

	char str[256]={0};
	Func::itostr(m_frameIndex, str);
	Json *source = Json_getItem(animation, str);
	const char *pic = Json_getItemAt(source, 0)->valuestring;
	float scaleX = Json_getItemAt(source, 1)->valuefloat;
	float scaleY = Json_getItemAt(source, 2)->valuefloat;
	float positionX = Json_getItemAt(source, 3)->valuefloat;
	float positionY = Json_getItemAt(source, 4)->valuefloat;

	setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(pic));
	CCPoint anch = getAnchorPoint();
	setPositionX(getPositionX() + positionX * getScaleX() + (anch.x - 0.5) * getTextureRect().size.width);
	setPositionY(-(getPositionY() + positionY * getScaleY()) + (anch.y - 0.5) * getTextureRect().size.height);
	setScaleX(getScaleX() * scaleX);
	setScaleY(getScaleY() * scaleY);
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

void CCEffect::setFrame(CCArray *effectArray, int frameInAll, int frameInAction)
{
	CCObject* child = NULL;
	char str[256]={0};
	Func::itostr(frameInAll, str);
	CCARRAY_FOREACH(effectArray, child)
	{
		CCEffect *ch = (CCEffect *)child;
		Json *source = Json_getItem(ch->m_frame, str);
		if (source)
		{
			int c = Json_getSize(source);
			if(c <= 0)
			{
				continue;
			}
			CCAssert(c == 9, "count error");
			float posX = Json_getItemAt(source, 0)->valuefloat;
			float posY = Json_getItemAt(source, 1)->valuefloat;
			float scaleX = Json_getItemAt(source, 2)->valuefloat;
			float scaleY = Json_getItemAt(source, 3)->valuefloat;
			float skewX = Json_getItemAt(source, 4)->valuefloat;
			float skewY = Json_getItemAt(source, 5)->valuefloat;
			float visable = Json_getItemAt(source, 6)->valuefloat;
			float brightness = Json_getItemAt(source, 7)->valuefloat;
			const char *pic = Json_getItemAt(source, 8)->valuestring;

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
					ch->setVisible(false);
					ch->setAlpha(0);
				}
				else
				{
					ch->setVisible(true);
					ch->setAlpha(visable);
				}
			}
			ch->setAnimatime(std::string(pic), ch->isVisible(), frameInAll);
				
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

void CCBoneClip::setBoneStencil(std::string name, float posX, float posY, bool visable)
{
	if(!getStencil())
	{
		Json *animation = Json_getItem(m_effectInfo, name.c_str());
		if(animation == NULL)
		{
			return;
		}
		Json *arch = Json_getItem(animation, "info");
		float archX = Json_getItemAt(arch, 0)->valuefloat;
		float archY = Json_getItemAt(arch, 1)->valuefloat;
		int width = Json_getItemAt(arch, 2)->valueint;
		int height = Json_getItemAt(arch, 3)->valueint;
		float poX = Json_getItemAt(arch, 4)->valuefloat;
		float poY = Json_getItemAt(arch, 5)->valuefloat;
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
	char str[256]={0};
	Func::itostr(frame, str);
	Json *source = Json_getItem(this->m_frame, str);
	if (source)
	{
		int c = Json_getSize(source);
		CCAssert(c == 9, "count error");
		float posX = Json_getItemAt(source, 0)->valuefloat;
		float posY = Json_getItemAt(source, 1)->valuefloat;
		int visable = Json_getItemAt(source, 6)->valueint;
		const char *pic = Json_getItemAt(source, 8)->valuestring;
		this->setBoneStencil(std::string(pic), posX, posY, (bool)visable);
	}
}
