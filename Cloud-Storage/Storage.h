// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-06-29 10:12:56 by jiangtao> */

/* @file Storage.h
 * $Id: Storage.h 2015-06-25 13:39:16 jiangtao 
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================

#ifndef STORAGE_H
#define STORAGE_H
#include <string>

class Storage_Protocol;
class Storage
{
public:
	Storage ();
	virtual ~Storage ();

	void set_int_value (const char* field,int v);
	void async_set_int_value (unsigned long token, const char* field, int v);
	int get_int_value (const char* field, int dv);
	void async_get_int_value (unsigned long token, const char* field, int dv);

 	void set_float_value (const char* field, float v);
	void async_set_float_value (unsigned long token, const char* field, float v);
	float get_float_value (const char* field, float dv);
	void async_get_float_value (unsigned long token, const char* field, float dv);

	void set_string_value (const char* field,const std::string& v);
	void async_set_string_value (unsigned long token, const char* field, const std::string& v);
	std::string  get_string_value (const char* field, const std::string& dv);
	void async_get_string_value (unsigned long token,
															 const char* field, const std::string& dv);	
	
	void async_store_data (unsigned long token,
												 const char* key,
												 const char* data_type,
												 const char* data,
												 size_t data_length);

  void async_find_data (unsigned long token,
												const char* key);

public:
	int init (Storage_Protocol* impl);
	void shutdown ();

private:
	void error_msg(int error_code);
	Storage_Protocol* impl_;
};

#endif /* STORAGE_H */
