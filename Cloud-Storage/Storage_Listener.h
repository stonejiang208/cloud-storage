// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-06-28 19:17:53 by jiangtao> */

/* @file Storage_Listener.h
 * $Id: Storage_Listener.h 2015-06-28 08:51:49 jiangtao 
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================

#ifndef STORAGE_LISTENER_H
#define STORAGE_LISTENER_H
#include <cstddef>

class Storage_Listener
{
public:	
	Storage_Listener ();
	virtual ~Storage_Listener ();
	virtual void on_system_msg (int msg_id) = 0;

	virtual void on_op_complete (unsigned long token, int result) = 0;

	virtual void on_get_int_complete (unsigned long token,
																		const char* field,
																		int v) = 0;

	virtual void on_get_float_complete (unsigned long token,
																			const char* field,
																			float v) = 0;

	virtual void on_get_string_complete (unsigned long token,
																			 const char* field,
																			 const char* v) = 0;

	virtual void on_find_data_complete (unsigned long token,
																			const char* key,
																			const char* dat_type,
																			const char* data,
																			size_t data_length) = 0;
};

#endif /* STORAGE_LISTENER_H */
