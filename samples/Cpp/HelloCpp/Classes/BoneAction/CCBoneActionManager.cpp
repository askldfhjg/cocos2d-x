#include "cocos2d.h"
#include "Function.h"
#include "CCBoneActionManager.h"
#include "../../extensions/spine/extension.h"

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
    m_pAnimationData = new char_Bone();
    return true;
}

CCBoneActionManager::~CCBoneActionManager(void)
{
	CCBoneActionManager::threadAsync::over();
	if(m_pAnimationData->size() > 0)
	{
		char_Bone::iterator iter;
		for (iter = m_pAnimationData->begin(); iter != m_pAnimationData->end();)
		{
			clearBoneData(iter->second);
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
	
	char_Bone::iterator it = m_pAnimationData->find(key);	
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
	//m_pAnimationData->insert(char_json::value_type(key, root));

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
		//m_pAnimationData->insert(char_json::value_type(key2, root));


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

CCBoneActionData *CCBoneActionManager::processBoneData(Json *root, Json *effectRoot)
{
	CCBoneActionData *ret = new CCBoneActionData();
	Json *tmp = root->child;
	char_frame *tt = new char_frame();
	int haveEffect = 0;
	while(tmp)
	{
		tmp->prev = NULL;
		Json *ne = tmp->next;
		tmp->next = NULL;
		if(!strcmp(tmp->name,"skl"))
		{
			ret->skl = tmp;
		}
		else if(!strcmp(tmp->name,"label"))
		{
			ret->label = tmp;
		}
		else if(!strcmp(tmp->name,"effect"))
		{
			haveEffect = tmp->valueint;
			Json_dispose(tmp);
		}
		else
		{
			CCString *key = CCString::create(tmp->name);
			key->retain();
			int_json *ttBone = new int_json();
			Json *child2 = tmp->child;
			while(child2)
			{
				int fc = atoi(child2->name);
				CCBoneJson *stTemp = new CCBoneJson();
				Json *boneChild = child2->child;
				stTemp->posX = boneChild->valuefloat;
				boneChild = boneChild->next;
				stTemp->posY = boneChild->valuefloat;
				boneChild = boneChild->next;
				stTemp->scaleX = boneChild->valuefloat;
				boneChild = boneChild->next;
				stTemp->scaleY = boneChild->valuefloat;
				boneChild = boneChild->next;
				stTemp->skewX = boneChild->valuefloat;
				boneChild = boneChild->next;
				stTemp->skewY = boneChild->valuefloat;
				boneChild = boneChild->next;
				stTemp->visable = boneChild->valuefloat;
				boneChild = boneChild->next;
				boneChild = boneChild->child;
				stTemp->colorRed = boneChild->valuefloat;
				boneChild = boneChild->next;
				stTemp->colorGreen = boneChild->valuefloat;
				boneChild = boneChild->next;
				stTemp->colorBlue = boneChild->valuefloat;
				ttBone->insert(int_json::value_type(fc, stTemp));
				child2 = child2->next;
			}
			tt->insert(char_frame::value_type(key, ttBone));
			Json_dispose(tmp);
		}
		tmp = ne;
	}
	ret->frame = tt;
	ret->effectOrder = NULL;
	ret->effectMotion = NULL;
	ret->effect = NULL;
	ret->mask = false;
	if(effectRoot && haveEffect)
	{
		Json *effectChild = effectRoot->child;
		while(effectChild)
		{
			effectChild->prev = NULL;
			Json *ne = effectChild->next;
			effectChild->next = NULL;
			if(!strcmp(effectChild->name,"effect"))
			{
				Json *effect = effectChild->child;
				char_effect *ff = new char_effect();
				while(effect)
				{
					CCString *key = CCString::create(effect->name);
					key->retain();
					CCEffectJson *eft = new CCEffectJson();
					Json *eChild = effect->child;
					while(eChild)
					{
						if(!strcmp(eChild->name,"info"))
						{
							eft->archX = eChild->child->valuefloat;
							eft->archY = eChild->child->next->valuefloat;
							if(eChild->child->next->next)
							{
								eft->width = eChild->child->next->next->valuefloat;
								eft->height = eChild->child->next->next->next->valuefloat;
								eft->posX = eChild->child->next->next->next->next->valuefloat;
								eft->posY = eChild->child->next->next->next->next->next->valuefloat;
							}
 						}
						else if(!strcmp(eChild->name,"type"))
						{
							eChild = eChild->next;
							continue;
						}
						else
						{
							if(!eft->info)
							{
								eft->info = new int_json();
							}
							int fc = atoi(eChild->name);
							CCBoneJson *ii = new CCBoneJson();
							int len = strlen(eChild->child->valuestring);
							char *pic = new char[len+1];
							strcpy(pic, eChild->child->valuestring);
							ii->pic = pic;
							ii->scaleX = eChild->child->next->valuefloat;
							ii->scaleY = eChild->child->next->next->valuefloat;
							ii->posX = eChild->child->next->next->next->valuefloat;
							ii->posY = eChild->child->next->next->next->next->valuefloat;
							eft->info->insert(int_json::value_type(fc, ii));
						}
						eChild = eChild->next;
					}
					ff->insert(char_effect::value_type(key, eft));
					effect = effect->next;
				}
				ret->effect = ff;
				Json_dispose(effectChild);
			}
			else if(!strcmp(effectChild->name,"mask"))
			{
				ret->mask = effectChild->valueint;
				Json_dispose(effectChild);
			}
			else if(!strcmp(effectChild->name,"motion"))
			{
				Json *motion = effectChild->child;
				tt = new char_frame();
				while(motion)
				{
					CCString *key = CCString::create(motion->name);
					key->retain();
					int_json *ttBone = new int_json();
					Json *child2 = motion->child;
					while(child2)
					{
						int fc = atoi(child2->name);
						CCBoneJson *stTemp = new CCBoneJson();
						Json *boneChild = child2->child;
						stTemp->posX = boneChild->valuefloat;
						boneChild = boneChild->next;
						stTemp->posY = boneChild->valuefloat;
						boneChild = boneChild->next;
						stTemp->scaleX = boneChild->valuefloat;
						boneChild = boneChild->next;
						stTemp->scaleY = boneChild->valuefloat;
						boneChild = boneChild->next;
						stTemp->skewX = boneChild->valuefloat;
						boneChild = boneChild->next;
						stTemp->skewY = boneChild->valuefloat;
						boneChild = boneChild->next;
						stTemp->visable = boneChild->valuefloat;
						boneChild = boneChild->next;
						Json *color = boneChild->child;
						stTemp->colorRed = color->valuefloat;
						color = color->next;
						stTemp->colorGreen = color->valuefloat;
						color = color->next;
						stTemp->colorBlue = color->valuefloat;
						boneChild = boneChild->next;
						if(boneChild->valuestring && strlen(boneChild->valuestring) > 0)
						{
							int len = strlen(boneChild->valuestring);
							char *pic = new char[len+1];
							strcpy(pic, boneChild->valuestring);
							stTemp->pic = pic;
						}
						ttBone->insert(int_json::value_type(fc, stTemp));
						child2 = child2->next;
					}
					tt->insert(char_frame::value_type(key, ttBone));
					motion = motion->next;
				}
				ret->effectMotion = tt;
				Json_dispose(effectChild);
			}
			else if(!strcmp(effectChild->name,"order"))
			{
				ret->effectOrder = effectChild;
			}
			else
			{
				Json_dispose(effectChild);
			}
			effectChild = ne;
		}
	}
	return ret;
}

void CCBoneActionManager::clearBoneData(CCBoneActionData *data)
{
	Json_dispose(data->label);
	Json_dispose(data->skl);
	if(data->effectOrder)
	{
		Json_dispose(data->effectOrder);
	}
	if(data->effect)
	{
		if(data->effect->size())
		{
			char_effect::iterator iter;
			for (iter = data->effect->begin(); iter != data->effect->end();)
			{
				CC_SAFE_RELEASE(iter->first);
				if(iter->second->info)
				{
					if(iter->second->info->size() > 0)
					{
						int_json::iterator iter2;
						for (iter2 = iter->second->info->begin(); iter2 != iter->second->info->end();)
						{
							CC_SAFE_DELETE_ARRAY(iter2->second->pic);
							CC_SAFE_DELETE(iter2->second);
							iter->second->info->erase(iter2++);
						}
					}
				}
				CC_SAFE_DELETE(iter->second->info);
				CC_SAFE_DELETE(iter->second);
				data->effect->erase(iter++);
			}
		}
		CC_SAFE_DELETE(data->effect);
	}
	if(data->effectMotion)
	{
		if(data->effectMotion->size() > 0)
		{
			char_frame::iterator iter2;
			for (iter2 = data->effectMotion->begin(); iter2 != data->effectMotion->end();)
			{
				if(iter2->second->size() > 0)
				{
					int_json::iterator iter3;
					for (iter3 = iter2->second->begin(); iter3 != iter2->second->end();)
					{
						CC_SAFE_DELETE_ARRAY(iter3->second->pic);
						CC_SAFE_DELETE(iter3->second);
						iter2->second->erase(iter3++);
					}
				}
				CC_SAFE_RELEASE(iter2->first);
				CC_SAFE_DELETE(iter2->second);
				data->effectMotion->erase(iter2++);
			}
		}
		CC_SAFE_DELETE(data->effectMotion);
	}

	if(data->frame->size() > 0)
	{
		char_frame::iterator iter2;
		for (iter2 = data->frame->begin(); iter2 != data->frame->end();)
		{
			if(iter2->second->size() > 0)
			{
				int_json::iterator iter3;
				for (iter3 = iter2->second->begin(); iter3 != iter2->second->end();)
				{
					CC_SAFE_DELETE_ARRAY(iter3->second->pic);
					CC_SAFE_DELETE(iter3->second);
					iter2->second->erase(iter3++);
				}
			}
			CC_SAFE_RELEASE(iter2->first);
			CC_SAFE_DELETE(iter2->second);
			data->frame->erase(iter2++);
		}
	}
	CC_SAFE_DELETE(data->frame);
	CC_SAFE_DELETE(data);
}
CCBoneActionData *CCBoneActionManager::addAnimation(const char *name)
{
	CCString *key = CCString::create(name);
	char_Bone::iterator it = m_pAnimationData->find(key);
	key->retain();
	if (it != m_pAnimationData->end())
	{
		clearBoneData(it->second);
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

	Json *effectRoot = NULL;
	Json *source = Json_getItem(root, "effect");
	int isEffect = source->valueint;
	if(isEffect)
	{
		std::string actionName = std::string(name);
		actionName =  CCBoneSpriteConfig::getEffectUrl() + actionName +"effect.plist";
		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(actionName.c_str());
		path =  CCBoneSpriteConfig::getBoneUrl() + std::string(name) + ".effect";
		fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(path.c_str());
		size = 0;
		buffer = (char*)CCFileUtils::sharedFileUtils()->getFileData(fullPath.c_str(), "rt", &size);
		effectRoot = Json_create(buffer);
		CC_SAFE_DELETE_ARRAY(buffer);
	}
	CCBoneActionData *ret = processBoneData(root, effectRoot);
	m_pAnimationData->insert(char_Bone::value_type(key, ret));
	FREE(root);
	FREE(effectRoot);
	return ret;
}

CCBoneActionData *CCBoneActionManager::replaceAnimation(char *name)
{
	CCString *key = CCString::create(name);
	char_Bone::iterator it = m_pAnimationData->find(key);
	key->retain();
	if (it != m_pAnimationData->end())
	{
		key->release();
		return it->second;
	}
	return addAnimation(name);
}

void CCBoneActionManager::addAnimationAsync(char *name, CCCallFunc *callback)
{
	this->async(this, callfuncNDD_return_selector(CCBoneActionManager::addAnimationByAsync), NULL, name, NULL, callback);
}

CCBoneActionData *CCBoneActionManager::getAnimation(const char *name)
{
	CCAssert(name, "plist filename should not be NULL");
	CCBoneActionData *tmp = NULL;
	CCString *key = CCString::create(name);
	char_Bone::iterator it = m_pAnimationData->find(key);
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
/*
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
}*/
void CCBoneActionManager::purgeSharedCache()
{
	CC_SAFE_RELEASE_NULL(pSharedManager);
}
