#include <iostream>
using std::cout;
using std::endl;

class Data
{
private:
        int _data;
public:
    Data(int data=0)  // 这里对内置data初始化，使得测试应例直接写Data()，没有任何问题
    :_data(data)
    {
        cout<<"Data()"<<endl;
    }
        
        
    int getData()  const
    {
        return _data;
    }
};  


class MiddleLayer
{
private:
    Data * _pdata;

public:
    MiddleLayer(Data * pdata)
        :_pdata(pdata)
    {
        cout<<" MiddleLayer(Data * pdata)"<<endl;
    }

    Data * operator->()
    {
        return _pdata;
    }


    ~MiddleLayer()
    {
        if(_pdata)
        {
            delete _pdata;
        }
    }
};


int main(void)
{

    MiddleLayer ml(new Data(10));
    cout<<ml->getData()<<endl; //ml本身是个对象
    return 0;
}

