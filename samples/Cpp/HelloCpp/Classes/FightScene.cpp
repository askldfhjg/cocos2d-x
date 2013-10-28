#include "FightScene.h"
#include "AppMacros.h"
#include "BoneAction/BoneAction.h"
#include "TableViewTestScene.h"
#include "LoadingScene.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#include <windows.h>
#include "direct.h" 
#include <strsafe.h>
#include "vld.h"
#endif

USING_NS_CC;

CCScene* FightScene::scene()
{
    CCScene *scene = CCScene::create();
    FightScene *layer = FightScene::create();
    scene->addChild(layer);
    return scene;
}

FightScene::~FightScene(void)
{
	equipList->removeAllObjects();
	CC_SAFE_RELEASE(equipList);
}

bool FightScene::init()
{
	if (!CCLayerColor::initWithColor(ccc4(214, 214, 214, 255)))
	//if (!CCLayer::init())
    {
        return false;
    }
    setTouchEnabled(true);
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	CCSize winSize = CCEGLView::sharedOpenGLView()->getFrameSize();

	//读取装备骨骼
	equipList = CCArray::create();
	equipList->retain();
	actionList = CCArray::create();
	actionList->retain();
	motionList = CCArray::create();
	motionList->retain();
	checkSkl();

	checkMontion();

    CCSprite* pSprite = CCSprite::create("pic/bg.png");
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	//this->addChild(pSprite, 0);

	

	//btn
	CCLabelTTF *labell = CCLabelTTF::create("refresh", "Marker Felt", 26);
	labell->setPosition(ccp(visibleSize.width-143, visibleSize.height - 43));
	labell->setColor(ccc3(255,0,0));
	this->addChild(labell);
	CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
        "pic/CloseNormal.png",
        "pic/CloseSelected.png",
        this,
        menu_selector(FightScene::menuCloseCallback));
	CCMenu* pMenu =CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
	pCloseItem->setPosition(ccp(visibleSize.width-43, visibleSize.height -43));
	this->addChild(pMenu, 5);

	CCLabelTTF *label = CCLabelTTF::create("speed normal", "Marker Felt", 26);
	label->setTag(77);
	label->setPosition(ccp(visibleSize.width-363, visibleSize.height - 43));
	label->setColor(ccc3(255,0,0));
	this->addChild(label);

	CCMenuItemImage *pSpeedItem = CCMenuItemImage::create(
        "pic/CloseNormal.png",
        "pic/CloseSelected.png",
        this,
        menu_selector(FightScene::menuSpeedCallback));
	CCMenu* pMenuSpeed =CCMenu::create(pSpeedItem, NULL);
    pMenuSpeed->setPosition( CCPointZero );
	pSpeedItem->setPosition(ccp(visibleSize.width-243, visibleSize.height -43));
	this->addChild(pMenuSpeed, 5);

	CCLabelTTF *labelEquip = CCLabelTTF::create("equip list", "Marker Felt", 24);
	labelEquip->setPosition(ccp(70, visibleSize.height-10));
	labelEquip->setColor(ccc3(0,0,0));
	this->addChild(labelEquip);
	TableViewTestLayer *pLayer = TableViewTestLayer::create(equipList, this, callfuncO_selector(FightScene::streakMove));
	pLayer->setTag(33);
	pLayer->setAnchorPoint(ccp(0, 0));
	pLayer->setPosition(ccp(0, visibleSize.height-275));
	this->addChild(pLayer);

	CCLabelTTF *labelAction = CCLabelTTF::create("equip list", "Marker Felt", 24);
	labelAction->setPosition(ccp(70, 260));
	labelAction->setColor(ccc3(0,0,0));
	this->addChild(labelAction);
	TableViewTestLayer *actionLayer = TableViewTestLayer::create(actionList, this, callfuncO_selector(FightScene::startAttack));
	actionLayer->setTag(44);
	actionLayer->setAnchorPoint(ccp(0, 0));
	actionLayer->setPosition(ccp(0, 0));
	this->addChild(actionLayer);

	CCLabelTTF *labelMotion = CCLabelTTF::create("bone list", "Marker Felt", 24);
	labelMotion->setPosition(ccp(visibleSize.width-130, 265));
	labelMotion->setColor(ccc3(0,0,0));
	this->addChild(labelMotion);
	TableViewTestLayer *motionLayer = TableViewTestLayer::create(motionList, this, callfuncO_selector(FightScene::afterAttack));
	motionLayer->setTag(447);
	motionLayer->setAnchorPoint(ccp(0, 0));
	motionLayer->setPosition(ccp(visibleSize.width-200, 0));
	this->addChild(motionLayer);
    return true;
}

