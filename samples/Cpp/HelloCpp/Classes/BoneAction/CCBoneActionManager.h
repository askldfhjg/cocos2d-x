#ifndef __BONE_ACTION_MANAGER_H__
#define __BONE_ACTION_MANAGER_H__
#include "Function.h"
#include "cocos2d.h"
#include "../../extensions/spine/Json.h"
USING_NS_CC;
using namespace cocos2d::extension;

struct ptrCmp
{
    bool operator()(CCString * s1, CCString * s2 ) const
    {
		return strcmp(s1->getCString(), s2->getCString()) < 0;
    }
};
typedef std::map<CCString *, Json *, ptrCmp> char_json;

class CCBoneActionManager : public threadAsync
{
//luaµ¼³ö
public:
	static CCBoneActionManager* sharedManager(void);
	Json *addAnimation(char *name);
	Json *getAnimation(char *name);
	Json *getEffectAnimation(char *name);

public:
    bool init(void);
    ~CCBoneActionManager(void);

public:
	void addAnimationAsync(char *name, CCCallFunc *callback);
	Json *replaceAnimation(char *name);
	void purgeSharedCache();
	

protected:
	char *addAnimationByAsync(CCNode *target, void *data1, void *data2);

protected:
    CCBoneActionManager(void) {}

protected:
	char_json* m_pAnimationData;
};

#endif //__BONE_ACTION_MANAGER_H__