 ///
 /// @file    Task.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-02-09 16:04:45
 ///
 
#ifndef __WDTASK_H__
#define __WDTASK_H__

namespace wd
{
class Task
{
public:
	virtual
	void process()=0;

	virtual
	~Task(){}
};

}//end of namespace wd

#endif
