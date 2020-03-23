 ///通过继承自这个类来避免复制和赋值操作，因为基类的这俩函数被delete了
 
#ifndef __WD_NONCOPYABLE_H__
#define __WD_NONCOPYABLE_H__

namespace wd
{
class Noncopyable
{
protected:
	Noncopyable() {}
	~Noncopyable(){}

	Noncopyable(const Noncopyable &) = delete;
	Noncopyable & operator=(const Noncopyable &)=delete;
};
}//end of namespace wd

#endif
