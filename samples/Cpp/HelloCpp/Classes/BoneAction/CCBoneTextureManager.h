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
//lua����
public:
	static CCBoneTextureManager* sharedManager(void);
	Json *addEquip(char *name);
	Json *getEquip(char *name);

public:
    bool init(void);
    ~CCBoneTextureManager(void);

public:
	void addEquipAsync(char *name, CCCallFunc *callback);
	void purgeSharedCache();
	

private:
	char *addTextureByAsync(CCNode *target, void *data1, void *data2);

protected:
    CCBoneTextureManager(void) {}

protected:
	char_json* m_pTextureData;
};

#endif //__BONE_TEXTURE_MANAGER_H__