#include<iostream>
using namespace std;
class student
{
    int id;
    float marks;
    string name;
    public:
   /* student()
    {
        cout<<"Default Consturctor called\n"<<endl;
        id = 0;
        marks = 2.5;
        name = "Default";
    }*/

        student(int id = 0, float marks = 2.5, string name = "Default"):id(id),marks(marks), name(name)//initializer list
        {
            cout<<"Paramaterized  1constructor called\n"<<endl;

           // this ->id = id; //this -> it is the this points to the property of the current object
            //this ->marks = marks;
            //this ->name = name;
        }
        student(int sid, string sname, float smarks)
        {
            cout<<"Paramaterized 2constructor called\n"<<endl;

            id = sid;
            marks = smarks;
            name = sname;
        }
    void printdetails()
    {
        cout<<id<<" "<<marks<<" "<<name<<endl;
    }
};

int main()
{
    // student s1, s2, s3, s4, s5;
    // s1.printdetails();
    // s2.printdetails();
    // s3.printdetails();
    // s4.printdetails();
    // s5.printdetails();

    student s1(18, 183, "Virat"),s2(45, 264, "Rohit"),s3(7, 100, "Dhoni"), s4;
    s1.printdetails();
    s2.printdetails();
    s3.printdetails();
    s4.printdetails();
    student st5 = s3; //str4 invoking the default copy constructor
    st5.printdetails();

}