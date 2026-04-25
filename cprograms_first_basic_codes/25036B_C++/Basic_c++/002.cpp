#include <iostream>
using namespace std;
class student
{
    int id;
    string name;
    int marks;

    public:
    void getdetails()
    {
        cout<<"Enter the id ";
        cin>>id;
        cout<<"Enter the name ";
        cin>>name;
        cout<<"Enter the marks ";
        cin>>marks;
    }

    void printdetails()
    {
        cout<<" The id is "<<id<<endl<<"The name is "<<name<<endl<<"The marks are "<<marks<<endl;
    }
};

int main()
{
    student s1, s2;
    s1.getdetails();
    s1.printdetails();
}