#include "cocos2d.h"
#include "Function.h"
#include "CCBoneActionManager.h"
#include "../../extensions/spine/Json.h"

using namespace cocos2d::extension;
USING_NS_CC;

static CCBoneActionManager *pSharedManager = NULL;

CCBoneActionManager* CCBoneActionManager::sharedManager(void)
{
    if (!pSharedManager)
    {
        pSharedManager = new CCBoneActionManager();
        pSharedManager->init();
    }
    return pSharedManager;
}

bool CCBoneActionManager::init(void)
{
    m_pAnimationData = new char_json();
    return true;
}

CCBoneActionManager::~CCBoneActionManager(void)
{
	CCBoneActionManager::threadAsync::over();
	if(m_pAnimationData->size() > 0)
	{
		char_json::iterator iter;
		for (iter = m_pAnimationData->begin(); iter != m_pAnimationData->end();)
		{
			Json_dispose(iter->second);
			CC_SAFE_RELEASE(iter->first);
			m_pAnimationData->erase(iter++);
		}
	}
	CC_SAFE_DELETE(m_pAnimationData);
}

char *CCBoneActionManager::addAnimationByAsync(CCNode *target, void *data1, void *data2)
{
	char *name = (char *)data1;
	CCString *key = CCString::create(name);
	key->retain();
	std::string path = CCBoneSpriteConfig::getBoneUrl() + std::string(name) + ".motion";
	std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(path.c_str());
	
	char_json::iterator it = m_pAnimationData->find(key);	
	if (it != m_pAnimationData->end())
	{
		key->release();
		return NULL;
	}

    unsigned long size;
    char* buffer = (char*)CCFileUtils::sharedFileUtils()->getFileData(fullPath.c_str(), "rt", &size);
	Json* root = Json_create(buffer);
	CC_SAFE_DELETE_ARRAY(buffer);
	if(!root)
	{
		return NULL;
	}
	m_pAnimationData->insert(char_json::value_type(key, root));

	std::string actionName = std::string(name);
	Json *source = Json_getItem(root, "effect");
	int isEffect = source->valueint;
	if(isEffect)
	{
		path =  CCBoneSpriteConfig::getBoneUrl() + std::string(name) + ".effect";
		fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(path.c_str());
		size = 0;
		buffer = (char*)CCFileUtils::sharedFileUtils()->getFileData(fullPath.c_str(), "rt", &size);
		root = Json_create(buffer);
		CC_SAFE_DELETE_ARRAY(buffer);
		actionName = std::string(name) + "_effect";
		CCString *key2 = CCString::create(actionName);
		key2->retain();
		m_pAnimationData->insert(char_json::value_type(key2, root));


		actionName =  CCBoneSpriteConfig::getEffectUrl() + std::string(name) +"effect.plist";

		char* ret = new char[255];
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
		strcpy_s(ret, actionName.size() + 1, actionName.c_str());
#else
		strlcpy(ret, actionName.c_str(), actionName.size() + 1);
#endif
		return ret;
	}
	return NULL;
}

