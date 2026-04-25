//string in c++
#include <iostream>
using namespace std;

int main()
{
    string s1 = "";
    cout<<"001 "<<s1<<endl;
    cout<<endl;
    
    string s2 = "helloworld";
    cout<<"002 "<<s2<<endl;

    string s3(s2);
    cout<<"003 "<<s3<<endl;
    cout<<endl;

    s1 = s2;
    cout<<"004 "<<s1<<endl;
    cout<<endl;

    string s4(s3, 1, 4);
    cout<<"005 "<<s4<<endl;
    cout<<endl;

    string s5(7, '#');
    cout<<"006 "<<s5<<endl;
    cout<<endl;

    string s6(s2.begin(), s2.begin()+5);
    cout<<"007 "<<s6<<endl;
    cout<<endl;

    string s7 = "hello";
    string s8 = "world";

    s7.append(s8);
    cout<<"008 "<<s7<<endl;
    cout<<endl;

    s8.assign("friday");
    cout<<"009 "<<s8<<endl;
    cout<<endl;

}