void FightScene::menuSpeedCallback(CCObject* pSender)
{
	CCLabelTTF *view = (CCLabelTTF *)this->getChildByTag(77);
	std::string ff = std::string(view->getString());
	if(def)
	{
		if(ff == "speed normal")
		{
			view->setString("speed slow");
			def->setAnimationInterval(1/2.0f);
		}
		else
		{
			view->setString("speed normal");
			def->setAnimationInterval(1/24.0f);
		}
	}

}


void FightScene::menuCloseCallback(CCObject* pSender)
{
	m_pActionManager->removeAllActionsFromTarget(def);
	checkSkl();
	checkMontion();
	if(def != NULL)
	{
		this->removeChild(def);
	}
	TableViewTestLayer *view = (TableViewTestLayer *)this->getChildByTag(33);
	view->updateList(this->equipList);
	view = (TableViewTestLayer *)this->getChildByTag(44);
	view->updateList(this->actionList);
	view = (TableViewTestLayer *)this->getChildByTag(447);
	view->updateList(this->motionList);
	CCLabelTTF * vview = (CCLabelTTF *)this->getChildByTag(77);
	vview->setString("speed normal");
}


void FightScene::startAttack(CCObject *dd)
{
	if(!def)
	{
		return;
	}
	CCString *ff = (CCString *)dd;
	CCSequence *gg = CCSequence::create(def->createAction(ff->getCString()), NULL);
	def->runAction(gg);
}

void FightScene::streakMove(CCObject *dd)
{
	if(!def)
	{
		return;
	}
	CCString *ff = (CCString *)dd;
	std::string fgg = std::string(ff->getCString());
	size_t last = 0;
	size_t index = fgg.find_first_of("+",last);
	std::string pic;
	while (index!=std::string::npos)
	{
		pic = fgg.substr(last,index-last);
		last = index+1;
		index = fgg.find_first_of("+",last);
	}
	std::string name = fgg.substr(last,index-last);
	def->changeBoneTexture(pic.c_str(), name.c_str());
}

void FightScene::afterAttack(CCObject *dd)
{
	if(def != NULL)
	{
		this->removeChild(def);
	}
	CCString *ff = (CCString *)dd;
	CCBoneActionManager::sharedManager()->addAnimation(const_cast<char *>(ff->getCString()));
	def = CCBoneSpriteLayer::create(ff->getCString(), "test01_mon_res");
	def->setPosition(ccp(500, 100));
	//def->setScale(0.5f);

	this->addChild(def, 3);

	CC_SAFE_RELEASE(actionList);
	actionList = def->allLabel();
	actionList->retain();
	TableViewTestLayer *view = (TableViewTestLayer *)this->getChildByTag(44);
	view->updateList(this->actionList);
}

