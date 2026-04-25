#include<iostream>
using namespace std;

template<class A, class B>

class student
{
    A num1;
    A num2;
    B num3;

    public:
    student(A num1 = 0,A num2 = 0, B num3 = 0):num1(num1), num2(num2), num3(num3)
    {}
    void display()
    {
        cout<<" num1 --> "<<num1<<" num2 --> "<<num2<<" num3 "<<num3<<endl;
    }
};

int main()
{
    student <int,double>obj1(10, 45, 45.78);
    obj1.display();
    student <char,float>obj2('A', 'a', (float)34.55);
    obj2.display();
}