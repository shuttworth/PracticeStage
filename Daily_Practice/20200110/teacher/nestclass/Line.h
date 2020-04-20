 ///
 /// @file    Line.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-10 16:19:19
 ///
 
#ifndef __WD_LINE_H__
#define __WD_LINE_H__

//封装, 只提供接口, 接口层
//
//设计模式之PIMPL
//1. 编译防火墙
//2. 可以实现信息隐藏
//3. 只要头文件不变，将程序以库的方式交给别人去使用时，
//   当库进行了升级时，不需要重新对源程序进行编译的,
//   可以平滑的升级库的版本
class Line
{
public:
	Line(int x1, int y1, int x2, int y2);
	~Line();

	void printLine() const;

	class LineImpl;

private:
	LineImpl * _pimpl;
};

#endif
