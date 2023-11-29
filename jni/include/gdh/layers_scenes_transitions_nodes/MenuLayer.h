#ifndef __MENULAYER_H__
#define __MENULAYER_H__

#include "../gd.h"

	class FLAlertLayerProtocol;

	class MenuLayer : public cocos2d::CCLayer, public FLAlertLayerProtocol, public GooglePlayDelegate {
	public:
		static MenuLayer* node();
		static cocos2d::CCScene* scene(bool options) ;
		virtual bool init();
		virtual void keyBackClicked();
		virtual void keyDown(cocos2d::enumKeyCodes key) ;
		virtual void googlePlaySignedIn();
		virtual void FLAlert_Clicked(FLAlertLayer* alert, bool btn2);
		void onMoreGames(cocos2d::CCObject*);
		void onGarage(cocos2d::CCObject*);
		void onQuit(cocos2d::CCObject*);
		void onMyProfile(cocos2d::CCObject*);
		void onPlay(cocos2d::CCObject*);
		void onCreator(cocos2d::CCObject*);
		void onRobTop(cocos2d::CCObject*);
		void onNewgrounds(cocos2d::CCObject*);
		void onDaily(cocos2d::CCObject*);
		void onOptions(cocos2d::CCObject*);
		void onAchievements(cocos2d::CCObject*);
		void onStats(cocos2d::CCObject*);
		void onFacebook(cocos2d::CCObject*);
		void onTwitter(cocos2d::CCObject*);
		void onYouTube(cocos2d::CCObject*);
	};

	class CreatorLayer : public cocos2d::CCLayer {
	public:
		static CreatorLayer* create();
		virtual void sceneWillResume();
		virtual bool init();
		void onBack(cocos2d::CCObject*);
		void onOnlyFullVersion(cocos2d::CCObject*);
		void onChallenge(cocos2d::CCObject*);
		void onLeaderboards(cocos2d::CCObject*);
		void onMyLevels(cocos2d::CCObject*);
		void onSavedLevels(cocos2d::CCObject*);
		void onDailyLevel(cocos2d::CCObject*);
		void onWeeklyLevel(cocos2d::CCObject*);
		void onFeaturedLevels(cocos2d::CCObject*);
		void onFameLevels(cocos2d::CCObject*);
		void onMapPacks(cocos2d::CCObject*);
		void onOnlineLevels(cocos2d::CCObject*);
		void onGauntlets(cocos2d::CCObject*);
		void onSecretVault(cocos2d::CCObject*);
		void onTreasureRoom(cocos2d::CCObject*);
	};


#endif