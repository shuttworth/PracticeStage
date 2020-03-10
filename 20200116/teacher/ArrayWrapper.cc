///
/// @file    ArrayWrapper.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2020-01-16 17:20:40
///

#include <iostream>
using std::cout;
using std::endl;
class MetaData
{
public:
	MetaData(int size, const std::string &name)
	: name_(name)
	, size_(size)
	{	cout << "MetaData(int,string&)" << endl;}

	MetaData(const MetaData &other)
	: name_(other.name_)
	,size_(other.size_)
	{
		std::cout << "MetaData(const MetaData &other)" << std::endl;
	}

	MetaData(MetaData &&other)
	//: name_(other.name_) //调用复制构造函数
	: name_(std::move(other.name_))//std::move 将对象变成一个右值，但并不移动数据
	, size_(std::move(other.size_))
	{
		std::cout << "MetaData(MetaData &&other)" << std::endl;
	}

	std::string getName() const { return name_; }	

	int getSize() const { return size_; }

private:
	std::string name_;
	int size_;
};

class ArrayWrapper
{
public:
	ArrayWrapper()
	: pVals_(new int [64])
	, metadata_(64, "ArrayWrapper")
	{	cout << "ArrayWrapper()" << endl;	}

	ArrayWrapper(int n)
	: pVals_(new int[n])
	, metadata_(n, "ArrayWrapper")
	{	cout << "ArrayWrapper(int)" << endl;	}

	ArrayWrapper(const ArrayWrapper & other)
	: pVals_(new int[other.metadata_.getSize()])
	, metadata_(other.metadata_)
	{
		std::cout << "ArrayWrapper(const ArryWrapper &other)" << std::endl;
		for(int idx = 0; idx != other.metadata_.getSize(); ++idx)
		{
			pVals_[idx] = other.pVals_[idx];
		}
	}

	ArrayWrapper(ArrayWrapper && other)//移动构造函数
	: pVals_(other.pVals_)
	//, metadata_(other.metadata_)// 调用MetaData的复制构造函数
	, metadata_(std::move(other.metadata_))
	{
		std::cout << "ArrayWrapper(ArrayWrapper &&other)" << std::endl;
		other.pVals_ = NULL;
	}

	~ArrayWrapper()
	{
		delete [] pVals_;
	}

private:
	int * pVals_;//
	MetaData metadata_;
};

int main(void)
{
	ArrayWrapper aw1;

	ArrayWrapper aw2 = std::move(aw1);

	return 0;
}
