#ifndef __EFFECT_H__
#define __EFFECT_H__
#include "cocos2d.h"
#include "../../extensions/spine/Json.h"
#include "CCBones.h"
USING_NS_CC;
using namespace cocos2d::extension;

class CCEffect : public CCBones
{
public:
	CCEffect()
		:m_effectInfo(NULL)
		,m_frameIndex(-1)
		,m_add(false)
		,m_lastFrame(-1)
		,m_lastData(NULL)
	{};
	virtual ~CCEffect(void);

public:
    /** creates the action */
	static CCEffect *create(const char *name);
	static void setFrame(CCArray *effectArray, int frameInAll, int frameInAction, bool done);
	bool setAnimatime(const char *, bool show, int index, bool done);
	bool getAdd();
	void setAdd(bool add);
public:
	char_effect *m_effectInfo;
	
private:
	int m_frameIndex;
	bool m_add;
	int m_lastFrame;
	CCBoneJson *m_lastData;
};

class CCBoneClip : public CCClippingNode
{
public:
    static CCBoneClip* create();

public:
	CCBoneClip()
		:m_effectInfo(NULL)
		,m_visable(false)
		,m_offsetX(0)
		,m_offsetY(0)
	{};
	virtual ~CCBoneClip();
	virtual void visit();
	virtual void onEnter();
    virtual void onEnterTransitionDidFinish();
    virtual void onExitTransitionDidStart();
    virtual void onExit();

	void setBoneStencil(const char *name, float posX, float posY, bool visable);
	void setFrame(int frame);
public:
	int_json *m_boneData;
	char_effect *m_effectInfo;
	bool m_visable;
	float m_offsetX;
	float m_offsetY;
};

#endif //__EFFECT_H__