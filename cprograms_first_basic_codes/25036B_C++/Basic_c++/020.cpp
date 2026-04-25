#include <iostream>
using namespace std;

class student
{
    int num1;
    int num2;
    public:
    //unariy operator overloading
    student(int num1 = 0, int num2 = 1) : num1(num1), num2(num2)
    {
        cout<< " constructor is called"<< endl;
    }

    void display()
    {
        cout << " num1 = "<< num1<<endl<<" num2 = "<< num2<<endl;
    }

    void operator --()
    {
        num1--;
        num2--;
    }

    void operator ++()
    {
        num1++;
        num2++;
    }

    void operator ++(int)
    {
        num1++;
        num2++;
    }

    //binary operator
    void operator -(int var)
    {
        num1 = num1 - var;
        num2 = num2 - var;
    }

    void operator +(int var)
    {
        num1 = num1 + var;
        num2 = num2 + var;
    }

    //multiple value returning
    student operator +(student temp)
    {
        student temp1;
        temp1.num1 = num1 + temp.num1;
        temp1.num2 = num2 + temp.num2;
        return temp1;
    }
};

int main()
{
    student var (20, -15);
    var.display();

    cout<<"unariy operator"<<endl;
    --var;
    var.display();

    ++var;
    var.display();

    var++;
    var.display();

    cout<<"binary operator"<<endl;
    var + 10;
    var.display();

    var + 20;
    var.display();

    cout<<"multiple value returning"<<endl;

    student obj2(20, 30), obj3;

    obj3 = var + obj2;
    obj3.display();


}