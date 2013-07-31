#include "TableViewTestScene.h"

USING_NS_CC;
USING_NS_CC_EXT;

TableViewTestLayer *TableViewTestLayer::create(CCArray *list, CCNode *target, SEL_CallFuncO callback)
{
	TableViewTestLayer *pRet = new TableViewTestLayer();
	if (pRet && pRet->init(list, target, callback))
	{
		pRet->autorelease();
		return pRet; 
	}
	else
	{
		delete pRet;
		pRet = NULL;
		return NULL;
	}
}

TableViewTestLayer::~TableViewTestLayer()
{
	CC_SAFE_RELEASE(list);
}


bool TableViewTestLayer::init(CCArray *list, CCNode *target, SEL_CallFuncO callback)
{
    if ( !CCLayer::init() )
    {
        return false;
    }

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	this->list = list;
	this->param1 = target;
	this->selector = callback;
	this->list->retain();
	CCTableView *tableView = CCTableView::create(this, CCSizeMake(200, 250));
	tableView->setDirection(kCCScrollViewDirectionVertical);
	tableView->setPosition(ccp(0, 0));
	tableView->setAnchorPoint(ccp(0, 0));
	tableView->setDelegate(this);
	tableView->setTag(111);
	tableView->setVerticalFillOrder(kCCTableViewFillTopDown);
	this->addChild(tableView);
	tableView->reloadData();

    return true;
}

void TableViewTestLayer::tableCellTouched(CCTableView* table, CCTableViewCell* cell)
{
	CCString *string = (CCString *)list->objectAtIndex(cell->getIdx());
	CCLOG("cell touched at index: %i", cell->getIdx());
	((param1)->*(selector))(string);
}

CCSize TableViewTestLayer::tableCellSizeForIndex(CCTableView *table, unsigned int idx)
{
    return CCSizeMake(200, 30);
}

CCTableViewCell* TableViewTestLayer::tableCellAtIndex(CCTableView *table, unsigned int idx)
{
    CCString *string = (CCString *)list->objectAtIndex(idx);
    CCTableViewCell *cell = table->dequeueCell();
    if (!cell) {
        cell = new CCTableViewCell();
        cell->autorelease();
		CCLayerColor *ff = CCLayerColor::create(ccc4(255, 0, 0, 255), 200, 25);
        cell->addChild(ff);

        CCLabelTTF *label = CCLabelTTF::create(string->getCString(), "Helvetica", 20.0);
        label->setPosition(CCPointZero);
		label->setAnchorPoint(CCPointZero);
        label->setTag(123);
        cell->addChild(label);
    }
    else
    {
        CCLabelTTF *label = (CCLabelTTF*)cell->getChildByTag(123);
        label->setString(string->getCString());
    }
    return cell;
}

unsigned int TableViewTestLayer::numberOfCellsInTableView(CCTableView *table)
{
	int ttt = this->list->count();
	return ttt;
}

void TableViewTestLayer::updateList(cocos2d::CCArray *list)
{
	this->list = list;
	CCTableView *view = (CCTableView *)this->getChildByTag(111);
	view->reloadData();
}
