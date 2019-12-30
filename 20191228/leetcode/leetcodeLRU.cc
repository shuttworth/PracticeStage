#include <iostream>
#include <list>
#include <unordered_map>

using std::cout;
using std::endl;
using std::unordered_map;
using std::list;

class LRUcache
{
    struct CacheNote
    {
        int key;
        int value;

        CacheNote(int k,int v)
            :key(k)
             ,value(v)
        {}


    };

public:
    LRUcache(int capacity)
        :_capacity(capacity)
    {}


    int get(int key)
    {
        auto it = _hashTable.find(key);
        if(it ==_hashTable.end()){
            return -1;
        }
        else { //如果查找到这个元素，需要把他移到链表的头部
            _data.splice(_data.begin(),_data,_hashTable[key]);
            _hashTable[key]=_data.begin();//对位置进行更新
            return _hashTable[key]->value;
        }
    }

    void put(int key,int value)
    {
        auto it=_hashTable.find(key);
        if(it == _hashTable.end())
        {
            if(_hashTable.size() == _capacity)
            {
                _hashTable.erase(_data.back().key);
                _data.pop_back(); //移除末尾元素
            }
            _data.push_front(CacheNote(key,value));
            _hashTable[key]=_data.begin();
        }
        else 
        {
            _hashTable[key]->value=value;
        }
    }

private:
    size_t _capacity; //put 里的第二个if想成立，需要_capacity是size_t 类型的
    list<CacheNote> _data;
    unordered_map<int,list<CacheNote>::iterator> _hashTable; //int 是key，iterator是list中的位置
};





int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

