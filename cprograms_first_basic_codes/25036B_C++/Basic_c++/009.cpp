//pass by value
// #include<iostream>
// using namespace std;
// void add(int ,int);
// int main()
// {
//     int num1=18,num2=20;
//     cout<<"before passing  " <<num1<<" "<<num2<<endl;
//     add(num1,num2);
//     cout<<"After passing  " <<num1<<" "<<num2<<endl;

// }
// void add(int num1,int num2)
// {
//     num1=num1+10;
//     num2=num2+10;
//     cout<<"inside function  " <<num1<<" "<<num2<<endl;
// }

//pass by reference
#include<iostream>
using namespace std;
void add(int &,int &);
int main()
{
    int num1=18,num2=20;
    cout<<"before passing  " <<num1<<" "<<num2<<endl;
    add(num1,num2);
    cout<<"After passing  " <<num1<<" "<<num2<<endl;

}
void add(int &num1,int &num2)
{
    num1=num1+10;
    num2=num2+10;
    cout<<"inside function  " <<num1<<" "<<num2<<endl;
}