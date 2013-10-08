#include "cocos2d.h"
#include "Function.h"
#include "CCBoneTextureManager.h"
#include "../../extensions/spine/Json.h"

using namespace cocos2d::extension;
USING_NS_CC;

static CCBoneTextureManager *pSharedManager = NULL;

CCBoneTextureManager* CCBoneTextureManager::sharedManager(void)
{
    if (!pSharedManager)
    {
        pSharedManager = new CCBoneTextureManager();
        pSharedManager->init();
    }
    return pSharedManager;
}

bool CCBoneTextureManager::init(void)
{
    m_pTextureData = new char_json();
    return true;
}

CCBoneTextureManager::~CCBoneTextureManager(void)
{
	CCBoneTextureManager::threadAsync::over();
	if(m_pTextureData->size() > 0)
	{
		char_json::iterator iter;
		for (iter = m_pTextureData->begin(); iter != m_pTextureData->end();)
		{
			Json_dispose(iter->second);
			m_pTextureData->erase(iter++);
		}
	}
	CC_SAFE_DELETE(m_pTextureData);
}

char *CCBoneTextureManager::addTextureByAsync(CCNode *target, void *data1, void *data2)
{
	std::string item = std::string((char *)data2);
	std::string textureName = std::string((char *)data1);
	std::string texturePic = CCBoneSpriteConfig::equipUrl + textureName +".plist";
	std::string path = CCBoneSpriteConfig::boneUrl + textureName + "."+item;
	std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(path.c_str());
	std::string key = textureName+"_"+item;
	CCString *newKey = CCString::create(key);
	newKey->retain();
	char_json::iterator it = m_pTextureData->find(newKey);	
	if (it != m_pTextureData->end())
	{
		newKey->release();
		return NULL;
	}

    unsigned long size;
    char* buffer = (char*)CCFileUtils::sharedFileUtils()->getFileData(fullPath.c_str(), "rt", &size);
    Json* root = Json_create(buffer);
	CC_SAFE_DELETE_ARRAY(buffer);
	if(!buffer)
	{
		return NULL;
	}

	newKey->retain();
	m_pTextureData->insert(char_json::value_type(newKey, root));
	bool isFull = (bool)Json_getItem(root, "full")->valueint;
	if(isFull)
	{
		char* ret = new char[255];
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
		strcpy_s(ret, texturePic.size() + 1, texturePic.c_str());
#else
		strlcpy(ret, texturePic.c_str(), texturePic.size() + 1);
#endif
		return ret;
	}
	else
	{
		return NULL;
	}

}

Json *CCBoneTextureManager::addEquip(char *name)
{
	std::string textureName = std::string(name);
	std::string path = CCBoneSpriteConfig::boneUrl + textureName + ".equip";
	std::string texturePic = CCBoneSpriteConfig::equipUrl + textureName +".plist";
	std::string key = textureName+"_equip";
	CCString *newKey = CCString::create(key);
	newKey->retain();
	char_json::iterator it = m_pTextureData->find(newKey);	
	if (it != m_pTextureData->end())
	{
		newKey->release();
		return it->second;
	}
	std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(path.c_str());
    unsigned long size;
    char* buffer = (char*)CCFileUtils::sharedFileUtils()->getFileData(fullPath.c_str(), "rt", &size);
    Json* root = Json_create(buffer);
	CC_SAFE_DELETE_ARRAY(buffer);
	m_pTextureData->insert(char_json::value_type(newKey, root));
	bool isFull = (bool)Json_getItem(root, "full")->valueint;
	if(isFull)
	{
		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(texturePic.c_str());
	}
	return root;
}

void CCBoneTextureManager::addEquipAsync(char *name, CCCallFunc *callback)
{
	this->async(this, callfuncNDD_return_selector(CCBoneTextureManager::addTextureByAsync), NULL, name, (void *)"equip", callback);
}

Json *CCBoneTextureManager::getEquip(char *name)
{
	CCAssert(name, "plist filename should not be NULL");
	Json *tmp = NULL;

	std::string textureName = std::string(name);
	std::string key = textureName+"_equip";
	CCString *newKey = CCString::create(key);
	char_json::iterator it = m_pTextureData->find(newKey);
	if (it == m_pTextureData->end())
	{
		tmp = this->addEquip(name);
	}
	else
	{
		tmp = it->second;
	}
	CCAssert(tmp != NULL, "no animation");
	return tmp;
}

void CCBoneTextureManager::purgeSharedCache()
{
	CC_SAFE_RELEASE_NULL(pSharedManager);
}
