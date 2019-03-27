 ///
 /// @file    Line.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-11-02 11:09:59
 ///
 
#ifndef __WD_LINE_H__
#define __WD_LINE_H__

//惯用的设计模式PIMPL
//1. 实现了信息隐藏
//2. 接口与实现分离, 能够保证接口的稳定性
//3. 降低编译依赖，加快编译速度
//4. 能够以最小的代价完成库的平滑升级

class Line
{
public:    //接口是要展示出来的
	Line(int, int, int, int);
	~Line();

	void printLine() const;

	class LinePimpl;// 类的前向声明
private:
	LinePimpl * _pimpl;
};

#endif
 
