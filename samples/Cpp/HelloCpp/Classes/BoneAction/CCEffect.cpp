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

		//ccBlendFunc blend2 = {GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA};
		pobSprite->setShaderProgram(CCBone::getShader());
		//pobSprite->setBlendFunc(blend2);
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
	//ccBlendFunc blend2 = {GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA};
	setShaderProgram(CCBone::getShader());
	//setBlendFunc(blend2);
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


CCBoneClip *CCBoneClip::create()
{
	CCBoneClip *pRet = new CCBoneClip();
    if (pRet && pRet->init())
    {
        pRet->autorelease();
		pRet->setInverted(true);
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
