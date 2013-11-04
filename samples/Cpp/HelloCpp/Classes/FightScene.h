#ifndef __FIGHT_SCENE_H__
#define __FIGHT_SCENE_H__

#include "cocos2d.h"
#include "BoneAction/BoneAction.h"

class FightScene : public cocos2d::CCLayerColor
{
public:
	FightScene()
		:def(NULL)
		,hpBar(NULL)
		,equipList(NULL)
		,actionList(NULL)
	{};
    virtual bool init();  
	~FightScene(void);
    static cocos2d::CCScene* scene();
    
    void startAttack(CCObject *dd);
    
	void streakMove(CCObject *dd);
	void menuCloseCallback(CCObject* pSender);
	void menuSpeedCallback(CCObject* pSender);
	void afterAttack(CCObject *dd);
	CCRenderTexture* createStroke(CCSprite* label, int size, ccColor3B color, GLubyte opacity);
    CREATE_FUNC(FightScene);

private:
	void checkSkl();
	void checkMontion();
protected:
	CCBoneSpriteLayer *def;
	CCSprite *hpBar;
	CCArray *equipList;
	CCArray *actionList;
	CCArray *motionList;
};

#endif // __FIGHT_SCENE_H__
