#include <iostream>
using namespace std;

int fun(int a, int b)
{
    cout<<"From function1"<<endl;
    return a+b;
}

double fun(int a, double b)
{
    cout<<"From function2"<<endl;
    return a+b;
}

void fu