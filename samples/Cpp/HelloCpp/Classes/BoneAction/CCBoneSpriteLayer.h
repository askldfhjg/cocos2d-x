#ifndef __LAYER_BONE_SPRITE_H__
#define __LAYER_BONE_SPRITE_H__
#include "CCLayerAction.h"
#include "CCBones.h"
#include "CCEffect.h"
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
		,frameIndex(0)
		,lastFrame(0)
    {}
	~CCBoneSpriteLayer(void);
	virtual bool init(const char *animationName, const char *defaultSkl, bool isBatch);

//luaµ¼³ö
public:
	static CCBoneSpriteLayer *create(const char *animationName, const char *defaultSkl);
	static CCBoneSpriteLayer *createWithBatch(const char *animationName, char *defaultSkl);
	CCLayerAction *createAction(const char *BoneMove, float time);
	CCLayerAction *createAction(const char *BoneMove);
	CCBones *getBoneByName(const char *name);
	void changeBoneTexture(const char *textureName, const char *equipName);
	void resetBoneTexture(const char *textureName, const char *equipName);
	void setAnimationInterval(double interval);
	CCAction *testLayerAction();
	CCAction *randomLayerAction();
	CCAction *indexLayerAction(int index);
	void setBoneAction(const char *name);
	const char *getBoneAction();
	CCSize getLayerSize();
	
public:
	bool getLabel(const char *name, int &startFrame, int &endFrame);
	const char *getLabelNamebyFrame(int frame);
	CCRenderTexture* createStroke(CCSprite* label, int size, ccColor3B color, GLubyte opacity);
	bool haveEffect();
	CCAction *runAction(CCAction* action, bool stopBefore = true);
	CCArray* allLabel();
public:
	CCArray *m_bone; 
	CCArray *m_effect;
	CCBoneClip *m_clip;
	int frameIndex;
	int lastFrame;

private:
	double interval;
	Json *m_label;
	bool isBatch;
	bool isEffect;
	int *orderList;
};

#endif //__LAYER_BONE_SPRITE_H__