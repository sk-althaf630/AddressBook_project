#include <iostream>
using namespace std;

template <typename A, typename B>

A maxl(A var1, B var2)
{
    return var1 > var2? var1:var2;
}

int main()
{
    cout<<maxl(13,'A')<<endl;
    cout<<maxl('A',13)<<endl;
    cout<<maxl(45.66, 15)<<endl;
    cout<<maxl((float)65.77,700)<<endl;
}
