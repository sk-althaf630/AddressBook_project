//MULTIPLE INHERITANCE
#include<iostream>
using namespace std;
class A
{
    public:
    A()
    {
        cout<<"A's constructor called"<<endl;
    }

    ~A()
    {
        cout<<"A's constructor called"<<endl;
    }
};

class B 
{
    public:
    B()
    {
        cout<<"B's constructor called"<<endl;
    }

    ~B()
    {
        cout<<"B's constructor called"<<endl;
    }
};

//multiple inheritance
class C : public A, public B
{
    public:
    C()
    {
        cout<<"C's constructor called"<<endl;
    }

    ~C()
    {
        cout<<"C's constructor called"<<endl;
    }
};

int main()
{
    A obj1;
    B obj2;
    C obj3;
}