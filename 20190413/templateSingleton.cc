#include <iostream>
using std::cout;
using std::endl;


//实现模板模式单例的写法

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int=0,int=0)" << endl;
	}

	~Point()
	{	cout << "~Point()" << endl;	}

	void print() const 
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

private:
	int _ix;
	int _iy;
};

template <typename T>
class Singleton
{
public:
	template <typename... Args>
	static T * getInstance(Args... args) 
	{
		if(NULL == _pInstance) {
			_pInstance = new T(args...);
			_autoRelease;// 这一句不可少
		}
		return _pInstance;
	}

	class AutoRelease
	{
	public:
		AutoRelease(){	cout << "AutoRelease()" << endl;	}
		~AutoRelease() {
			if(_pInstance) {
				delete _pInstance;
			}
			cout << "~AutoRelease()" << endl;
		}
	};
private:
	Singleton() {}
	~Singleton() {}

private:
	static T * _pInstance;
	static AutoRelease _autoRelease;  //静态的private都要放在类之外进行初始化
};

template <typename T>
T * Singleton<T>::_pInstance = NULL;

template<typename T>
typename Singleton<T>::AutoRelease Singleton<T>::_autoRelease;
 
int main(void)
{
	Point * p1 = Singleton<Point>::getInstance(1, 2);
	Point * p2 = Singleton<Point>::getInstance(1, 2);
	Point * p3 = Singleton<Point>::getInstance(3, 4);

	cout << "p1 = " << p1 << endl
		 << "p2 = " << p2 << endl
		 << "p3 = " << p3 << endl;

	return 0;
}
