#include <iostream>

using std::cout;
using std::endl;
using std::cin;

struct Node
{
    Node(int data = 0, Node *pPre = nullptr, Node *pNext = nullptr)
    :_data(data)
    ,_pPre(pPre)
    ,_pNext(pNext)
    {
        cout << "Node(int, Node *, Node *)" << endl;
    }

    ~Node()
    {
        cout << "~Node()" << endl;
    }

    int _data;
    Node *_pPre;
    Node *_pNext;
};

class LinkList
{
public:
    LinkList()
    :_pHead(new Node())
    ,_pTail(new Node())
    ,_size(0)
    {
        cout << "LinkList()" << endl;
        _pHead->_pNext = _pTail;
        _pTail->_pPre = _pHead;
    }

    ~LinkList()
    {
        cout << "~LinkList()" << endl;

        Node *deleteNode = _pHead->_pNext;
        while (deleteNode)
        {
            Node *deleteNext = deleteNode->_pNext;
            delete deleteNode;
            deleteNode = deleteNext;
        }
        delete _pHead;
        _pHead = nullptr;
    }

    void pushFront(int data)
    {
        Node *newNode = new Node(data);
        _pHead->_pNext->_pPre = newNode;
        newNode->_pNext = _pHead->_pNext;
        newNode->_pPre = _pHead;
        _pHead->_pNext = newNode;
        ++_size;
    }

    void pushBack(int data)
    {
        Node *newNode = new Node(data);
        newNode->_pPre = _pTail->_pPre;
        _pTail->_pPre->_pNext = newNode;
        newNode->_pNext = _pTail;
        _pTail->_pPre = newNode;
        ++_size;
    }
    
    //在头部删除一个元素
    void popFront()
    {
        if(size() > 0)
        {
            Node *p = _pHead->_pNext;
            p->_pNext->_pPre = _pHead;
            _pHead->_pNext = p->_pNext;
            delete p;
            --_size;
        }
        else
        {
            cout << "链表为空,无法删除" << endl;
        }
    }
    
    //在尾部删除一个元素
    void popBack()
    {
        if (size() != 0)
        {
            Node *pNode = _pTail->_pPre;
            pNode->_pPre->_pNext = _pTail;
            _pTail->_pPre = pNode->_pPre;
            /* _pTail->_pPre->_pPre->_pNext = _pTail; */
            /* _pTail->_pPre = _pTail->_pPre->_pPre; */
            delete pNode;
            --_size;

        }
        else
        {
            cout << "链表为空,无法删除" << endl;
        }
    }

    void display() const
    {
        if(size() > 0)
        {
            Node *p = _pHead->_pNext;
            cout << "链表之中的节点为: " << endl;
            while(p  && p != _pTail)
            {
                cout << p->_data << " ";
                p = p->_pNext;
            }
            cout << endl;
        }
        else
        {
            cout << "链表为空，没有元素可以打印" << endl;
        }
    }

    size_t size() const
    {
        return _size;
    }

    void find(int data)
    {
        Node *pNode = _pHead->_pNext;
        while (pNode && pNode != _pTail)
        {
            if (pNode->_data == data)
            {
                cout << "该节点在链表之中" << endl;
                return;
            }

            pNode = pNode->_pNext;
        }
        
        cout << "该节点不在链表之中" << endl;
        return;
    }
    
    //在某个节点之前添加数据，还需要判断该节点在不在链表之中
    void insert(Node *pNode, int value)
    {
        Node *pTmp = find(pNode);
        if (nullptr == pTmp)
        {
            cout << "该节点在链表中不存在,无法插入" << endl;
            return;
        }

        Node *newNode = new Node(value);
        newNode->_pNext = pNode;
        newNode->_pPre = pNode->_pPre;
        pNode->_pPre->_pNext = newNode;
        pNode->_pPre = newNode;
        ++_size;
    }

    //需要判断该节点在不在链表之中
    void erase(int data)
    {
        Node *pNode = _pHead->_pNext;
        while (pNode && pNode != _pTail)
        {
            if (data == pNode->_data)
            {
                cout << "链表中有这个元素，可以删除" << endl;
                pNode->_pPre->_pNext = pNode->_pNext;
                pNode->_pNext->_pPre = pNode->_pPre;
                delete pNode;
                --_size;
                return;
            }
            pNode = pNode->_pNext;
        }

        cout << "链表中没有这个元素，无法删除" << endl;
    }

    Node *getHead()
    {
        return _pHead;
    }

    Node *getTail()
    {
        return _pTail;
    }
private:
    Node *find(Node *p)
    {
        if(size() > 0)
        {
            Node *pNode = _pHead->_pNext;
            //while(pNode && pNode != _pTail)
            while (pNode != _pTail)
            {
                if (p == pNode)
                {
                    return p;
                }

                pNode = pNode->_pNext;
            }
            return nullptr;
        }
        else
        {
            cout << "链表为空，无法查找元素" << endl;
            return nullptr;
        }
    }

    /* Node *insert(Node *pNode); */

    /* void erase(Node *p); */
private:
    Node *_pHead;
    Node *_pTail;
    size_t _size;
};

void test()
{
    LinkList lst;
    cout << "在头部添加三个元素，1,2,3" << endl;
    lst.pushFront(1);
    lst.pushFront(2);
    lst.pushFront(3);
    lst.display();

    cout << endl;
    cout << "在尾部添加三个元素，4,5,6" << endl;
    lst.pushBack(4);
    lst.pushBack(5);
    lst.pushBack(6);
    lst.display();

    cout << endl;
    cout << "在头部删除一个元素: " << endl;
    lst.popFront();
    lst.display();

    cout << endl;
    cout << "在尾部删除一个元素: " << endl;
    lst.popBack();
    lst.display();

    cout << endl;
    cout << "在头部再删除一个元素: " << endl;
    lst.popFront();
    lst.display();

    cout << endl;
    cout << "在尾部再删除一个元素: " << endl;
    lst.popBack();
    lst.display();

    cout << endl;
    cout << "查找节点在不在链表之中: " << endl;
    int number = 0;
    cout << "请输入节点: " << endl;
    cin >> number;
    lst.find(number);
    lst.display();

    cout << endl;
    cout << "删除节点在不在链表之中: " << endl;
    cout << "请输入节点: " << endl;
    cin >> number;
    lst.erase(number);
    lst.display();

    cout << endl;
    cout << "在指定位置_pHead->_pNext->_pNext插入节点123：" << endl;
    Node *p = lst.getHead()->_pNext->_pNext;
    lst.insert(p, 123);
    lst.display();
}

void test2()
{
    LinkList lst;
    lst.display();
}
int main()
{
    /* test(); */
    test2();
    return 0;
}

