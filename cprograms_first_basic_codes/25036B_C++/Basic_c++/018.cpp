//Dynamical memory in c++

#include <iostream>
using namespace std;

class student
{
    public:
    int id;
    string name;
    string address;

    student(int id = 0, string name = "Dfault", string address = "nellore"):id(id),name(name), address(address)
    {
        cout<<"constructor is called"<<endl;
    }

    ~student()
    {
        cout<<"destroctor is called"<<endl;
    }

    void display()
    {
        cout<<"id is "<< id<<endl<<"name is "<< name<<endl<<"adress is "<<address<< endl;
    }
};

int main()
{
    student *ptr1 = new student();
    student *ptr2 = new student(45, "Rohit", "Munbai");

    ptr1->display();
    ptr2->display();
    
    student *ptr3 = new student[5];
    for(int i = 0; i < 5; i++)
    {
        ptr3[i].display();
    }

    ptr3[1].id = 18;
    ptr3[1].name = "virat";
    ptr3[1].address = "bangaluru";
    ptr3[1].display();

    return 0;
}