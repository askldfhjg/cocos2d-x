#ifndef __BONE_ACTION_MANAGER_H__
#define __BONE_ACTION_MANAGER_H__
#include "Function.h"
#include "cocos2d.h"
#include "../../extensions/spine/Json.h"
USING_NS_CC;
using namespace cocos2d::extension;

struct ptrCmp
{
    bool operator()( const char * s1, const char * s2 ) const
    {
        return strcmp( s1, s2 ) < 0;
    }
};
typedef std::map<const char *, Json *, ptrCmp> char_json;

class CCBoneActionManager : public threadAsync
{
//luaµ¼³ö
public:
	static CCBoneActionManager* sharedManager(void);
	Json *addAnimation(char *name);
	Json *getAnimation(char *name);

public:
    bool init(void);
    ~CCBoneActionManager(void);

public:
	void addAnimationAsync(char *name, CCNode *target, SEL_CallFunc callback);
	void purgeSharedCache();
	

protected:
	Json *addAnimationByAsync(CCNode *target, void *data);

protected:
    CCBoneActionManager(void) {}

protected:
	char_json* m_pAnimationData;
};

#endif //__BONE_ACTION_MANAGER_H__