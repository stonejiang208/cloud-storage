// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-06-28 17:43:32 by jiangtao> */

/* @file My_Listener.h
 * $Id: My_Listener.h 2015-06-28 09:24:38 jiangtao 
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================

#ifndef MY_LISTENER_H
#define MY_LISTENER_H

#include "Cloud-Storage/Storage_Listener.h"

class My_Listener
	: public Storage_Listener
{
public:
	My_Listener ();
	virtual ~My_Listener ();
public:
	virtual void on_system_msg (int msg_id);

	virtual void on_op_complete (unsigned long token, int result);

	virtual void on_get_int_complete (unsigned long token,
																		const char* field,
																		int v);

	virtual void on_get_float_complete (unsigned long token,
																			const char* field,
																			float v);

	virtual void on_get_string_complete (unsigned long token,
																			 const char* field,
																			 const char* v);

  virtual void on_find_data_complete (unsigned long token,
                                      const char* key,
                                      const char* data_type,
                                      const char* data,
                                      size_t data_length);
};

#endif /* MY_LISTENER_H */
