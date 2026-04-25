//virtual function
#include<iostream>
using namespace std;
class student
{
    public:
    int id;
    string name;
    string address;
    public:

    student(int id=0, string name ="Default1", string address ="Default2"):id(id),name(name),address(address)
    {

    }

    virtual void display()
    {
        cout<<" ID -> "<<id<<" Name->"<<name<< " Address -> "<<address<<endl;
    }

};

class stupar: public student
{
    int marks;
    public:
    stupar(int id=1,string name ="default2",string address ="Default3",int marks=90):student(id,name,address),marks(marks)
    {

    }
    void display()
    {
        cout<<" ID -> "<<id<<" Name->"<<name<< " Address -> "<<address<< "marks -> "<<marks<<endl;
    }
};

int main()
{
    student *st1=new stupar(18,"VK","banglore",202);
    st1->display();
}