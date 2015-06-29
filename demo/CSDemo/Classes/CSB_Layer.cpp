// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-05 12:19:18 by jiangtao> */

/* @file CSB_Layer.cpp
 * $Id: CSB_Layer.cpp 2015-01-26 14:43:28 jiangtao Exp $
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================


#include "CSB_Layer.h"

#include "editor-support/cocostudio/ActionTimeline/CSLoader.h"
CSB_Layer::CSB_Layer()
	: root_ (nullptr)
{
	
}

CSB_Layer::~CSB_Layer()
{
	CC_SAFE_RELEASE (root_);
}


bool CSB_Layer::init()
{
	if (!Base::init ())
	{
		return false;
	}
	std::string filename = get_csb_filename ();
	Node* node = CSLoader::createNode (filename);
	if (!node)
	{
		return nullptr;
	}
  this->addChild (node);
	node->retain ();
	root_ = node;
	set_callbacks (root_);
  return  true;
}

