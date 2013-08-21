#ifndef __FIGHT_SCENE_H__
#define __FIGHT_SCENE_H__

#include "cocos2d.h"
#include "BoneAction/BoneAction.h"

class FightScene : public cocos2d::CCLayer
{
public:
	FightScene()
		:attack(NULL)
		,def(NULL)
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
	void afterAttack();
    CREATE_FUNC(FightScene);

private:
	void checkSkl();
protected:
	CCBoneSpriteLayer *attack;
	CCBoneSpriteLayer *def;
	CCArray *equipList;
	CCArray *actionList;
};

#endif // __FIGHT_SCENE_H__
