#include <iostream>
#include <memory>
#include <algorithm>
using std::cout;
using std::endl;


//用allocator来实现vector
template <typename T>
class Vector
{
public:
	typedef T * iterator;

	Vector()
	: _start(0)
	, _finish(0) //内容的尽头
	, _end_of_storage(0) //空间的尽头
	{}

	T * begin() 
	{	return _start;	}

	T * end()
	{	return _finish;	}

	void push_back(const T & value);

	void pop_back();
	
	size_t size() const
	{	return  _finish - _start;	}

	size_t capacity() const
	{	return _end_of_storage - _start;	}

private:
	void reallocate();//扩容

private:
	static std::allocator<T> _alloc;
	T * _start;
	T * _finish;
	T * _end_of_storage;
};

template <typename T>
std::allocator<T> Vector<T>::_alloc;

template <typename T>
void Vector<T>::push_back(const T & value) 
{
	if(size() == capacity())
		reallocate();
	
	_alloc.construct(_finish++, value);
}

template <typename T>
void Vector<T>::pop_back()
{
	if(size() > 0) {
		_alloc.destroy(--_finish);
	}	
}

template <typename T>
void Vector<T>::reallocate()
{
	size_t oldCapacity = capacity();
	size_t newCapacity = oldCapacity > 0 ? oldCapacity * 2 : 1;

	T * ptmp = _alloc.allocate(newCapacity);

	if(size() > 0) {
		//std::copy(_start, _finish, ptmp);	
		std::uninitialized_copy(_start, _finish, ptmp);

		while(_start != _finish)
			_alloc.destroy(--_finish);

		_alloc.deallocate(_start, oldCapacity);
	}
	_start = ptmp;
	_finish = _start + oldCapacity;
	_end_of_storage = _start + newCapacity;
}

void display(Vector<int> & vec)
{
	cout << "vec's size = " << vec.size() << endl;
	cout << "vec's capacity = " << vec.capacity() << endl;
}
 
int main(void)
{
	Vector<int> myvec;

	myvec.push_back(1);
	display(myvec);
	myvec.push_back(2);
	display(myvec);
	myvec.push_back(3);
	display(myvec);
	myvec.push_back(4);
	display(myvec);
	myvec.push_back(5);
	display(myvec);
	myvec.push_back(6);
	display(myvec);

	cout << endl;

	Vector<int>::iterator it = myvec.begin();
	for(; it != myvec.end(); ++it) 
		cout << *it << " ";
	cout << endl;
}
