//HYBRID INHERTANCE

#include <iostream>
using namespace std;

class A
{
    public:
    A()
    {
        cout<< "A's constructor called"<< endl;
    }

    ~A()
    {
        cout<<"A's destructor called"<< endl;
    }
};

class B : public A
{
    public:
    B()
    {
        cout <<"B's constructor called"<< endl;
    }

    ~B()
    {
        cout<<"B's destructor called"<< endl;
    }
};

class C : public A
{
    public:
    C()
    {
        cout <<"C's constructor called"<< endl;
    }

    ~C()
    {
        cout<<"C's destructor called"<< endl;
    }
};

class D : public B,public C
{
    public:
    D()
    {
        cout <<"D's constructor called"<< endl;
    }

    ~D()
    {
        cout<<"D's destructor called"<< endl;
    }
};




int main()
{
    A obj1;
    B obj2;
    C obj3;
    D obj4;
}