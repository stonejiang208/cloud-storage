// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-06-28 17:44:31 by jiangtao> */

/* @file My_Listener.cpp
 * $Id: My_Listener.cpp 2015-06-28 09:24:45 jiangtao Exp $
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================


#include "My_Listener.h"
#include "cocos2d.h"
USING_NS_CC;

My_Listener::My_Listener()
{
}

My_Listener::~My_Listener()
{
}

void My_Listener::on_system_msg(int msg_id)
{
  CCLOG ("My_Listener::on_system_msg (%d)",msg_id);
}

void My_Listener::on_op_complete(unsigned long token, int result)
{
	CCLOG ("My_Listener::on_op_complete (%zd,%d)",token,result);
  if (result != 0)
  {
    CCLOG ("on bad");
  }
}

void My_Listener::on_get_int_complete(unsigned long token,
																			const char * field, int v)
{
}

void My_Listener::on_get_float_complete(unsigned long token,
																				const char * field, float v)
{
  CCLOG ("My_Listener::on_get_float_complete (%zd,%s,%f)",token,field,v);
}

void My_Listener::on_get_string_complete(unsigned long token,
																				 const char * field, const char * v)
{
}

void My_Listener::on_find_data_complete (unsigned long token,
                            const char* key,
                            const char* data_type,
                            const char* data,
                            size_t data_length)
{
  CCLOG ("My_Listener::on_find_data_complete (%zd,%s,%s,[%s])",
         token,key,data_type,data);
}
