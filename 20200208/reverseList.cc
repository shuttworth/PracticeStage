#include <iostream>
#include <stack>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        //       尾插法其实并不高明,一边遍历一边头插效果更好
        ListNode * pos = head;
        while(pos->next!=NULL)
        {
            pos=pos->next;
        }
        ListNode* tail=new ListNode(0);
        tail->next=NULL;
        pos->next=tail; //尾结点的安插已经完成
        ListNode * moveNode;
        while(head!=tail)
        {
            moveNode=head;
            ++head;
            moveNode->next=NULL;
            tail->next=moveNode;
        }
        head=head->next;
        delete tail;
        return head; 
    }
};

void test0()
{
    stack<int>sta1;
    cout<<sta1.empty()<<endl;
    cout<<sta1.top()<<endl;
}

int main()
{
    test0();
    /* ListNode p1(1); */
    /* ListNode p2(2); */
    /* ListNode p3(3); */
    /* ListNode * g1 = &p1; */
    /* cout<<g1->val<<endl; */
    //p1.next=p2;
    //p2.next=p3;

    return 0;
}

