#include<iostream>
using namespace std;

struct student
{
    int id;
    string name;
    string address;

    void fun()
    {
        cout<<"Helloworld"<<endl;
    }
};

class student1
{
    int id;
    string name;
    string address;
};

int main()
{
    struct student var1;
    student1 obj1;
    //obj1.id=18;
    //obj1.name= "virat";//we canot access like this beacause they are private members.
    var1.id = 18;
    var1.name = "virat";
    var1.address = "Bengaluru";
    var1.fun();
    cout<<var1.id<<endl<<var1.name<<endl<<var1.address<<endl;
}