#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "ace/Init_ACE.h"
#include "ace/Log_Msg.h"
#include <vector>
#include <string>
using namespace std;

#include "Cloud-Storage/Service.h"

#include "Cloud-Storage/Storage_Manager.h"

#include "Test_Layer.h"

#define ADDRESS "192.168.1.9"
#define PORT_NUM 2809

USING_NS_CC;


AppDelegate::AppDelegate()
{
  Cloud_Storage::init ();
  CCLOG ("App Start here.");
  FileUtils* fu = FileUtils::getInstance();
  std::string wp  = fu->getWritablePath();
  Storage_Manager::instance()->init(wp,ADDRESS,PORT_NUM);
  
  listener_ = new My_Listener();
  
  Storage_Manager::instance()->set_listener(listener_);
  
  Storage_Manager::instance()->open ();
}

AppDelegate::~AppDelegate() 
{
  
  Storage_Manager::destroy();
  delete listener_;
  Cloud_Storage::fini ();
  
   CCLOG ("App end here.");
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

// If you want to use packages manager to install more packages, 
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::create("My Game");
        director->setOpenGLView(glview);
    }

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    register_all_packages();


		    Size my_designResolutionSize;
		vector<string> searchPath;

		my_designResolutionSize = Size (1136, 640);
		searchPath.push_back ( "iPhone5");
		glview->setDesignResolutionSize(
			my_designResolutionSize.width,
			my_designResolutionSize.height,
		 ResolutionPolicy::SHOW_ALL);

		
    // set searching path
		FileUtils::getInstance()->setSearchPaths(searchPath);

		
    // create a scene. it's an autorelease object
  auto scene =  Scene::create ();
  scene->addChild(Test_Layer::create());
    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
