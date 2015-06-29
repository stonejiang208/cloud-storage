// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-06-29 12:11:39 by jiangtao> */

/* @file Test_Layer.cpp
 * $Id: Test_Layer.cpp 2015-06-29 03:40:50 jiangtao Exp $
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================


#include "Test_Layer.h"
#include "Cloud-Storage/Storage_Manager.h"
#include "Cloud-Storage/Utils.h"
#include "Cloud-Storage/Storage.h"


std::string Test_Layer::get_csb_filename()
{
	return "main/main.csb";
}

void Test_Layer::set_callbacks(Root_Node_Type * root_node)
{
  Widget* root = static_cast<Widget*>(root_node);
	{
		std::string node_name ="Button_1";
    auto node = static_cast<Button*> (Helper::seekWidgetByName(root, node_name));
    if (node)
    {
      node->addClickEventListener(CC_CALLBACK_1(Self::on_btn_quit, this));
     
    }
  }
  {
    std::string node_name ="Button_2";
    auto node = static_cast<Button*> (Helper::seekWidgetByName(root, node_name));
    if (node)
    {
      node->addClickEventListener(CC_CALLBACK_1(Self::on_btn_2, this));
      
    }
  }
  
  {
    std::string node_name ="Button_3";
    auto node = static_cast<Button*> (Helper::seekWidgetByName(root, node_name));
    if (node)
    {
      node->addClickEventListener(CC_CALLBACK_1(Self::on_btn_3, this));
      
    }
  }
  
  {
    std::string node_name ="Button_4";
    auto node = static_cast<Button*> (Helper::seekWidgetByName(root, node_name));
    if (node)
    {
      node->addClickEventListener(CC_CALLBACK_1(Self::on_btn_4, this));
      
    }
  }
  
  {
    std::string node_name ="Button_5";
    auto node = static_cast<Button*> (Helper::seekWidgetByName(root, node_name));
    if (node)
    {
      node->addClickEventListener(CC_CALLBACK_1(Self::on_btn_5, this));
      
    }
  }
  
  {
    std::string node_name ="TextField_1";
    auto node = static_cast<TextField*> (Helper::seekWidgetByName(root, node_name));
    auto s = node->getContentSize();
    
    EditBox* eb1 = EditBox::create (s,"Default/Button_Normal.png");
    auto p = node->getParent();
    p->addChild (eb1);
    eb1->setPosition (node->getPosition());
    eb1->setName("eb1");
    eb1->setDelegate(this);
    eb1->setFontColor (Color3B::BLACK);
    eb1_ = eb1;
    
  }
  
  {
    std::string node_name ="TextField_2";
    auto node = static_cast<TextField*> (Helper::seekWidgetByName(root, node_name));
    auto s = node->getContentSize();
    
    EditBox* eb = EditBox::create (s,"Default/Button_Normal.png");
    auto p = node->getParent();
    p->addChild (eb);
    eb->setPosition (node->getPosition());
    eb->setName("eb2");
    eb->setInputMode(EditBox::InputMode::NUMERIC);
    eb->setDelegate(this);
    eb->setFontColor (Color3B::BLACK);
    eb2_ = eb;

    
  }
  

}
#if 0
Test_Layer::CREATE_FUNC(Self)
{
}
#endif

void Test_Layer::on_btn_quit(Ref *)
{
  Storage_Manager::instance()->shutdown ();
  
  Director::getInstance()->end();
  
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
  exit(0);
#endif
}

void Test_Layer::on_btn_2(Ref *)
{
  CCLOG ("Test_Layer::on_btn_2");
  const char* text = eb1_->getText();
  if (strlen (text) > 0)
   {
     do_set_string(text);
   }
  
}

void Test_Layer::on_btn_3(Ref *)
{
  CCLOG ("Test_Layer::on_btn_3");
  const char* text = eb1_->getText();
  if (strlen (text) > 0)
  {
    do_set_int(text);
  }
  
  
}

void Test_Layer::on_btn_4(Ref *)
{
  CCLOG ("Test_Layer::on_btn_4");
  do_get_string();
  
}

void Test_Layer::on_btn_5(Ref *)
{
  CCLOG ("Test_Layer::on_btn_5");
  do_get_int ();
}


void Test_Layer::do_set_string(const char *text)
{
  Storage* s = Storage_Manager::instance()->get_storage();
  // s->set_float_value("level", 123.3f);
  
  unsigned long token = Utils::generate_token();
  CCLOG ("token = %zd",token);
  
  s->async_set_string_value(token, "name", text);
  
}

void Test_Layer::do_set_int (const char* text)
{
  
  Storage* s = Storage_Manager::instance()->get_storage();
  // s->set_float_value("level", 123.3f);
  
  unsigned long token = Utils::generate_token();
  CCLOG ("token = %zd",token);
  
  int score = atoi (text);
  s->async_set_int_value(token, "score", score);
  
}

void Test_Layer::do_get_int()
{
  Storage* s = Storage_Manager::instance()->get_storage();
  int value = s->get_int_value("score", 0);
  
  char text [80];
  sprintf (text, "%d",value);
  eb2_->setText(text);
}


void Test_Layer::do_get_string()
{
  Storage* s = Storage_Manager::instance()->get_storage();
  std::string value  = s->get_string_value("name", "");

  eb1_->setText(value.c_str());
}



void Test_Layer::editBoxReturn (EditBox* editBox)
{
  CCLOG ("Test_Layer::editBoxReturn");
  std::string name =  editBox->getName();
  const char* text =  editBox->getText();
  
  CCLOG ("Test_Layer::editBoxReturn [%s] [%s]",name.c_str(),text);
  
  if (strlen (text) > 0)
  {
    if (name == "eb1")
    {
      do_set_string (text);
    }
    else if (name == "eb2")
    {
      do_set_int (text);
    }
  }
  
}