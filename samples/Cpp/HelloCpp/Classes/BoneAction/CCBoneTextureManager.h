#ifndef __BONE_TEXTURE_MANAGER_H__
#define __BONE_TEXTURE_MANAGER_H__
#include "Function.h"
#include "CCBoneActionManager.h"
#include "cocos2d.h"
#include "../../extensions/spine/Json.h"
USING_NS_CC;
using namespace cocos2d::extension;

class CCBoneTextureManager : public threadAsync
{
//luaµ¼³ö
public:
	static CCBoneTextureManager* sharedManager(void);
	Json *addEquip(char *name);
	Json *getEquip(char *name);
	Json *addSkl(char *name);
	Json *getSkl(char *name);

public:
    bool init(void);
    ~CCBoneTextureManager(void);

public:
	void addSklAsync(char *name, CCCallFunc *callback);
	void addEquipAsync(char *name, CCCallFunc *callback);
	void purgeSharedCache();
	

private:
	Json *addTextureByAsync(CCNode *target, void *data);
	std::string getTextureName(char *name);

protected:
    CCBoneTextureManager(void) {}

protected:
	char_json* m_pTextureData;
};

#endif //__BONE_TEXTURE_MANAGER_H__