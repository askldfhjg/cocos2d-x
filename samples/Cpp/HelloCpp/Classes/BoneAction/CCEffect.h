#ifndef __EFFECT_H__
#define __EFFECT_H__
#include "cocos2d.h"
#include "../../extensions/spine/Json.h"
#include "CCBone.h"
USING_NS_CC;
using namespace cocos2d::extension;

class CCEffect : public CCBone
{
public:
	CCEffect()
		:m_effectInfo(NULL)
		,m_frameIndex(-1)
		,m_add(false)
		,m_lastFrame(0)
	{};
	virtual ~CCEffect(void);

public:
    /** creates the action */
	static CCEffect *create(std::string &name);
	bool setAnimatime(std::string name, bool show, int index);
	bool getAdd();
	void setAdd(bool add);
public:
	Json *m_effectInfo;
	
private:
	int m_frameIndex;
	bool m_add;
	int m_lastFrame;
};

class CCBoneClip : public CCClippingNode
{
public:
    static CCBoneClip* create();
public:
	CCBoneClip()
		:m_effectInfo(NULL)
		,m_frame(NULL)
		,m_frameIndex(-1)
		,m_add(false)
		,m_lastFrame(0)
	{};
	virtual ~CCBoneClip();
	virtual void onEnter();
    virtual void onEnterTransitionDidFinish();
    virtual void onExitTransitionDidStart();
    virtual void onExit();

public:
	Json *m_frame;
	Json *m_effectInfo;

private:
	int m_frameIndex;
	bool m_add;
	int m_lastFrame;
};

#endif //__EFFECT_H__