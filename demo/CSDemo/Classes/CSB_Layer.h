// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-05 12:18:47 by jiangtao> */

/* @file CSB_Layer.h
 * $Id: CSB_Layer.h 2015-01-26 14:43:20 jiangtao 
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================

#ifndef CSB_LAYER_H
#define CSB_LAYER_H

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include <string>
USING_NS_CC;
using namespace cocos2d::ui;
class CSB_Layer
	: public Layer
{
	typedef CSB_Layer Self;
	typedef Layer Base;	
public:
  typedef Node Root_Node_Type;
	CSB_Layer ();
	virtual ~CSB_Layer ();
	virtual std::string get_csb_filename() = 0;
	virtual void set_callbacks (Root_Node_Type*) = 0;
	virtual bool init ();
protected:
	Root_Node_Type* root_;
private:
	
};

#endif /* CSB_LAYER_H */
