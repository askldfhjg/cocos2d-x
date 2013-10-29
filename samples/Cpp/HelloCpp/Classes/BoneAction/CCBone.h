#ifndef __BONE_H__
#define __BONE_H__
#include "cocos2d.h"
#include "../../extensions/spine/Json.h"
USING_NS_CC;
using namespace cocos2d::extension;

struct CCBonePicWeight
{
	const char *pic;
	int type;
	float topOffset;
	float leftOffset;
	bool isFull;
	int weight;
};

class CCBone : public CCSprite
{
public:
	CCBone()
		:m_frame(NULL)
		,m_pic(NULL)
		,m_brightness(0)
		,m_startZOrder(0)
		,m_picLowWeight(NULL)
		,m_picNowWeight(NULL)
		,m_masked(false)
	{};
	virtual ~CCBone(void);

public:
    /** creates the action */
    static CCBone *createWithSpriteFrame(CCSpriteFrame *pSpriteFrame, std::string &name);
	static CCBone *create(std::string &name);
	void changeTexture(CCTexture2D * texture);
	const char *getName();
	void setStartStatus(bool del);
	void setOffset(float top, float left);
	float getTopOffset();
	float getLeftOffset();
	void setStartArch(const CCPoint& anchor);
	void Reset();
	float getBrightness();
	void setBrightness(float brightness);
	void setAlpha(float alpha);
	float getAlpha();
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
	int m_startZOrder;
	CCSpriteFrame *m_pic;
	Json *m_frame;
	float m_brightness;
	float m_alpha;
	CCBonePicWeight *m_picLowWeight;
	CCBonePicWeight *m_picNowWeight;
	std::string name;
	bool m_masked;
};


#endif //__BONE_H__