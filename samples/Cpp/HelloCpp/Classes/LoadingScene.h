#ifndef __LOADING_SCENE_H__
#define __LOADING_SCENE_H__

#include "cocos2d.h"

class LoadingScene : public cocos2d::CCLayerColor
{
public:
	LoadingScene()
		:m_nNumberOfLoaded(0)
		,m_nNumberOfSprites(0)
		,m_pLabelLoading(NULL)
		,m_pLabelPercent(NULL)
	{};

    virtual bool init();  

    static cocos2d::CCScene* scene();
    
	void loadingCallBack(cocos2d::CCObject *obj);

	void loadingCallBack2();

	void lastProcess();

    CREATE_FUNC(LoadingScene);
protected:
	int m_nNumberOfLoaded;
	int m_nNumberOfSprites;
	int m_nNumberOfSkl;
	cocos2d::CCLabelTTF *m_pLabelLoading;
	cocos2d::CCLabelTTF *m_pLabelPercent;
};

#endif // __LOADING_SCENE_H__
