// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-06-29 11:48:12 by jiangtao> */

/* @file Test_Layer.h
 * $Id: Test_Layer.h 2015-06-29 03:40:44 jiangtao 
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================

#ifndef TEST_LAYER_H
#define TEST_LAYER_H
#include "CSB_Layer.h"
class Test_Layer
	: public CSB_Layer
  , public EditBoxDelegate
{
	typedef CSB_Layer Base;
	typedef Test_Layer Self;
public:
	virtual std::string get_csb_filename ();
	virtual void set_callbacks (Root_Node_Type* node);
	CREATE_FUNC (Self);
  virtual void editBoxReturn(EditBox* editBox);
protected:
	void on_btn_quit (Ref*);
	void on_btn_2 (Ref*);
  void on_btn_3 (Ref*);
  void on_btn_4 (Ref*);
  void on_btn_5 (Ref*);
  
private:
  void do_set_string (const char* text);
  void do_set_int (const char* text);
  
  void do_get_string();
  void do_get_int ();
  
private:
  EditBox* eb1_;
  EditBox* eb2_;
};

#endif /* TEST_LAYER_H */
