#include <cstdio>
using namespace std;

//基类A
class A{
public:
    A(int a, int b);
public:
    void display();
protected:
    int m_a;
    int m_b;
};
A::A(int a, int b)
    : m_a(a), m_b(b)
{

}
void A::display(){
    printf("m_a=%d, m_b=%d\n", m_a, m_b);
}

//派生类B
class B: public A{
public:
    B(int a, int b, int c);
    void display();
    //private:
protected:    
    int m_c;
};
B::B(int a, int b, int c): A(a, b), m_c(c){ }
void B::display(){
    printf("m_a=%d, m_b=%d, m_c=%d\n", m_a, m_b, m_c);
}

//声明并定义派生类C
class C: public B{
public:
    C(char a, int b, int c, int d);
public:
    void display();
private:
    int m_b;  //遮蔽A类的成员变量
    int m_c;  //遮蔽B类的成员变量
    int m_d;  //新增成员变量
};
C::C(char a, int b, int c, int d): B(a, b, c), m_b(b), m_c(c), m_d(d){ }
void C::display(){
    printf("A::m_a=%d, A::m_b=%d, B::m_c=%d\n", m_a, A::m_b, B::m_c);
    printf("C::m_b=%d, C::m_c=%d, C::m_d=%d\n", m_b, m_c, m_d);
}




int main(){
    A obj_a(99, 10);
    B obj_b(84, 23, 95);
    obj_a.display();
    obj_b.display();
    //创建C类对象obj_c
    C obj_c(84, 23, 95, 60);
    obj_c.display();

    return 0;
}
