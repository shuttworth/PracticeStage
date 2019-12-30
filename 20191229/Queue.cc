#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class queue
{
    private:
        int *_array;
        int _size;
        int _head;
        int _tail;

    public:
        queue(int size)
        :_array(new int[1]())
        ,_size(size)
         ,_head(0)
         ,_tail(0)
        { }

        bool empty() const
        {
            return _head==_tail;
        }

        bool full() const
        {
            return _head==(_tail+1)%_size;
        }

        void push(int number)
        {
            if(!full())
            {
                _array[++_tail]=number;
            }
            else cout<<"already full"<<endl;
        }

        void pop()
        {
            if(!empty())
            {
                ++_head;
            }
            else cout<<"already empty"<<endl;
        }

        void printhead()
        {
            cout<<"head="<<_array[_head]<<endl;
        }

        void printtail()
        {
            cout<<"tail="<<_array[_tail]<<endl;
        }



};

int main()
{
    queue qu1(8);
    qu1.pop();
    qu1.push(1);
    qu1.push(2);
    qu1.printhead();
    qu1.printtail();
    qu1.pop();
    qu1.printhead();

    return 0;
}

