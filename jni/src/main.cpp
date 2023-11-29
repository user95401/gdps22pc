#include "includes.h"
#include "EventLevelPage.hpp"


class CreatorLayerMod : public CreatorLayer {
public:
    void onMultiplayer(cocos2d::CCObject*) {
    }
    void onEventLevel(cocos2d::CCObject* pSender) {
        EventLevelPage* alert = EventLevelPage::create();
        alert->m_bNoElasticity = true;//HJfod
        alert->show();
    }
};
CreatorLayer* CreatorLayerFromInit;
void addclbtn(const char* name, cocos2d::SEL_MenuHandler sus, const CCPoint& pos, CCMenu* menu) {
    CCSprite* btn = CCSprite::createWithSpriteFrameName(name);
    btn->setScale(0.8f);
    auto btnItem = CCMenuItemSpriteExtra::create(btn, btn, CreatorLayerFromInit, sus);
    btnItem->setPosition(pos);
    menu->addChild(btnItem);
}
bool(*CreatorLayer_init)(CreatorLayer*);
bool CreatorLayer_init_H(CreatorLayer* self) {
    if (!CreatorLayer_init(self)) return false;
    CreatorLayerFromInit = self;
    CCMenu* menu = (CCMenu*)self->getChildren()->objectAtIndex(1);
    if (true){//menu->getChildrenCount() == 2) {
        menu->removeChild((CCNode*)menu->getChildren()->objectAtIndex(0), true);
        menu->removeChild((CCNode*)menu->getChildren()->objectAtIndex(0), true);
        menu->removeChild((CCNode*)menu->getChildren()->objectAtIndex(0), true);
        menu->removeChild((CCNode*)menu->getChildren()->objectAtIndex(0), true);
        menu->removeChild((CCNode*)menu->getChildren()->objectAtIndex(0), true);
        menu->removeChild((CCNode*)menu->getChildren()->objectAtIndex(0), true);
        menu->removeChild((CCNode*)menu->getChildren()->objectAtIndex(0), true);
        menu->removeChild((CCNode*)menu->getChildren()->objectAtIndex(0), true);
        menu->removeChild((CCNode*)menu->getChildren()->objectAtIndex(0), true);
        menu->removeChild((CCNode*)menu->getChildren()->objectAtIndex(0), true);
        menu->removeChild((CCNode*)menu->getChildren()->objectAtIndex(0), true);
        //row1
        addclbtn("GJ_createBtn_001.png", menu_selector(CreatorLayer::onMyLevels), { -180,90 }, menu);
        addclbtn("GJ_savedBtn_001.png", menu_selector(CreatorLayer::onSavedLevels), { -90,90 }, menu);
        addclbtn("GJ_highscoreBtn_001.png", menu_selector(CreatorLayer::onLeaderboards), { 0,90 }, menu);
        addclbtn("GJ_challengeBtn_001.png", menu_selector(CreatorLayer::onChallenge), { 90,90 }, menu);
        addclbtn("GJ_versusBtn_001.png", menu_selector(CreatorLayer::onOnlyFullVersion), { 180,90 }, menu);
        //row2
        addclbtn("GJ_mapBtn_001.png", menu_selector(CreatorLayer::onOnlyFullVersion), { -180,0 }, menu);
        addclbtn("GJ_dailyBtn_001.png", menu_selector(CreatorLayer::onDailyLevel), { -90,0 }, menu);
        addclbtn("GJ_weeklyBtn_001.png", menu_selector(CreatorLayer::onWeeklyLevel), { 0,0 }, menu);
        addclbtn("GJ_eventBtn_001.png", menu_selector(CreatorLayerMod::onEventLevel), { 90,0 }, menu);
        addclbtn("GJ_gauntletsBtn_001.png", menu_selector(CreatorLayer::onGauntlets), { 180,0 }, menu);
        //row3
        addclbtn("GJ_featuredBtn_001.png", menu_selector(CreatorLayer::onFeaturedLevels), { -180,-90 }, menu);
        addclbtn("GJ_listsBtn_001.png", menu_selector(CreatorLayer::onOnlyFullVersion), { -90,-90 }, menu);
        addclbtn("GJ_pathsBtn_001.png", menu_selector(CreatorLayer::onOnlyFullVersion), { 0,-90 }, menu);
        addclbtn("GJ_mapPacksBtn_001.png", menu_selector(CreatorLayer::onMapPacks), { 90,-90 }, menu);
        addclbtn("GJ_searchBtn_001.png", menu_selector(CreatorLayer::onOnlineLevels), { 180,-90 }, menu);
    }
    return true;
}
class MenuLayerMod {
public:
    void onTwitch(cocos2d::CCObject* pSender) {
        CCApplication::sharedApplication()->openURL("http://gdps22pc.cxgame.ru/"); //"https://www.twitch.tv/robtopgames");
    }
    void onDiscord(cocos2d::CCObject* pSender) {
        CCApplication::sharedApplication()->openURL("https://discord.gg/hC9JsVE7Pc");//"https://discord.com/invite/geometrydash"); 
    }
    void onPlay(cocos2d::CCObject* pSender) {
        /* auto scene = CCScene::create();
        scene->addChild(LevelSelectLayer::create(1));
        CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.5f, scene)); */
    }
    void onUpdateHttpResponse(CCHttpClient* client, CCHttpResponse* response) {
        std::vector<char>* responseData = response->getResponseData();
        std::string responseString(responseData->begin(), responseData->end());
        if (responseString != "1.11.2-android1") {
            AchievementNotifier::sharedState()->notifyAchievement("Update available!", ("You can download actual " + responseString + " version on the website.").c_str(), "GJ_downloadsIcon_001.png", true);
        }
    }
};
bool(*MenuLayer_init)(MenuLayer*);
bool MenuLayer_init_H(MenuLayer* self) {
    if (!MenuLayer_init(self)) return false;

    //_ModsResources
    CCTextureCache::sharedTextureCache()->addImage("_ModsResources.png", 0);
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("_ModsResources.plist");

    CCSize winSize = CCDirector::sharedDirector()->getWinSize();

    //self->runAction(CCSequence::create(CCDelayTime::create(0.1f), CCCallFuncO::create(self, callfuncO_selector(MenuLayerMod::termsOfUseLayerShow), self), nullptr));

    auto versionLabel = CCLabelBMFont::create("1.11.2-android1", "chatFont.fnt");
    versionLabel->setAlignment(CCTextAlignment::kCCTextAlignmentRight);
    versionLabel->setPosition({ winSize.width, 0 });
    versionLabel->setAnchorPoint({ 1.0f, 0 });
    versionLabel->setOpacity({ 130 });
    versionLabel->setScale({ 0.5f });
    self->addChild(versionLabel);
    auto fadeTo200 = CCFadeTo::create(5, 200);
    auto fadeTo130 = CCFadeTo::create(5, 130);
    auto versionLabelseq = CCSequence::create(fadeTo200, fadeTo130, nullptr);
    auto versionLabelrepeat = CCRepeatForever::create(versionLabelseq);
    versionLabel->runAction(versionLabelrepeat);

    //udate if sddso herer
    CCHttpRequest* request = new CCHttpRequest;
    request->setUrl("http://gdps22pc.cxgame.ru/lastAndroidUpdate.php");
    request->setRequestType(CCHttpRequest::HttpRequestType::kHttpPost);
    request->setResponseCallback(self, httpresponse_selector(MenuLayerMod::onUpdateHttpResponse));
    CCHttpClient::getInstance()->send(request);
    request->release(); 

    auto gdps22goldtxt_menu = CCMenu::create(); //// MENU MENU MENU MENU MENU MENU MENU MENU MENU MENU MENU MENU MENU
    auto gdps22goldtxt = CCMenuItemLabel::create(CCLabelBMFont::create("private server 2.2", "goldFont.fnt"), self, nullptr);
    gdps22goldtxt->setPosition({ (winSize.width / 2) + 50, winSize.height - 82 }); ///// / / SET ITEM POSSSS
    gdps22goldtxt_menu->addChild(gdps22goldtxt); /////ADDD ITEM IN TOO MENU ^^^^^^^^^^^^^^^^^^^^^
    gdps22goldtxt_menu->setPosition({ 0, 0 }); /////WHY THE FUCK I MUST SET IT?!?!?!?!?!?
    self->addChild(gdps22goldtxt_menu, 100);

    auto user666_siteIcon_001 = CCSprite::createWithSpriteFrameName("user666_siteIcon_001.png");//gj_twitchIcon_001.png");
    auto twitchbutton = CCMenuItemSpriteExtra::create(
        user666_siteIcon_001,
        user666_siteIcon_001,
        self,
        menu_selector(MenuLayerMod::onTwitch)
    );
    twitchbutton->setPosition({ 0, 38 });

    auto discord = CCSprite::createWithSpriteFrameName("gj_discordIcon_001.png");
    auto discordbutton = CCMenuItemSpriteExtra::create(
        discord,
        discord,
        self,
        menu_selector(MenuLayerMod::onDiscord)
    );
    discordbutton->setPosition({0, 0});

    auto menu = CCMenu::create();
    menu->addChild(twitchbutton);
    menu->addChild(discordbutton);
    menu->setPosition({ 112, 23.6 });
    menu->setAnchorPoint({ 0, 0 });
    menu->setScale({ 0.82 });

    self->addChild(menu);

    return true;
}
#include "customLayerxd.hpp"
GJDropDownLayer* (*_ZN12SupportLayer6createEv)();
GJDropDownLayer* _ZN12SupportLayer6createEv_H() {
    GJDropDownLayer* DropDown = GJDropDownLayer::create("help out", 240.f);
    auto winSize = CCDirector::sharedDirector()->getWinSize();

    auto menuInLtopBtns = CCMenu::create();
    menuInLtopBtns->setPosition({ 35, winSize.height - 105 });
    DropDown->m_pLayer->addChild(menuInLtopBtns);

    //creaditsLnk
    auto creditsLnk = CCMenuItemSpriteExtra::create(
        CCSprite::createWithSpriteFrameName("communityCreditsBtn_001.png"),
        CCSprite::createWithSpriteFrameName("communityCreditsBtn_001.png"),
        menuInLtopBtns,
        menu_selector(customLayerxd::openURLcredits)
    );
    menuInLtopBtns->addChild(creditsLnk);

    menuInLtopBtns->alignItemsVerticallyWithPadding(8);

    auto txt1 = CCLabelBMFont::create("Hi, if u have some problems or questions -\nall of it on discord server!\n\n\n\n\n\n\n\n", "chatFont.fnt");
    txt1->setPosition({ winSize.width / 2, winSize.height / 2 });
    txt1->setScale(0.8f);
    txt1->setAlignment(kCCTextAlignmentCenter);
    DropDown->m_pLayer->addChild(txt1);

    CCSprite* developersLabel = CCSprite::createWithSpriteFrameName("developersLabel.png");
    developersLabel->setPosition({ winSize.width / 2, winSize.height / 2 });
    DropDown->m_pLayer->addChild(developersLabel);

    //links
    auto linksMenu = CCMenu::create();

    auto user666_siteIcon_001 = CCSprite::createWithSpriteFrameName("user666_siteIcon_001.png");
    auto openURLbtn = CCMenuItemSpriteExtra::create(
        user666_siteIcon_001,
        user666_siteIcon_001,
        linksMenu,
        menu_selector(customLayerxd::openURL)
    );
    linksMenu->addChild(openURLbtn);

    auto gj_discordIcon_001 = CCSprite::createWithSpriteFrameName("gj_discordIcon_001.png");
    auto discord_openURLbtn = CCMenuItemSpriteExtra::create(
        gj_discordIcon_001,
        gj_discordIcon_001,
        linksMenu,
        menu_selector(customLayerxd::discord_openURL)
    );
    linksMenu->addChild(discord_openURLbtn);

    auto user666_vkIcon_001 = CCSprite::createWithSpriteFrameName("user666_vkIcon_001.png");
    auto vk_openURLbtn = CCMenuItemSpriteExtra::create(
        user666_vkIcon_001,
        user666_vkIcon_001,
        linksMenu,
        menu_selector(customLayerxd::vk_openURL)
    );
    linksMenu->addChild(vk_openURLbtn);

    auto gj_ytIcon_001 = CCSprite::createWithSpriteFrameName("gj_ytIcon_001.png");
    auto yt_openURLbtn = CCMenuItemSpriteExtra::create(
        gj_ytIcon_001, gj_ytIcon_001,
        linksMenu,
        menu_selector(customLayerxd::yt_openURL)
    );
    linksMenu->addChild(yt_openURLbtn);

    auto _gjBtn = CCSprite::create("_gjBtn.png");
    auto _gjBtnbtn = CCMenuItemSpriteExtra::create(
        _gjBtn, _gjBtn,
        linksMenu,
        menu_selector(customLayerxd::gamejolt_openURL)
    );
    linksMenu->addChild(_gjBtnbtn);

    linksMenu->setPosition({ winSize.width / 2, 82 });
    linksMenu->alignItemsHorizontallyWithPadding(5);
    DropDown->m_pLayer->addChild(linksMenu);

    return DropDown;
}

