#include "Function.h"
#include "pthread.h"
#include "cocos2d.h"
#include <queue>

USING_NS_CC;
using namespace std;

void  Func::itostr(int i, char *str)
{
	sprintf(str, "%d", i);
}

float Func::round(float r)
{
    return (r > 0.0) ? floor(r + 0.5) : ceil(r - 0.5);
}

//∂‡œﬂ≥Ã

bool threadAsync::need_quit = false;
pthread_t threadAsync::s_loadingThread;
pthread_mutex_t threadAsync::s_asyncInfoMutex;
pthread_mutex_t threadAsync::s_callbackMutex;
pthread_mutex_t threadAsync::s_SleepMutex;
pthread_cond_t threadAsync::s_SleepCondition;
unsigned long threadAsync::s_nAsyncRefCount = 0;
std::queue<asyncInfo*>* threadAsync::s_pAsyncInfoQueue = NULL;
std::queue<asyncInfo*>* threadAsync::s_pCallbackQueue = NULL;

void* threadAsync::loadAsync(void* data)
{
    asyncInfo *pAsyncStruct = NULL;

    while (true)
    {
        // create autorelease pool for iOS
        CCThread thread;
        thread.createAutoreleasePool();       

        queue<asyncInfo*> *pQueue = s_pAsyncInfoQueue;

        pthread_mutex_lock(&s_asyncInfoMutex);// get async struct from queue
        if (pQueue->empty())
        {
            pthread_mutex_unlock(&s_asyncInfoMutex);
            if (need_quit) {
                break;
            }
            else {
            	pthread_cond_wait(&s_SleepCondition, &s_SleepMutex);
                continue;
            }
        }
        else
        {
            pAsyncStruct = pQueue->front();
            pQueue->pop();
            pthread_mutex_unlock(&s_asyncInfoMutex);
        } 

		if (pAsyncStruct->target && pAsyncStruct->selector)
        {
			pAsyncStruct->spritePlist = ((pAsyncStruct->target)->*(pAsyncStruct->selector))(pAsyncStruct->param1, pAsyncStruct->param2, pAsyncStruct->param3);
        }

        pthread_mutex_lock(&s_callbackMutex);
        s_pCallbackQueue->push(pAsyncStruct);
        pthread_mutex_unlock(&s_callbackMutex); 
    }
    
	if( s_pAsyncInfoQueue != NULL )
    {
        delete s_pAsyncInfoQueue;
        s_pAsyncInfoQueue = NULL;
        delete s_pCallbackQueue;
        s_pCallbackQueue = NULL;

        pthread_mutex_destroy(&s_asyncInfoMutex);
        pthread_mutex_destroy(&s_callbackMutex);
        pthread_mutex_destroy(&s_SleepMutex);
        pthread_cond_destroy(&s_SleepCondition);
    }

    return 0;
}

void threadAsync::over()
{
	if(s_pAsyncInfoQueue != NULL && s_pAsyncInfoQueue->empty())
	{
		need_quit = true;
		pthread_cond_signal(&s_SleepCondition);
	}
}

void threadAsync::async(CCObject *target, SEL_CallFuncNDD_return selector, cocos2d::CCNode *param1, void *param2, void *param3, cocos2d::CCCallFunc *callback)
{
	if (s_pAsyncInfoQueue == NULL)
    {             
        s_pAsyncInfoQueue = new queue<asyncInfo*>();     
        s_pCallbackQueue = new queue<asyncInfo*>();          
        s_nAsyncRefCount = 0;
        pthread_mutex_init(&s_SleepMutex, NULL);
        pthread_cond_init(&s_SleepCondition, NULL);
        pthread_mutex_init(&s_asyncInfoMutex, NULL);
		pthread_mutex_init(&s_callbackMutex, NULL);
        pthread_create(&s_loadingThread, NULL, loadAsync, NULL);
    }

	need_quit = false;
    if (0 == s_nAsyncRefCount)
    {
        CCDirector::sharedDirector()->getScheduler()->scheduleSelector(schedule_selector(threadAsync::asyncCallBack), this, 0, false);
    }

    ++s_nAsyncRefCount;

	CC_SAFE_RETAIN(target);
	CC_SAFE_RETAIN(param1);
	CC_SAFE_RETAIN(callback);

    // generate async struct
    asyncInfo *data = new asyncInfo();
    data->target = target;
	data->param1 = param1;
	data->param2 = param2;
	data->param3 = param3;
    data->selector = selector;
	data->callback = callback;
	data->spritePlist = NULL;

    // add async struct into queue
    pthread_mutex_lock(&s_asyncInfoMutex);
    s_pAsyncInfoQueue->push(data);
    pthread_mutex_unlock(&s_asyncInfoMutex);

    pthread_cond_signal(&s_SleepCondition);
}

void threadAsync::asyncCallBack(float dt)
{
    // the image is generated in loading thread
    queue<asyncInfo*> *pQueue = s_pCallbackQueue;

    pthread_mutex_lock(&s_callbackMutex);
    if (pQueue->empty())
    {
        pthread_mutex_unlock(&s_callbackMutex);
    }
    else
    {
        asyncInfo *pAsyncStruct = pQueue->front();
        pQueue->pop();
        pthread_mutex_unlock(&s_callbackMutex);

		if(pAsyncStruct->spritePlist != NULL)
		{
			CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(pAsyncStruct->spritePlist);
		}

		if (pAsyncStruct->callback)
        {
			pAsyncStruct->callback->execute();
        }

		CC_SAFE_RELEASE(pAsyncStruct->target);
		CC_SAFE_RELEASE(pAsyncStruct->param1);
		CC_SAFE_RELEASE(pAsyncStruct->callback);
        delete pAsyncStruct;

        --s_nAsyncRefCount;
        if (0 == s_nAsyncRefCount)
        {
            CCDirector::sharedDirector()->getScheduler()->unscheduleSelector(schedule_selector(threadAsync::asyncCallBack), this);
        }
    }
}