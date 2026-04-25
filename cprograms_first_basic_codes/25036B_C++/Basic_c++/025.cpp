//for understanding the reange/scope of the object.
#include <iostream>
using namespace std;

void fun();
namespace first
{
    char x = 'A';
}

namespace second
{
    float x = 635.7;
}
//double x = 34.7;
int main()
{
    int x = 57;

    cout<<"locale x is "<<endl;
    //cout<< ::x<< endl;
    cout<<first::x<<endl;
    cout<<second::x<<endl;

    fun();
}

void fun()
{
    using namespace first;
    cout<<first::x<<endl;
}