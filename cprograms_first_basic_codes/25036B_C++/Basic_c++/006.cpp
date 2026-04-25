#include<iostream>
using namespace std;
class student 
{
    int id;
    string name;

    public:
    student(int id=0, string name = "default"):id(id),name(name)
    {
        cout<<"Constructor called"<<endl;
    }
    ~student()
    {
        cout<<"Destorutor called"<<endl;
    }
    void display()
    {
        cout<<"Id is "<<id<<"name is "<<endl;
    }
};

int main()
{
    student s1, s2(18, "virat");
    s1.display();
    s2.display();
}