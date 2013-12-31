#ifndef __BONE_H__
#define __BONE_H__
#include "cocos2d.h"
#include "CCboneActionManager.h"
#include "../../extensions/spine/Json.h"
USING_NS_CC;
using namespace cocos2d::extension;

struct CCBonePicWeight
{
	const char *pic;
	float topOffset;
	float leftOffset;
	bool isFull;
	int prevent;
};

struct CCBoneJsonData
{
	float posX;
	float posY;
	float scaleX;
	float scaleY;
	float skewX;
	float skewY;
	float visable;
	float colorRed;
	float colorGreen;
	float colorBlue;
};

class CCBones : public CCSprite
{
public:
	CCBones()
		:m_weightList(NULL)
		,m_redPercent(0)
		,m_greenPercent(0)
		,m_bluePercent(0)
		,m_startZOrder(0)
		,m_masked(false)
		,m_boneData(NULL)
		,m_preventList(NULL)
	{};
	virtual ~CCBones(void);

public:
    /** creates the action */
    static CCBones *createWithSpriteFrame(CCSpriteFrame *pSpriteFrame, std::string &name);
	static CCBones *create(std::string &name);
	static void setFrame(CCArray *boneArray, int frameInAll, int frameInAction);
	void changeTexture(CCTexture2D * texture);
	const char *getName();
	void setStartStatus(bool del);
	void setOffset(float top, float left);
	float getTopOffset();
	float getLeftOffset();
	void Reset();
	void setRedPercent(float red);
	void setGreenPercent(float green);
	void setBluePercent(float blue);
	void setAlpha(float alpha);
	void clearWeightList();
	float getAlpha();
	static CCGLProgram *getShader();
	virtual void draw(void);

public:
	CCPoint m_startPosition;
	float m_fStartAngleX;
	float m_fStartAngleY;
	float m_fStartScaleX;
	float m_fStartScaleY;
	bool m_startVisable;
	float m_topOffset;
	float m_leftOffset;
	int endFrame;
	int m_startZOrder;
	int_json *m_boneData;
	float m_redPercent;
	float m_greenPercent;
	float m_bluePercent;
	float m_alpha;
	CCBonePicWeight **m_weightList;
	int *m_preventList;
	std::string name;
	bool m_masked;
	static int weightListLength;
};


#endif //__BONE_H__