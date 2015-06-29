#include "HelloWorldScene.h"
#include "Cloud-Storage/Storage_Manager.h"
#include "Cloud-Storage/Utils.h"
#include "Cloud-Storage/Storage.h"
#include "ui/CocosGUI.h"
#include <unistd.h>

USING_NS_CC;

using namespace cocos2d::ui;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World cloud storage", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    // position the sprite on the center of the screen


    // add the sprite as a child to this layer

    Button* bt = Button::create ("HelloWorld.png");

    bt->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
  bt->addClickEventListener(CC_CALLBACK_1(HelloWorld::test, this));
  
		this->addChild (bt);
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
  
  Storage_Manager::instance()->shutdown ();

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::test (Ref*)
{
  CCLOG ("HelloWorld::test()");
  
  Storage* s = Storage_Manager::instance()->get_storage();
 // s->set_float_value("level", 123.3f);
  
  unsigned long token = Utils::generate_token();
  CCLOG ("token = %zd",token);
  
//  s->async_set_int_value(token,"score", 999);
  
 // int v = s->get_int_value ("score",0);
  
#if 0
  const char* mydata = "hello world 123";
  
  size_t n = strlen (mydata) + 1;
  
  s->async_store_data(token,
                      "mykey",
                      "string_data",
                      mydata,
                      n);
#endif
  
  // CCLOG ("score = %d",v);
  
 // s->async_get_float_value (token,"level",0.0f);
  
  s->async_find_data(token, "mykey");
}
