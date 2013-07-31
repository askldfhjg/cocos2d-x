#ifndef __BONE_H__
#define __BONE_H__
#include "cocos2d.h"
#include "../../extensions/spine/Json.h"
USING_NS_CC;
using namespace cocos2d::extension;

class CCBone : public CCSprite
{
public:
	CCBone()
		:m_frame(NULL)
		,m_pic(NULL)
		,m_brightness(0)
	{};
	~CCBone(void);

public:
    /** creates the action */
    static CCBone *createWithSpriteFrame(CCSpriteFrame *pSpriteFrame, std::string &name);
	const char *getName();
	void setStartStatus(bool del);
	void setOffset(float top, float left);
	float getTopOffset();
	float getLeftOffset();
	void setStartArch(const CCPoint& anchor);
	void Reset();
	float getBrightness();
	void setBrightness(float brightness);
	static CCGLProgram *getShader();
	virtual void draw(void);

public:
	CCPoint m_startPosition;
	CCPoint m_startArch;
	float m_fStartAngleX;
	float m_fStartAngleY;
	float m_fStartScaleX;
	float m_fStartScaleY;
	bool m_startVisable;
	float m_topOffset;
	float m_leftOffset;
	int endFrame;
	CCSpriteFrame *m_pic;
	Json *m_frame;
	float m_brightness;
	std::string name;
};


#endif //__BONE_H__