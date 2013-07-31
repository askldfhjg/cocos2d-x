#ifndef __FFTABLEVIEWTESTSCENE_H__
#define __FFTABLEVIEWTESTSCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"


class TableViewTestLayer : public cocos2d::CCLayer, public cocos2d::extension::CCTableViewDataSource, public cocos2d::extension::CCTableViewDelegate
{
public:
	~TableViewTestLayer();
	virtual bool init(cocos2d::CCArray *list, cocos2d::CCNode *target, cocos2d::SEL_CallFuncO callback);  
    static TableViewTestLayer *create(cocos2d::CCArray *list, cocos2d::CCNode *target, cocos2d::SEL_CallFuncO callback);
    virtual void scrollViewDidScroll(cocos2d::extension::CCScrollView* view) {};
    virtual void scrollViewDidZoom(cocos2d::extension::CCScrollView* view) {}
    virtual void tableCellTouched(cocos2d::extension::CCTableView* table, cocos2d::extension::CCTableViewCell* cell);
    virtual cocos2d::CCSize tableCellSizeForIndex(cocos2d::extension::CCTableView *table, unsigned int idx);
    virtual cocos2d::extension::CCTableViewCell* tableCellAtIndex(cocos2d::extension::CCTableView *table, unsigned int idx);
    virtual unsigned int numberOfCellsInTableView(cocos2d::extension::CCTableView *table);
	void updateList(cocos2d::CCArray *list);

private:
	cocos2d::CCArray *list;
	cocos2d::CCNode *param1;
	cocos2d::SEL_CallFuncO selector;
};

#endif // __FFTABLEVIEWTESTSCENE_H__
