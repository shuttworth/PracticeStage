#include <iostream>

using std::cout;
using std::endl;

struct Node
{
    int data;
    Node * pre;
    Node * next;
}; 

// 逆置一个单链表

// 逆置双向链表

class List
{
public:
    List()
    :_head(nullptr)
     ,_tail(nullptr)
     ,_size(0)
    {
        cout<<"List()"<<endl;
    }

    ~List()
    {
        if(_size!=0)
        {
            if(_head!=_tail)
            {
                _head=_head->next;
            }
        }
        cout<<"~List()"<<endl;
    }

    void push_back(int value)//在尾部添加数据
    {
        Node * tailnew = new Node();
        tailnew =_tail->next;
        tailnew->data=value;
        tailnew->pre=_tail;
        _tail=tailnew;
        _size++;
    }

    void push_front(int value)//在头部添加数据
    {
        Node * headnew = new Node(); 
           headnew= _head->pre;
        headnew->data = value;
        headnew ->next= _head;
        _head = headnew;
        _size++;
    }



    void pop_back()//在尾部删除一个数据
    {
        if(_tail!=_head)
        {
            Node * r= _tail;
            _tail=_tail->pre;
            _tail->next=nullptr;
            delete  r;
            _size--;
        }
    }


    void pop_front()//在头部删除一个数据
    {
        if(_tail!=_head)
        {
            Node * r= _head;
            _head = _head->next;
            _head->pre = nullptr;
            delete  r;
            _size--;
        }
    }



    void insert(Node *p, int value)//在某个节点之前添加数据, 还需要判断该节点在不在链表之中
    {
        if(find(p)!=nullptr)
        {
            Node * q=p->pre->next;
            q->pre=p->pre; 
            p->pre=q;
            q->next=p;
            q->data=value;
            _size++;
        }
        else cout<<"此节点不存在，无法插入"<<endl;
    }


    void erase(int data)//需要判断该节点在不在链表之中	 			 		
    {
        //改进，觉着可以使用到void find() 函数
        Node * look=_head;
        while(look->data!=data)
        {
            if(look==_tail){
                cout<<"该节点不在链表中"<<endl;
                break;
                //return--退出函数，while循环后面还有其他语句的话，直接跳过不会执行
            } 
            look=look->next;
        }
        if(look->data==data)
        {
            erase(look);
            _size--;
        }
    }
    


    void display() const//打印链表
    {
        Node * pass = _head;
        while(pass->next!=_tail->next)
        {
            cout<<pass->data<<"  ";
            pass=pass->next;
        }
        cout<<endl;
    }


    void find(int data)
    {
        Node * look=_head;
        while(look->data!=data)
        {
            if(look==_tail){
                cout<<"该节点不在链表中"<<endl;
                break;
                //return--退出函数，while循环后面还有其他语句的话，直接跳过不会执行
            } 
            look=look->next;
        }
        if(look->data==data)
        {
            cout<<"该节点在链表中"<<endl;
        }
    }

private:
    Node * find(Node * p)	//如果存在，就返回该节点；不存在，就返回空指针
    {
        Node * look=_head;
        while(p->data!=look->data)
        {
            if(look==_tail){
                return nullptr;
            //return--退出函数，while循环后面还有其他语句的话，直接跳过不会执行
            } 
            look=look->next;
        }
        return look;
    }

    Node * insert(Node *p);	//确定节点存在时，在该直接插入元素
    
    void erase(Node *p)			//删除一个指定的节点
    {
        p->pre->next=p->next;
        p->next->pre=p->pre;
        delete p;
    }


private:
    Node * _head;
    Node * _tail;
    int    _size;
};		


int main() //需要写测试应例
{
    return 0;
}

