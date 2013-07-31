#ifndef __ACTION_LAYER_ACTION_H__
#define __ACTION_LAYER_ACTION_H__
#include "cocos2d.h"
USING_NS_CC;

enum BoneMotion{BoneMotionTypeNormal, BoneMotionTypeSlow};
class CCLayerAction : public CCActionInterval
{
public:
	CCLayerAction()
		:startFrame(NULL)
		,endFrame(NULL)
		,nowFrame(0)
		,nowStage(0)
		,totalStage(0)
		,totalFrameCount(0)
		,m_isDone(true)
		,actionTime(0)
		,action(NULL)
	{};
	~CCLayerAction(void);

    /** initializes the action */
    bool initWithFrame(const char *name, CCNode *node, double interval);

    /** returns true if the action has finished */
    virtual bool isDone(void);
	virtual void update(float frame);
	void startWithTarget(CCNode* pTarget);

public:
    /** creates the action */
    static CCLayerAction* create(const char *name, CCNode *node, double interval);
	static CCLayerAction* create(const char *name, CCFiniteTimeAction *layerMove, BoneMotion actionType, CCNode *node, double interval);
	static int obj;
protected:
	bool  m_isDone;

protected:
	int* startFrame;
	int* endFrame;
	int nowFrame;
	int nowStage;
	int totalStage;
	int totalFrameCount;
	float actionTime;
	CCAction *action;
};


#endif //__ACTION_LAYER_ACTION_H__
