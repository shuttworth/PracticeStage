 ///
 /// @file    templateHeapSort.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-11-12 11:29:56
 ///
 
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;


template <typename T, typename Compare = std::less<T>>
class HeapSort
{
public:
	HeapSort(const vector<T> & data)
	: _data(data)
	{	cout << "size = " << _data.size() << endl;}

	void heapAdjust(int parent, int size)
	{
		int left = 2 * parent + 1;
		while(left < size) {
			if(left + 1 < size && _data[left] < _data[left + 1])
				++left;
			if(_data[parent] < _data[left]) {
				std::swap(_data[parent], _data[left]);
				parent = left;
				left = 2 * parent + 1;
			} else
				break;
		}
	}

	void sort()
	{
		int sz = _data.size();
		for(int idx = sz / 2 - 1; idx >= 0; --idx) 
		{
			heapAdjust(idx, sz);
		}

		for(; sz > 0; --sz) {
			std::swap(_data[0], _data[sz - 1]);
			heapAdjust(0, sz - 1);
		}
	}

	void display() const
	{
		auto rit = _data.rbegin();
		for(; rit != _data.rend(); ++rit)
			cout << *rit << " ";
		cout << endl;
	}

private:
	vector<T> _data;
};
 
int main(void)
{
	vector<int> numbers {4, 2, 5, 3, 1, 6, 7};
	HeapSort<int> hs(numbers);
	hs.sort();
	hs.display();

	return 0;
}
