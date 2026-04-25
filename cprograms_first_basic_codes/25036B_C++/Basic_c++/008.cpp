#include<iostream>
using namespace std;

int main()
{
    int num = 45;
    int &ref = num;
    cout<<num<<" "<<ref<<endl;
    ref = ref+10;
    cout<<num<<" "<<ref<<endl;
    num = num + 10;
    cout<<num<<" "<<ref<<endl;

    return 0;

}