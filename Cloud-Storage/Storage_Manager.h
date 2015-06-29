// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-06-28 17:16:15 by jiangtao> */

/* @file Storage_Manager.h
 * $Id: Storage_Manager.h 2015-06-25 13:43:30 jiangtao 
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================

#ifndef STORAGE_MANAGER_H
#define STORAGE_MANAGER_H

#include "Cloud-Storage/Storage.h"
#include <string>
#include <memory>


class Storage_Manager_Impl;
class Storage_Listener;

class Storage_Manager
{
public:
	Storage_Manager ();
	virtual ~Storage_Manager ();
	int init (const std::string& writable_path,
						const std::string& address,
						unsigned short port);
	
	Storage* get_storage ();
	void start_create_storage ();
	int open ();

	int shutdown ();
	static Storage_Manager* instance ();
	static void destroy ();

	void set_listener (Storage_Listener* listener);
	Storage_Listener* get_listener();
	
private:
	std::shared_ptr<Storage_Manager_Impl>   impl_;
	static Storage_Manager*                instance_;
};



#endif /* STORAGE_MANAGER_H */
