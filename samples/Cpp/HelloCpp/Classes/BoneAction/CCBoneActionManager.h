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

struct CCBoneJson
{
	float posX;
	float posY;
	float scaleX;
	float scaleY;
	float skewX;
	float skewY;
	float visable;
	float colorRed;
	float colorGreen;
	float colorBlue;
	char *pic;
};
typedef std::map<int, CCBoneJson*> int_json;
struct CCEffectJson
{
	float posX;
	float posY;
	float archX;
	float archY;
	float width;
	float height;
	int_json *info;
};
typedef std::map<CCString*, CCEffectJson*, ptrCmp> char_effect;
typedef std::map<CCString*, int_json*, ptrCmp> char_frame;
struct CCBoneActionData
{
	Json *label;
	Json *skl;
	char_frame *frame;
	int mask;
	char_effect *effect;
	Json *effectOrder;
	char_frame *effectMotion;
};

typedef std::map<CCString *, Json *, ptrCmp> char_json;
typedef std::map<CCString *, CCBoneActionData*, ptrCmp> char_Bone;

class CCBoneActionManager : public threadAsync
{
//luaµ¼³ö
public:
	static CCBoneActionManager* sharedManager(void);
	CCBoneActionData *addAnimation(const char *name);
	CCBoneActionData *getAnimation(const char *name);
	//Json *getEffectAnimation(const char *name);

public:
    bool init(void);
    ~CCBoneActionManager(void);

public:
	void addAnimationAsync(char *name, CCCallFunc *callback);
	CCBoneActionData *replaceAnimation(char *name);
	void purgeSharedCache();
	

protected:
	char *addAnimationByAsync(CCNode *target, void *data1, void *data2);
	CCBoneActionData *processBoneData(Json *root, Json *effectRoot);
	void clearBoneData(CCBoneActionData *data);

protected:
    CCBoneActionManager(void) {}

protected:
	char_Bone* m_pAnimationData;
};

#endif //__BONE_ACTION_MANAGER_H__