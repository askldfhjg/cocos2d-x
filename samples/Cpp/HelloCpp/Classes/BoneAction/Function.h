#ifndef __FUNCTION_H__
#define __FUNCTION_H__

#include "pthread.h"
#include <queue>
#include "cocos2d.h"


struct asyncInfo
{
	cocos2d::CCObject *target;
	cocos2d::CCNode *param1;
	void *param2;
	cocos2d::SEL_CallFuncND selector;
	cocos2d::CCCallFunc *callback;

};

class Func
{
public:
	static void itostr(int i, char *str);
	static float round(float r);

};

class threadAsync : public cocos2d::CCObject
{
public:
	void async(CCObject *target, cocos2d::SEL_CallFuncND selector, cocos2d::CCNode *param1, void *param2, cocos2d::CCCallFunc *callback);
	static void over();
	
private:
	void asyncCallBack(float dt);
	static pthread_t s_loadingThread;
	static pthread_mutex_t s_asyncInfoMutex;
	static pthread_mutex_t s_callbackMutex;
	static pthread_mutex_t s_SleepMutex;
	static pthread_cond_t s_SleepCondition;
	static unsigned long s_nAsyncRefCount;
	static void* loadAsync(void* data);
	static std::queue<asyncInfo*>* s_pAsyncInfoQueue;
	static std::queue<asyncInfo*>* s_pCallbackQueue;
	static bool need_quit;
};
#endif //__FUNCTION_H__