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
	std::string dd = std::string(name);
	dd += ".motion";
	std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(dd.c_str());
	
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
	
	m_pAnimationData->insert(char_json::value_type(key, root));
	return NULL;
}

Json *CCBoneActionManager::addAnimation(char *name)
{
	CCString *key = CCString::create(name);
	char_json::iterator it = m_pAnimationData->find(key);
	key->retain();
	if (it != m_pAnimationData->end())
	{
		key->release();
		return it->second;
	}
	std::string path = std::string(name) + ".motion";
	std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(path.c_str());
    unsigned long size;
    char* buffer = (char*)CCFileUtils::sharedFileUtils()->getFileData(fullPath.c_str(), "rt", &size);
    Json* root = Json_create(buffer);
	CC_SAFE_DELETE_ARRAY(buffer);
	
	key->retain();
	m_pAnimationData->insert(char_json::value_type(key, root));
	return root;
}

void CCBoneActionManager::addAnimationAsync(char *name, CCCallFunc *callback)
{
	this->async(this, callfuncNDD_return_selector(CCBoneActionManager::addAnimationByAsync), NULL, name, NULL, callback);
}

Json *CCBoneActionManager::getAnimation(char *name)
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
	CCAssert(tmp != NULL, "no animation");
	return tmp;
}

void CCBoneActionManager::purgeSharedCache()
{
	CC_SAFE_RELEASE_NULL(pSharedManager);
}
