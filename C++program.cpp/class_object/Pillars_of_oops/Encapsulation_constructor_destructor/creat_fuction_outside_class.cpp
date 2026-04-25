/*wap that should be difination out side the class
sample input:- name 
sample output:- name*/

#include <iostream>
using namespace std;

class myclass
{
    int id;
    string name;
    float marks;

    public:
    void promote();
    void display();
};

void myclass :: promote()
{
    cout<<"The id of the student: ";
    cin>>id;
    cout<<"The name of the student: ";
    cin>>name;
    cout<<"The marks of the student: ";
    cin>>marks;
}

void myclass :: display()
{
    cout<<""<<id<<endl<<""<<name<<endl<<""<<marks<<endl;
}

int main()
{
    myclass s1;
    s1.promote();
    s1.display();

    myclass s2;
    s2= s1;
    s2.display();

    return 0;
}