void CreateGameLayersHooks() {
    HOOK("_ZN9MenuLayer4initEv", MenuLayer_init_H, MenuLayer_init);
    HOOK("_ZN12SupportLayer6createEv", _ZN12SupportLayer6createEv_H, _ZN12SupportLayer6createEv);
    HOOK("_ZN12CreatorLayer4initEv", CreatorLayer_init_H, CreatorLayer_init);
}

void(* GameObject_customSetup)(GameObject*);
void GameObject_customSetup_H(GameObject* self) {
    GameObject_customSetup(self);
    
    if (self->m_textureName.find("pixelart_") != self->m_textureName.npos) {//any pixel art
        self->m_objectType = kGameObjectTypeDecoration;
    }
    if (self->m_textureName.find("blockPiece_") != self->m_textureName.npos) {//any blockPiece
        self->m_objectType = kGameObjectTypeDecoration;
    }
    if (self->m_textureName.find("Bloque_Pixel") != self->m_textureName.npos) {//any blockPiece
        self->m_objectType = kGameObjectTypeDecoration;
    }

}
/* void(* EditorUI_setupCreateMenu)(EditorUI*);
void EditorUI_setupCreateMenu_H(EditorUI* self) {

    //tab0(blocks)
    if (auto tab0 = (EditButtonBar*)(self->m_pCreateButtonBars->objectAtIndex(0))) {
        tab0->m_pButtonArray->addObject(self->getCreateBtn(4003, 4));//"Bloque_Pixel_01_1_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(4004, 4));//"Bloque_Pixel_01_2_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(4005, 4));//"Bloque_Pixel_01_3_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(4006, 4));//"Bloque_Pixel_01_4_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(4007, 4));//"Bloque_Pixel_02_1_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(4008, 4));//"Bloque_Pixel_02_2_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(4009, 4));//"Bloque_Pixel_02_3_001.png");
        
        tab0->m_pButtonArray->addObject(self->getCreateBtn(4010, 4));//"Bloque_Pixel_03_1_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(4011, 4));//"Bloque_Pixel_03_2_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(4012, 4));//"Bloque_Pixel_03_3_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(4013, 4));//"Bloque_Pixel_03_4_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(4014, 4));//"Bloque_Pixel_03_5_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(4015, 4));//"Bloque_Pixel_03_6_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(4016, 4));//"Bloque_Pixel_03_7_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(4017, 4));//"Bloque_Pixel_03_8_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(4018, 4));//"Bloque_Pixel_03_9_001.png");

        tab0->m_pButtonArray->addObject(self->getCreateBtn(4019, 4));//"Bloque_Pixel_03_10_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(4020, 4));//"Bloque_Pixel_03_11_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(4021, 4));//"Bloque_Pixel_03_12_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(4022, 4));//"Bloque_Pixel_03_13_001.png");

        tab0->m_pButtonArray->addObject(self->getCreateBtn(1964, 4));//"blockPiece_001_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(1965, 4));//"blockPiece_002_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(1966, 4));//"blockPiece_003_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(1967, 4));//"blockPiece_004_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(1968, 4));//"blockPiece_005_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(1969, 4));//"blockPiece_006_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(1970, 4));//"blockPiece_007_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(1971, 4));//"blockPiece_008_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(1972, 4));//"blockPiece_009_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(1973, 4));//"blockPiece_010_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(1974, 4));//"blockPiece_011_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(1975, 4));//"blockPiece_012_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(1976, 4));//"blockPiece_013_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(1977, 4));//"blockPiece_014_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(1978, 4));//"blockPiece_015_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(1979, 4));//"blockPiece_016_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(1980, 4));//"blockPiece_017_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(1981, 4));//"blockPiece_018_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(1982, 4));//"blockPiece_019_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(1983, 4));//"blockPiece_020_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(1984, 4));//"blockPiece_021_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(1985, 4));//"blockPiece_022_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(1986, 4));//"blockPiece_023_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(1987, 4));//"blockPiece_024_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(1988, 4));//"blockPiece_small_001_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(1989, 4));//"blockPiece_small_002_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(1990, 4));//"blockPiece_small_003_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(1991, 4));//"blockPiece_small_004_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(1992, 4));//"blockPiece_small_005_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(1993, 4));//"blockPiece_small_006_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(1994, 4));//"blockPiece_small_007_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(1995, 4));//"blockPiece_small_008_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(1996, 4));//"blockPiece_small_009_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(1997, 4));//"blockPiece_small_010_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(1998, 4));//"blockPiece_small_011_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(1999, 4));//"blockPiece_small_012_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(2000, 4));//"blockPiece_small_013_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(2001, 4));//"blockPiece_small_014_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(2002, 4));//"blockPiece_small_015_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(2003, 4));//"blockPiece_small_016_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(2004, 4));//"blockPiece_small_017_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(2005, 4));//"blockPiece_small_018_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(2006, 4));//"blockPiece_small_019_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(2007, 4));//"blockPiece_small_020_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(2008, 4));//"blockPiece_small_021_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(2009, 4));//"blockPiece_small_022_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(2010, 4));//"blockPiece_small_023_001.png");
        tab0->m_pButtonArray->addObject(self->getCreateBtn(2011, 4));//"blockPiece_small_024_001.png");
        tab0->reloadItemsInNormalSize();
    }
    //tab6
    if (auto tab6 = (EditButtonBar*)(self->m_pCreateButtonBars->objectAtIndex(6))) {
        tab6->m_pButtonArray->insertObject(self->getCreateBtn(3005, 4), 4);//spider pad
        tab6->m_pButtonArray->insertObject(self->getCreateBtn(3004, 4), 13);//spider orb
        tab6->m_pButtonArray->insertObject(self->getCreateBtn(2926, 4), 17);//green portal
        tab6->reloadItemsInNormalSize();
    }
    //tab11 (triggrers)
    if(auto tab11 = (EditButtonBar*)(self->m_pCreateButtonBars->objectAtIndex(11))){
        tab11->m_pButtonArray->removeObjectAtIndex(4);
        tab11->m_pButtonArray->insertObject(self->getCreateBtn(2701, 5), 4);//stop
        tab11->m_pButtonArray->insertObject(self->getCreateBtn(2702, 5), 5);//stop
        tab11->m_pButtonArray->insertObject(self->getCreateBtn(2067, 5), 11);//scale
        tab11->m_pButtonArray->insertObject(self->getCreateBtn(1912, 5), 20);//random
        tab11->m_pButtonArray->insertObject(self->getCreateBtn(2068, 5), 21);//adv random
        tab11->m_pButtonArray->insertObject(self->getCreateBtn(1913, 4), 22);//zoom
        tab11->m_pButtonArray->insertObject(self->getCreateBtn(1914, 5), 23);//zoom
        tab11->m_pButtonArray->insertObject(self->getCreateBtn(1916, 5), 24);//offset
        tab11->m_pButtonArray->insertObject(self->getCreateBtn(1917, 4), 25);//reverse
        tab11->m_pButtonArray->insertObject(self->getCreateBtn(1934, 4), 26);//song
        tab11->m_pButtonArray->insertObject(self->getCreateBtn(915, 4), 27);//yo
        tab11->m_pButtonArray->insertObject(self->getCreateBtn(1931, 4), 38);//end
        tab11->m_pButtonArray->insertObject(self->getCreateBtn(1932, 5), 39);//stopJump
        tab11->reloadItemsInNormalSize();
    }

    EditorUI_setupCreateMenu(self);
    
}
 */void ApplyObjectHooks() {
    //HOOK("_ZN10GameObject11customSetupEv", GameObject_customSetup_H, GameObject_customSetup);
    //HOOK("_ZN8EditorUI15setupCreateMenuEv", EditorUI_setupCreateMenu_H, EditorUI_setupCreateMenu);
    
    ObjectToolbox::sharedState()->addObject(3004, "spiderRing_001.png");
    ObjectToolbox::sharedState()->addObject(3005, "spiderBump_001.png");
    ObjectToolbox::sharedState()->addObject(2926, "portal_19_unity_001.png");

    ObjectToolbox::sharedState()->addObject(1964, "blockPiece_001_001.png");
    ObjectToolbox::sharedState()->addObject(1965, "blockPiece_002_001.png");
    ObjectToolbox::sharedState()->addObject(1966, "blockPiece_003_001.png");
    ObjectToolbox::sharedState()->addObject(1967, "blockPiece_004_001.png");
    ObjectToolbox::sharedState()->addObject(1968, "blockPiece_005_001.png");
    ObjectToolbox::sharedState()->addObject(1969, "blockPiece_006_001.png");
    ObjectToolbox::sharedState()->addObject(1970, "blockPiece_007_001.png");
    ObjectToolbox::sharedState()->addObject(1971, "blockPiece_008_001.png");
    ObjectToolbox::sharedState()->addObject(1972, "blockPiece_009_001.png");
    ObjectToolbox::sharedState()->addObject(1973, "blockPiece_010_001.png");
    ObjectToolbox::sharedState()->addObject(1974, "blockPiece_011_001.png");
    ObjectToolbox::sharedState()->addObject(1975, "blockPiece_012_001.png");
    ObjectToolbox::sharedState()->addObject(1976, "blockPiece_013_001.png");
    ObjectToolbox::sharedState()->addObject(1977, "blockPiece_014_001.png");
    ObjectToolbox::sharedState()->addObject(1978, "blockPiece_015_001.png");
    ObjectToolbox::sharedState()->addObject(1979, "blockPiece_016_001.png");
    ObjectToolbox::sharedState()->addObject(1980, "blockPiece_017_001.png");
    ObjectToolbox::sharedState()->addObject(1981, "blockPiece_018_001.png");
    ObjectToolbox::sharedState()->addObject(1982, "blockPiece_019_001.png");
    ObjectToolbox::sharedState()->addObject(1983, "blockPiece_020_001.png");
    ObjectToolbox::sharedState()->addObject(1984, "blockPiece_021_001.png");
    ObjectToolbox::sharedState()->addObject(1985, "blockPiece_022_001.png");
    ObjectToolbox::sharedState()->addObject(1986, "blockPiece_023_001.png");
    ObjectToolbox::sharedState()->addObject(1987, "blockPiece_024_001.png");

    ObjectToolbox::sharedState()->addObject(1988, "blockPiece_small_001_001.png");
    ObjectToolbox::sharedState()->addObject(1989, "blockPiece_small_002_001.png");
    ObjectToolbox::sharedState()->addObject(1990, "blockPiece_small_003_001.png");
    ObjectToolbox::sharedState()->addObject(1991, "blockPiece_small_004_001.png");
    ObjectToolbox::sharedState()->addObject(1992, "blockPiece_small_005_001.png");
    ObjectToolbox::sharedState()->addObject(1993, "blockPiece_small_006_001.png");
    ObjectToolbox::sharedState()->addObject(1994, "blockPiece_small_007_001.png");
    ObjectToolbox::sharedState()->addObject(1995, "blockPiece_small_008_001.png");
    ObjectToolbox::sharedState()->addObject(1996, "blockPiece_small_009_001.png");
    ObjectToolbox::sharedState()->addObject(1997, "blockPiece_small_010_001.png");
    ObjectToolbox::sharedState()->addObject(1998, "blockPiece_small_011_001.png");
    ObjectToolbox::sharedState()->addObject(1999, "blockPiece_small_012_001.png");
    ObjectToolbox::sharedState()->addObject(2000, "blockPiece_small_013_001.png");
    ObjectToolbox::sharedState()->addObject(2001, "blockPiece_small_014_001.png");
    ObjectToolbox::sharedState()->addObject(2002, "blockPiece_small_015_001.png");
    ObjectToolbox::sharedState()->addObject(2003, "blockPiece_small_016_001.png");
    ObjectToolbox::sharedState()->addObject(2004, "blockPiece_small_017_001.png");
    ObjectToolbox::sharedState()->addObject(2005, "blockPiece_small_018_001.png");
    ObjectToolbox::sharedState()->addObject(2006, "blockPiece_small_019_001.png");
    ObjectToolbox::sharedState()->addObject(2007, "blockPiece_small_020_001.png");
    ObjectToolbox::sharedState()->addObject(2008, "blockPiece_small_021_001.png");
    ObjectToolbox::sharedState()->addObject(2009, "blockPiece_small_022_001.png");
    ObjectToolbox::sharedState()->addObject(2010, "blockPiece_small_023_001.png");
    ObjectToolbox::sharedState()->addObject(2011, "blockPiece_small_024_001.png");

    ObjectToolbox::sharedState()->addObject(4003, "Bloque_Pixel_01_1_001.png");
    ObjectToolbox::sharedState()->addObject(4004, "Bloque_Pixel_01_2_001.png");
    ObjectToolbox::sharedState()->addObject(4005, "Bloque_Pixel_01_3_001.png");
    ObjectToolbox::sharedState()->addObject(4006, "Bloque_Pixel_01_4_001.png");
    ObjectToolbox::sharedState()->addObject(4007, "Bloque_Pixel_02_1_001.png");
    ObjectToolbox::sharedState()->addObject(4008, "Bloque_Pixel_02_2_001.png");
    ObjectToolbox::sharedState()->addObject(4009, "Bloque_Pixel_02_3_001.png");
    
    ObjectToolbox::sharedState()->addObject(4010, "Bloque_Pixel_03_1_001.png");
    ObjectToolbox::sharedState()->addObject(4011, "Bloque_Pixel_03_2_001.png");
    ObjectToolbox::sharedState()->addObject(4012, "Bloque_Pixel_03_3_001.png");
    ObjectToolbox::sharedState()->addObject(4013, "Bloque_Pixel_03_4_001.png");
    ObjectToolbox::sharedState()->addObject(4014, "Bloque_Pixel_03_5_001.png");
    ObjectToolbox::sharedState()->addObject(4015, "Bloque_Pixel_03_6_001.png");
    ObjectToolbox::sharedState()->addObject(4016, "Bloque_Pixel_03_7_001.png");
    ObjectToolbox::sharedState()->addObject(4017, "Bloque_Pixel_03_8_001.png");
    ObjectToolbox::sharedState()->addObject(4018, "Bloque_Pixel_03_9_001.png");

    ObjectToolbox::sharedState()->addObject(4019, "Bloque_Pixel_03_10_001.png");
    ObjectToolbox::sharedState()->addObject(4020, "Bloque_Pixel_03_11_001.png");
    ObjectToolbox::sharedState()->addObject(4021, "Bloque_Pixel_03_12_001.png");
    ObjectToolbox::sharedState()->addObject(4022, "Bloque_Pixel_03_13_001.png");

    ObjectToolbox::sharedState()->addObject(2701, "edit_eStopMoverBtn_001.png");//stop
    ObjectToolbox::sharedState()->addObject(2702, "edit_eStopMoverBtn_001.png");//stop
    ObjectToolbox::sharedState()->addObject(2067, "edit_eScaleComBtn_001.png");//scale
    ObjectToolbox::sharedState()->addObject(1912, "edit_eRandomBtn_001.png");//random
    ObjectToolbox::sharedState()->addObject(2068, "edit_eRandomBtn_001.png");//adv random
    ObjectToolbox::sharedState()->addObject(1913, "edit_eZoomBtn_001.png");//zoom
    ObjectToolbox::sharedState()->addObject(1914, "edit_eStaticBtn_001.png");//zoom / Static
    ObjectToolbox::sharedState()->addObject(1916, "edit_eOffsetBtn_001.png");//offset
    ObjectToolbox::sharedState()->addObject(1917, "edit_eReverseBtn_001.png");//reverse
    ObjectToolbox::sharedState()->addObject(1934, "edit_eSongBtn_001.png");//song
    ObjectToolbox::sharedState()->addObject(915, "edit_eTimeWarpBtn_001.png");//timeWarp
    ObjectToolbox::sharedState()->addObject(1930, "edit_eEndBtn_001.png");//end
    ObjectToolbox::sharedState()->addObject(1931, "edit_eEndBtn_001.png");//end
    ObjectToolbox::sharedState()->addObject(1932, "edit_eStopJumpBtn_001.png");//stopJump
}

void ApplyHooks() {
  CreateGameLayersHooks();
  ApplyObjectHooks();
}

void ApplyPatches() {
	PatchManager tmp;
	//tmp.addPatch("libcocos2dcpp.so", 0x20CDD8, "00 BF");
	//many thanks to Wyliemaster <3
	//tmp.addPatch("libcocos2dcpp.so", 0x322EBE, "0C"); //songid_bypass
	//tmp.addPatch("libcocos2dcpp.so", 0x2153CE, "0B"); //rated_small_anticheat
	tmp.Modify();
}

void loader() {
	ApplyHooks();
	ApplyPatches();
}

//starter
JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved)
{
	loader();
	return JNI_VERSION_1_6;
}   

