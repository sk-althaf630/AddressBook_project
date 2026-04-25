#include <iostream>
using namespace std;

class student
{
    public:
    int id;
    string name;
    student(int id = 0,string name = "Default") : id(id),name(name)
    {
        cout<<"Default Contstructor called"<<endl;
    }

    student(const student &var)
    {
        cout<<"copy constructor called"<<endl;
        id = var.id;
        name = var.name;
    }

    ~student()
    {
        cout<<"Destructor called"<<endl;
    }

    void print()
    {
        cout<<"ID is "<<id<<"Name is "<<name<<endl;
    }

};
int main()
{
    student s1(18,"virat"),s4;
    student s2 = s1;
    s1.print();
    student s3(s4);
    s3.print();
    s4 = s1;
    s4.print();
}