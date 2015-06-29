// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-06-28 18:57:48 by jiangtao> */

/* @file Storage_Protocol.h
 * $Id: Storage_Protocol.h 2015-06-27 10:25:55 jiangtao 
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================

#ifndef STORAGE_PROTOCOL_H
#define STORAGE_PROTOCOL_H
#include <string>
#include <cstddef>  //size_t

class Storage_Protocol
{
public:
	Storage_Protocol ();
	virtual ~Storage_Protocol ();

	virtual void set_int_value (const char* field,
															int v) = 0;
	virtual void async_set_int_value (unsigned long token,
																		const char* field,
																		int v) = 0;

	virtual int get_int_value (const char* field,
														 int dv) = 0;
	virtual void async_get_int_value (unsigned long token, const char* field, int dv) = 0;
	
 	virtual void set_float_value (const char* field, float v) = 0;
	virtual void async_set_float_value (unsigned long token, const char* field, float v) = 0;
	virtual float get_float_value (const char* field, float dv) = 0;
	virtual void async_get_float_value (unsigned long token, const char* field, float dv) = 0;

	virtual void set_string_value (const char* field,const std::string& v) = 0;
	virtual void async_set_string_value (unsigned long token,
																			 const char* field,
																			 const std::string& v) = 0;
	virtual std::string  get_string_value (
		const char* field, const std::string& dv) = 0;
	virtual void async_get_string_value (unsigned long token,
																			 const char* field,
																			 const std::string& dv) = 0;	


	virtual void async_store_data (unsigned long token,
																 const char* key,
																 const char* data_type,
																 const char* data,
																 size_t data_length) = 0;

	virtual void async_find_data (unsigned long token,
																const char* key) = 0;
};

#endif /* STORAGE_PROTOCOL_H */
