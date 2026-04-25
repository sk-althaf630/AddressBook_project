//class template

#include <iostream>
using namespace std;

template<class A>
class student
{
    A num1;
    A num2;

    public:
    student(A num1 = 0, A num2 = 1): num1(num1), num2(num2)
    {

    }
    void display()
    {
        cout<<"num1 ---> "<<num1<<"num2---> "<<num2<<endl;
    }
};

int main()
{
    student <int>obj1(19,34);
    obj1.display();
    student<double>obj2(10.55, 20.88);
    obj2.display();
}