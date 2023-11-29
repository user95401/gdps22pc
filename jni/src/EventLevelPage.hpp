#ifndef __EventLevelPage_H__
#define __EventLevelPage_H__
#include "includes.h"
using namespace cocos2d;
using namespace gd;
using namespace cocos2d::extension;

class EventLevelPage : public FLAlertLayer {
protected:
	virtual bool init();
	void onClose(cocos2d::CCObject*);
public:
	static EventLevelPage* create();
	const char* getEventTimeString();
};

#endif