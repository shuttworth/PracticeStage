#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

//本代码段通过运算符重载和嵌套类charproxy实现将读和写分开
class String
{
	class CharProxy
	{
	public:
		CharProxy(String & self, int idx) //传 字符串本身、字符串下标过来
		: _self(self)
		, _idx(idx)
		{}

		char & operator=(char ch);

		friend std::ostream & operator<<(std::ostream & os, const CharProxy & rhs);  //输入流运算符的重载
	private:
		String & _self;
		int _idx;
	};
	friend std::ostream & operator<<(std::ostream & os, const String::CharProxy & rhs);
	friend std::ostream & operator<<(std::ostream & os, const String & rhs);
public:
	String()
	: _pstr(new char[5]() + 4)
	{
		initRefcount();
	}
	String(const char * pstr)
	: _pstr(new char[strlen(pstr) + 5]() + 4)
	{
		strcpy(_pstr, pstr);
		initRefcount();
	}
	String(const String & rhs)
	: _pstr(rhs._pstr)
	{
		increaseRefcount();
	}

	~String()
	{
		release();
	}

	void release()
	{
		decreaseRefcount();
		if(refcount() == 0) {
			delete [] (_pstr - 4);
			cout << ">>> delete data" << endl;
		}
	}

	String & operator=(const String & rhs) 
	{
		cout << "String & operator=(const String &)" << endl;
		if(this != & rhs) {//1. 自复制
			release();// 2. 释放左操作的空间
			_pstr = rhs._pstr;//3. 改变指向
			increaseRefcount();
		}
		return *this;
	}


	const char * c_str() const
	{	return _pstr;	}

	int refcount() const
	{	return *reinterpret_cast<int *>(_pstr - 4); }

	int size() const 
	{	return strlen(_pstr);	}

	//问题: 下标访问运算符不知道接下来要做的是读操作，还是写操作, 无法区分
#if 0
	char & operator[](int idx)
	{
		static char nullchar = '\0';
		if(idx < 0 || idx >= size())
		{
			cout << ">>> idx 越界" << endl;
			return nullchar;
		} else {
			if(refcount() > 1) {
				decreaseRefcount();	
				char * ptmp = new char[size() + 5]() + 4;
				strcpy(ptmp, _pstr);
				_pstr = ptmp;
				initRefcount();
			}
			return _pstr[idx];
		}
	}
#endif
	CharProxy operator[](int idx)
	{
		return CharProxy(*this, idx);
	}
private:
	//inline
	void initRefcount() //函数名是具有语义的
	{
		*reinterpret_cast<int *>(_pstr - 4) = 1;
	}
	
	void increaseRefcount()
	{
		++*reinterpret_cast<int *>(_pstr - 4);
	}

	void decreaseRefcount()
	{
		--*reinterpret_cast<int *>(_pstr - 4);
	}


private:
	char * _pstr;
};
 
std::ostream & operator<<(std::ostream & os, const String & rhs)
{
	os << rhs._pstr;
	return os;
}

char & String::CharProxy::operator=(char ch)  //CharProxy类型的operator,_self是定义的string类型
{
	static char nullchar = '\0';
	if(_idx < 0 || _idx >= _self.size())
	{
		cout << ">>> idx 越界" << endl;
		return nullchar;
	} else {
		if(_self.refcount() > 1) {  //如果引用计数大于1，进行生拷贝
			_self.decreaseRefcount();	
			char * ptmp = new char[_self.size() + 5]() + 4;
			strcpy(ptmp, _self._pstr);
			_self._pstr = ptmp;
			_self.initRefcount();//对新开的空间进行初始化
		}
		_self._pstr[_idx] = ch;//进行写操作
		return _self._pstr[_idx];
	}
}

//输出流运算符
std::ostream & operator<<(std::ostream & os, const String::CharProxy & rhs)
{
	os << rhs._self._pstr[rhs._idx];
	return os;
}


int main(void)
{
	String s1 = "hello,world";
	String s2 = s1;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	printf("s1's address: %p\n", s1.c_str());
	printf("s2's address: %p\n", s2.c_str());
	cout << "s1' refcount = " << s1.refcount() << endl;
	cout << "s2' refcount = " << s2.refcount() << endl << endl;

	String s3 = "wangdao";
	String s4(s3);
	cout << "s3 = " << s3 << endl;
	cout << "s4 = " << s4 << endl;
	s2 = s3;
	cout << "执行赋值操作:" << endl;
	cout << "s2 = " << s2 << endl;
	printf("s3's address: %p\n", s3.c_str());
	printf("s2's address: %p\n", s2.c_str());
	printf("s4's address: %p\n", s4.c_str());

	cout << "s3' refcount = " << s3.refcount() << endl;
	cout << "s2' refcount = " << s2.refcount() << endl;
	cout << "s4' refcount = " << s4.refcount() << endl << endl;


	s3[0] = 'X';
	cout << "执行写操作:" << endl;

	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s4 = " << s4 << endl;
	printf("s3's address: %p\n", s3.c_str());
	printf("s2's address: %p\n", s2.c_str());
	printf("s4's address: %p\n", s4.c_str());
	cout << "s3' refcount = " << s3.refcount() << endl;
	cout << "s2' refcount = " << s2.refcount() << endl;
	cout << "s4' refcount = " << s4.refcount() << endl << endl;

	cout << "执行读操作:" << endl;
	cout << "s2[0] = " << s2[0] << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s4 = " << s4 << endl;
	printf("s3's address: %p\n", s3.c_str());
	printf("s2's address: %p\n", s2.c_str());
	printf("s4's address: %p\n", s4.c_str());
	cout << "s3' refcount = " << s3.refcount() << endl;
	cout << "s2' refcount = " << s2.refcount() << endl;
	cout << "s4' refcount = " << s4.refcount() << endl << endl;

	return 0;
}
