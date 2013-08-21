#include "LoadingScene.h"
#include "BoneAction/BoneAction.h"
#include "FightScene.h"
USING_NS_CC;

CCScene* LoadingScene::scene()
{
    CCScene *scene = CCScene::create();
    LoadingScene *layer = LoadingScene::create();
    scene->addChild(layer);
    return scene;
}

bool LoadingScene::init()
{
	if (!CCLayerColor::initWithColor(ccc4(255, 255, 255, 0)))
    {
        return false;
    }
    
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	m_pLabelLoading = CCLabelTTF::create("loading...", "Arial", 20);
    m_pLabelPercent = CCLabelTTF::create("%0", "Arial", 20);

    m_pLabelLoading->setPosition(ccp(size.width / 2, size.height / 2 - 20));
    m_pLabelPercent->setPosition(ccp(size.width / 2, size.height / 2 + 20));

    this->addChild(m_pLabelLoading);
    this->addChild(m_pLabelPercent);

	CCTextureCache::sharedTextureCache()->addImageAsync("pic/bg.png", this, callfuncO_selector(LoadingScene::loadingCallBack));
    CCTextureCache::sharedTextureCache()->addImageAsync("pic/CloseNormal.png", this, callfuncO_selector(LoadingScene::loadingCallBack));
    CCTextureCache::sharedTextureCache()->addImageAsync("pic/CloseSelected.png", this, callfuncO_selector(LoadingScene::loadingCallBack));
	    CCTextureCache::sharedTextureCache()->addImageAsync("pic/AvatarSklMeffect.png", this, callfuncO_selector(LoadingScene::loadingCallBack));
	m_nNumberOfSprites = 4;
	m_nNumberOfSkl = 4;
    return true;
}

void LoadingScene::loadingCallBack(CCObject *obj)
{
    ++m_nNumberOfLoaded;
    char tmp[10];
    sprintf(tmp,"%%%d", m_nNumberOfLoaded);
    m_pLabelPercent->setString(tmp);

    if (m_nNumberOfLoaded == m_nNumberOfSprites)
    {
		CCBoneActionManager::sharedManager()->addAnimationAsync("bone/AvatarSklM", CCCallFunc::create(this, callfunc_selector(LoadingScene::loadingCallBack2)));
		CCBoneTextureManager::sharedManager()->addSklAsync("bone/AvatarSklM", CCCallFunc::create(this, callfunc_selector(LoadingScene::loadingCallBack2)));
		CCBoneTextureManager::sharedManager()->addEquipAsync("bone/goldGlory_M", CCCallFunc::create(this, callfunc_selector(LoadingScene::loadingCallBack2)));
		CCBoneTextureManager::sharedManager()->addEquipAsync("bone/weapon", CCCallFunc::create(this, callfunc_selector(LoadingScene::loadingCallBack2)));
    }
}

void LoadingScene::loadingCallBack2()
{
    ++m_nNumberOfLoaded;
    char tmp[10];
    sprintf(tmp,"%%%d", m_nNumberOfLoaded);
    m_pLabelPercent->setString(tmp);
	if (m_nNumberOfLoaded == (m_nNumberOfSprites + m_nNumberOfSkl))
    {
		lastProcess();
    }
}

void LoadingScene::lastProcess()
{
	CCSpriteFrameCache *cache = CCSpriteFrameCache::sharedSpriteFrameCache();
	//cache->addSpriteFramesWithFile("pic/AvatarSklMeffect.plist");
	CCScene *pScene = FightScene::scene();
	CCDirector::sharedDirector()->replaceScene(pScene);
	this->removeChild(m_pLabelLoading, true);
	this->removeChild(m_pLabelPercent, true);
}