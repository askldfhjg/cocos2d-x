#ifndef __LAYER_BONE_SPRITE_H__
#define __LAYER_BONE_SPRITE_H__
#include "CCLayerAction.h"
#include "CCBone.h"
#include "cocos2d.h"
USING_NS_CC;


class CCBoneSpriteLayer : public cocos2d::CCLayer
{
public:
	CCBoneSpriteLayer()
		:m_label(NULL)
		,m_bone(NULL)
		,m_effect(NULL)
		,m_clip(NULL)
		,interval(1.0/24)
		,isBatch(false)
		,isEffect(false)
    {}
	~CCBoneSpriteLayer(void);
	virtual bool init(const char *animationName, const char *defaultSkl, bool isBatch);

//lua����
public:
	static CCBoneSpriteLayer *create(const char *animationName, const char *defaultSkl);
	static CCBoneSpriteLayer *createWithBatch(const char *animationName, char *defaultSkl);
	CCLayerAction *createAction(const char *BoneMove, float time);
	CCLayerAction *createAction(const char *BoneMove);
	CCBone *getBoneByName(const char *name);
	void changeBoneTexture(const char *textureName, const char *equipName);
	void resetBoneTexture(const char *textureName, const char *equipName);
	void setAnimationInterval(double interval);
	CCAction *testLayerAction();
	CCAction *randomLayerAction();
	CCAction *indexLayerAction(int index);
	
public:
	bool getLabel(const char *name, int &startFrame, int &endFrame);
	CCRenderTexture* createStroke(CCSprite* label, int size, ccColor3B color, GLubyte opacity);
	bool haveEffect();
	CCAction *runAction(CCAction* action, bool stopBefore = true);
	CCArray* allLabel();
public:
	CCArray *m_bone; 
	CCArray *m_effect;
	CCBoneClip *m_clip;

private:
	double interval;
	Json *m_label;
	bool isBatch;
	bool isEffect;
	
};

#endif //__LAYER_BONE_SPRITE_H__