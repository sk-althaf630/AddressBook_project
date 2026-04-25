#include<iostream>
using namespace std;
class student
{
    //public: //by this we can access below members.
    int id;
    string name;
    int marks;

    public:
    student()
    {
        cout<<"Constructor called\n";
        id =0;
        name = "Default";
        marks = 68;
    }
    
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
        cout<<"The id is "<<id<<endl<<"The name is "<<name<<endl<<"The marks are "<<marks<<endl;
    }

};

int main()
{
    student s1, s2;
    s1.printdetails();
    s2.printdetails();
    //cout<<"The size of s1 is "<<sizeof(s1)<<endl<<"The size of s2 is "<<sizeof(s2)<<endl;
}