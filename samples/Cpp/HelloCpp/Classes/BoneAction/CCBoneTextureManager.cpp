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
	std::string textureName = getTextureName((char *)data1);
	std::string texturePic = "pic/" + textureName +".plist";
	std::string path = "bone/" + textureName + "."+item;
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
	newKey->retain();
	m_pTextureData->insert(char_json::value_type(newKey, root));
	char* ret = new char[255];
	//strcpy_s(ret, texturePic.size() + 1, texturePic.c_str());
    strlcpy(ret, texturePic.c_str(), texturePic.size() + 1);
	return ret;
}

Json *CCBoneTextureManager::addEquip(char *name)
{
	std::string textureName = getTextureName(name);
	std::string path = "bone/" + textureName + ".equip";
	std::string texturePic = "pic/" + textureName +".plist";
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
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(texturePic.c_str());
	return root;
}

Json *CCBoneTextureManager::addSkl(char *name)
{
	std::string textureName = getTextureName(name);
	std::string path = "bone/" + textureName + ".skl";
	std::string texturePic = "pic/" + textureName +".plist";
	std::string key = textureName+"_skl";
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
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(texturePic.c_str());
	return root;
}

void CCBoneTextureManager::addSklAsync(char *name, CCCallFunc *callback)
{
	this->async(this, callfuncNDD_return_selector(CCBoneTextureManager::addTextureByAsync), NULL, name, (void *)"skl", callback);
}
void CCBoneTextureManager::addEquipAsync(char *name, CCCallFunc *callback)
{
	this->async(this, callfuncNDD_return_selector(CCBoneTextureManager::addTextureByAsync), NULL, name, (void *)"equip", callback);
}

Json *CCBoneTextureManager::getEquip(char *name)
{
	CCAssert(name, "plist filename should not be NULL");
	Json *tmp = NULL;

	std::string textureName = getTextureName(name);
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

Json *CCBoneTextureManager::getSkl(char *name)
{
	CCAssert(name, "plist filename should not be NULL");
	Json *tmp = NULL;

	std::string textureName = getTextureName(name);
	std::string key = textureName+"_skl";
	CCString *newKey = CCString::create(key);
	char_json::iterator it = m_pTextureData->find(newKey);
	if (it == m_pTextureData->end())
	{
		tmp = this->addSkl(name);
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

std::string CCBoneTextureManager::getTextureName(char *name)
{
	std::string s = std::string(name);
	size_t last = 0;
	size_t index=s.find_first_of("/",last);
	std::vector< std::string> ret = std::vector<std::string>();
	while (index!=std::string::npos)
	{
		ret.push_back(s.substr(last,index-last));
		last=index+1;
		index=s.find_first_of("/",last);
	}
	if (index-last>0)
	{
		ret.push_back(s.substr(last,index-last));
	}
	return ret.back();
}
