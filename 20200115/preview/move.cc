#include <iostream>

using namespace std;

//1. 字符串的定义
class String {
public:
    String(const String &rhs) {   }
    String(String &&rhs) {
        s_ = rhs.s_;
        rhs.s_ = NULL;

    }
    String& operator=(const String &rhs) {   }
    String& operator=(String &&rhs) {
        if (this != &rhs) {
            delete [] s_;
            s_ = rhs.s_;
            rhs.s_ = NULL;

        }
        return *this;

    }
private:
    char *s_;

};

//2. std::move

#include <iostream>


class MetaData
{
public:
    MetaData(int size, const std::string &name)
        : name_(name)
          ,size_(size)
    {}

    MetaData(const MetaData &other)
        : name_(other.name_),
        size_(other.size_)
    {
        std::cout << "MetaData(const MetaData &other)" << std::endl;
    }


    MetaData(MetaData &&other)
       // : name_(other.name_) //调用复制构造函数
        : name_(std::move(other.name_))//std::move 将对象变成一个右值，但并不移动数据
        ,size_(std::move(other.size_))
    {
        std::cout << "MetaData(MetaData &&other)" << std::endl;
    }

    std::string getName() const { return name_;  }  

    int getSize() const { return size_;  }

private:
    std::string name_;
    int size_;
};

class ArrayWrapper
{
public:
    ArrayWrapper()
        : pVals_(new int [64]),
        metadata_(64, "ArrayWrapper")
    {}

    ArrayWrapper(int n)
        : pVals_(new int[n]),
        metadata_(n, "ArrayWrapper")
    {}

    ArrayWrapper(const ArrayWrapper &other)
        : pVals_(new int[other.metadata_.getSize()]),
        metadata_(other.metadata_)
    {
        std::cout << "ArrayWrapper(const ArryWrapper &other)" << std::endl;
        for(int idx = 0; idx != (int)sizeof(pVals_); ++idx)
        {
            pVals_[idx] = other.pVals_[idx];
        }
    }

    ArrayWrapper(ArrayWrapper &&other)//移动构造函数
        : pVals_(other.pVals_),
        //metadata_(other.metadata_)// 调用MetaData的复制构造函数
        metadata_(std::move(other.metadata_))
    {
        std::cout << "ArrayWrapper(ArrayWrapper &&other)" << std::endl;
        other.pVals_ = NULL;
    }

    ~ArrayWrapper()
    {
        delete []pVals_;
    }

private:
    int *pVals_;
    MetaData metadata_;
};




int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

