//templete
#include<iostream>
using namespace std;

template<typename A>

A max1(A var1, A var2)
{
    //var1>var2?cout<<var1<<"is greater"<<endl: cout<<var2<<"is greater"<<endl;
    return var1>var2 ? var1 : var2;
}

int main()
{
    cout << max(10, 5) <<endl;
    cout << max((float)14.55, (float)34.56) <<endl;
    cout << max(78.67, -56.45) <<endl;
    cout << max('A', 'a') <<endl;
}