void FightScene::checkSkl()
{
	CCSpriteFrameCache *cache = CCSpriteFrameCache::sharedSpriteFrameCache();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	std::vector<std::string>::const_iterator searchPathsIter = CCFileUtils::sharedFileUtils()->getSearchPaths().begin();
	std::string root = *searchPathsIter;
	std::string dirRoot = root.substr(0, root.length() - 1);
	dirRoot += "\\bone\\*.equip";
	WIN32_FIND_DATA FindFileData; 

	size_t size = dirRoot.length();
	wchar_t *buffer = new wchar_t[size+1];
	MultiByteToWideChar( CP_ACP, 0, dirRoot.c_str(), size, buffer, size * sizeof(wchar_t) );
	buffer[size] = 0;  // 确保以 '\0' 结尾  

	equipList->removeAllObjects();
	HANDLE hFind = FindFirstFile(buffer, &FindFileData);
	if(hFind != INVALID_HANDLE_VALUE)
	{
		do
		{
			if(FindFileData.cFileName[0]=='.')
				continue;
			if(!(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
			{
				char str[MAX_PATH]={0};
				WideCharToMultiByte(CP_ACP, 0, FindFileData.cFileName, sizeof(FindFileData.cFileName) + 1, str, MAX_PATH, NULL, NULL);
				std::string fgg = std::string(str);
				if(fgg == "AvatarEquip_defultM.equip")
				{
					continue;
				}
				size_t last = 0;
				size_t index = fgg.find_first_of(".",last);
				while (index!=std::string::npos)
				{
					std::string fggg = fgg.substr(last,index-last);
					std::string path = CCBoneSpriteConfig::getBoneUrl() + fggg + ".equip";
					std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(path.c_str());
					unsigned long size;
					char* buffer = (char*)CCFileUtils::sharedFileUtils()->getFileData(fullPath.c_str(), "rt", &size);
					Json* root = Json_create(buffer);
					CC_SAFE_DELETE_ARRAY(buffer);
					int count = Json_getSize(root);
					for(int i = 0; i< count; i++)
					{
						Json *tmp = Json_getItemAt(root, i);
						std::string tmpString = tmp->name;
						if(tmpString == "full")
						{
							continue;
						}
						std::string ggg = fggg+"+"+tmpString;
						CCString *ff = CCString::create(ggg);
						CCLog(ff->getCString());
						equipList->addObject(ff);
					}
					Json_dispose(root);
					break;
				}
			}
		}
		while(FindNextFile(hFind,&FindFileData) != 0);
	}
	delete []buffer;
	FindClose(hFind);
#else
    equipList->removeAllObjects();
    CCString *ff = CCString::create("weapon");
    equipList->addObject(ff);
    ff = CCString::create("goldGlory_M");
    equipList->addObject(ff);
#endif
}


void FightScene::checkMontion()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	std::vector<std::string>::const_iterator searchPathsIter = CCFileUtils::sharedFileUtils()->getSearchPaths().begin();
	std::string root = *searchPathsIter;
	std::string dirRoot = root.substr(0, root.length() - 1);
	dirRoot += "\\bone\\*.motion";
	size_t size = dirRoot.length();
	wchar_t *buffer = new wchar_t[size+1];
	MultiByteToWideChar( CP_ACP, 0, dirRoot.c_str(), size, buffer, size * sizeof(wchar_t) );
	buffer[size] = 0;
	actionList->removeAllObjects();
	motionList->removeAllObjects();
	WIN32_FIND_DATA FindFileData; 
	HANDLE hFind = FindFirstFile(buffer, &FindFileData);
	bool found = true;
	int sec = 0;
	if(hFind != INVALID_HANDLE_VALUE)
	{
		do
		{
			if(FindFileData.cFileName[0]=='.')
				continue;
			if(!(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
			{
				/*LARGE_INTEGER date, adjust;
				date.HighPart = FindFileData.ftLastWriteTime.dwHighDateTime;
				date.LowPart = FindFileData.ftLastWriteTime.dwLowDateTime;
				adjust.QuadPart = 11644473600000 * 10000;
				date.QuadPart -= adjust.QuadPart;
				if(date.QuadPart / 10000000 < sec)
				{
					continue;
				}
				sec = date.QuadPart / 10000000;*/
				char str[MAX_PATH]={0};
				WideCharToMultiByte(CP_ACP, 0, FindFileData.cFileName, sizeof(FindFileData.cFileName) + 1, str, MAX_PATH, NULL, NULL);
				std::string fgg = std::string(str);
				size_t last = 0;
				size_t index = fgg.find_first_of(".",last);
				while (index!=std::string::npos)
				{
					std::string fggg = fgg.substr(last,index-last);
					if(found)
					{
						motionList->addObject(CCString::create(fggg.c_str()));
						break;
					}
					/*CCBoneActionManager::sharedManager()->replaceAnimation(const_cast<char *>(fggg.c_str()));
					found = true;
					if(def != NULL)
					{
						this->removeChild(def);
					}
					def = CCBoneSpriteLayer::create(fggg.c_str(), "AvatarEquip_defultM");
					def->setPosition(ccp(400, 50));
					def->setScale(0.5f);

					//def->changeBoneTexture("sword", "BallinBlade");
					this->addChild(def, 3);

					CC_SAFE_RELEASE(actionList);
					actionList = def->allLabel();
					actionList->retain();
					motionList->addObject(CCString::create(fggg.c_str()));*/
					break;
				}
			}
		}
		while(FindNextFile(hFind,&FindFileData) != 0);
	}
	delete []buffer;
	FindClose(hFind);
#else
    actionList->removeAllObjects();
    std::string fggg = std::string("AvatarSklM");
    CCBoneActionManager::sharedManager()->replaceAnimation(const_cast<char *>(fggg.c_str()));
    if(def != NULL)
    {
        this->removeChild(def);
    }
    def = CCBoneSpriteLayer::create(const_cast<char *>(fggg.c_str()), "AvatarEquip_defultM");
    def->setPosition(ccp(400, 50));
    def->setScale(0.5f);
    
    def->changeBoneTexture("sword", "BallinBlade");
    this->addChild(def, 3);
    
    CC_SAFE_RELEASE(actionList);
    actionList = def->allLabel();
    actionList->retain();
#endif
}

CCRenderTexture* FightScene::createStroke(CCSprite* label, int size, ccColor3B color, GLubyte opacity)
{
    CCRenderTexture* rt = CCRenderTexture::create(
        label->getTexture()->getContentSize().width + size * 2,
        label->getTexture()->getContentSize().height+size * 2
        );

    CCPoint originalPos = label->getPosition();
    ccColor3B originalColor = label->getColor();
    GLubyte originalOpacity = label->getOpacity();
    bool originalVisibility = label->isVisible();
    label->setColor(color);
    label->setOpacity(opacity);
    label->setVisible(true);
    ccBlendFunc originalBlend = label->getBlendFunc();
    ccBlendFunc bf = {GL_SRC_ALPHA, GL_ONE};
    label->setBlendFunc(bf);
    CCPoint bottomLeft = ccp(
        label->getTexture()->getContentSize().width * label->getAnchorPoint().x + size, 
        label->getTexture()->getContentSize().height * label->getAnchorPoint().y + size);
    CCPoint positionOffset= ccp(
        - label->getTexture()->getContentSize().width / 2,
        - label->getTexture()->getContentSize().height / 2);
    CCPoint position = ccpSub(originalPos, positionOffset);
    rt->begin();
    for (int i=0; i<360; i+= 15) // you should optimize that for your needs
    {
        label->setPosition(
            ccp(bottomLeft.x + sin(CC_DEGREES_TO_RADIANS(i))*size, bottomLeft.y + cos(CC_DEGREES_TO_RADIANS(i))*size)
            );
        label->visit();
    }
    rt->end();

    label->setPosition(originalPos);
    label->setColor(originalColor);
    label->setBlendFunc(originalBlend);
	label->setVisible(originalVisibility);
    label->setOpacity(originalOpacity);
    rt->setPosition(position);

    return rt;
}