Json *CCBoneActionManager::addAnimation(const char *name)
{
	CCString *key = CCString::create(name);
	char_json::iterator it = m_pAnimationData->find(key);
	key->retain();
	if (it != m_pAnimationData->end())
	{
		Json_dispose(it->second);
		CC_SAFE_RELEASE(it->first);
		m_pAnimationData->erase(it++);
	}
	std::string path =  CCBoneSpriteConfig::getBoneUrl() + std::string(name) + ".motion";
	std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(path.c_str());
    unsigned long size;
    char* buffer = (char*)CCFileUtils::sharedFileUtils()->getFileData(fullPath.c_str(), "rt", &size);
    Json* root = Json_create(buffer);
	CC_SAFE_DELETE_ARRAY(buffer);
	if(!root)
	{
		return NULL;
	}
	m_pAnimationData->insert(char_json::value_type(key, root));

	std::string actionName = std::string(name);
	Json *source = Json_getItem(root, "effect");
	int isEffect = source->valueint;
	if(isEffect)
	{
		actionName =  CCBoneSpriteConfig::getEffectUrl() + actionName +"effect.plist";
		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(actionName.c_str());

		path =  CCBoneSpriteConfig::getBoneUrl() + std::string(name) + ".effect";
		fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(path.c_str());
		size = 0;
		buffer = (char*)CCFileUtils::sharedFileUtils()->getFileData(fullPath.c_str(), "rt", &size);
		Json *effectRoot = Json_create(buffer);
		CC_SAFE_DELETE_ARRAY(buffer);
		actionName = std::string(name) + "_effect";
		CCString *key2 = CCString::create(actionName);
		key2->retain();
		m_pAnimationData->insert(char_json::value_type(key2, effectRoot));
	}
	return root;
}

Json *CCBoneActionManager::replaceAnimation(char *name)
{
	CCString *key = CCString::create(name);
	char_json::iterator it = m_pAnimationData->find(key);
	key->retain();
	if (it != m_pAnimationData->end())
	{
		key->release();
		return it->second;
	}
	std::string path =  CCBoneSpriteConfig::getBoneUrl() + std::string(name) + ".motion";
	std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(path.c_str());
    unsigned long size;
    char* buffer = (char*)CCFileUtils::sharedFileUtils()->getFileData(fullPath.c_str(), "rt", &size);
    Json* root = Json_create(buffer);
	CC_SAFE_DELETE_ARRAY(buffer);
	if(!root)
	{
		return NULL;
	}
	m_pAnimationData->insert(char_json::value_type(key, root));

	std::string actionName = std::string(name);
	Json *source = Json_getItem(root, "effect");
	int isEffect = source->valueint;
	if(isEffect)
	{
		actionName =  CCBoneSpriteConfig::getEffectUrl() + actionName +"effect.plist";
		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(actionName.c_str());

		path =  CCBoneSpriteConfig::getBoneUrl() + std::string(name) + ".effect";
		fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(path.c_str());
		size = 0;
		buffer = (char*)CCFileUtils::sharedFileUtils()->getFileData(fullPath.c_str(), "rt", &size);
		root = Json_create(buffer);
		CC_SAFE_DELETE_ARRAY(buffer);
		actionName = std::string(name) + "_effect";
		CCString *key2 = CCString::create(actionName);
		key2->retain();
		m_pAnimationData->insert(char_json::value_type(key2, root));
	}
	return root;
}

void CCBoneActionManager::addAnimationAsync(char *name, CCCallFunc *callback)
{
	this->async(this, callfuncNDD_return_selector(CCBoneActionManager::addAnimationByAsync), NULL, name, NULL, callback);
}

Json *CCBoneActionManager::getAnimation(const char *name)
{
	CCAssert(name, "plist filename should not be NULL");
	Json *tmp = NULL;
	CCString *key = CCString::create(name);
	char_json::iterator it = m_pAnimationData->find(key);
	if (it == m_pAnimationData->end())
	{
		tmp = this->addAnimation(name);
	}
	else
	{
		tmp = it->second;
	}
	if(!tmp)
	{
		CCLog("no Animation %s", name);
	}
	return tmp;
}

Json *CCBoneActionManager::getEffectAnimation(const char *name)
{
	CCAssert(name, "plist filename should not be NULL");
	CCString *key = CCString::create(std::string(name) + "_effect");
	Json *tmp = NULL;
	char_json::iterator it = m_pAnimationData->find(key);
	if (it != m_pAnimationData->end())
	{
		tmp = it->second;
	}
	CCAssert(tmp != NULL, "no animation");
	return tmp;
}
void CCBoneActionManager::purgeSharedCache()
{
	CC_SAFE_RELEASE_NULL(pSharedManager);
}
