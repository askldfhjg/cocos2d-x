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
		,interval(1.0/24)
		,isBatch(false)
		,isEffect(false)
    {}
	~CCBoneSpriteLayer(void);
	virtual bool init(const char *spriteName, bool isBatch);

//lua����
public:
	static CCBoneSpriteLayer *create(const char *spriteName);
	static CCBoneSpriteLayer *create(const char *spriteName, char *animationName);
	static CCBoneSpriteLayer *createWithBatch(const char *spriteName);
	static CCBoneSpriteLayer *createWithBatch(const char *spriteName, char *animationName);
	CCLayerAction *createAction(const char *BoneMove, CCFiniteTimeAction *layerMove, BoneMotion boneMotionType);
	CCLayerAction *createAction(const char *BoneMove, CCFiniteTimeAction *layerMove);
	CCBone *getBoneByName(const char *name);
	void changeBoneTexture(const char *textureName, const char *boneName, const char* equipName = NULL);
	void changeBoneTexture(const char *textureName);
	void changeBoneTexture(const char *textureName, const char *boneName);
	void changeBoneTexture(CCDictionary *info);
	void setAnimation(char *name);
	void setAnimationInterval(double interval);
	CCAction *testLayerAction();
	CCAction *randomLayerAction();
	CCAction *indexLayerAction(int index);
	
public:
	bool getLabel(const char *name, int &startFrame, int &endFrame);
	bool haveEffect();
	CCAction *runAction(CCAction* action, bool stopBefore = true);
	CCArray* allLabel();
public:
	CCArray *m_bone; 
	CCArray *m_effect;

private:
	double interval;
	Json *m_label;
	bool isBatch;
	bool isEffect;
	
};

#endif //__LAYER_BONE_SPRITE_H__