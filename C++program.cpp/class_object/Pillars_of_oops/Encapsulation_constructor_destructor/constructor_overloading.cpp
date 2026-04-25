#include <iostream>
using namespace std;

class myclass
{
    int id;
    string name;
    float marks;

    public:
       
        //constructor overloading
        //way_3:- 
    //    myclass(int id = 0, string name = "default", float marks = 78)
    //     {
    //         cout<<"parametrized constructor is called"<<endl;
    //         //"this->" it is the this points to the property of the current object.
    //         this->id = id;
    //         this->name = name;
    //         this->marks = marks;

    //     }
        myclass()
        {
            cout<<"Default constructor is called"<<endl;
            id = 0;
            name = "default";
            marks = 40;
        }

        myclass(int sid, string sname, float smarks)
        {
            cout<<"constructor overloading is called"<<endl;
            id = sid;
            name = sname;
            marks = smarks;
        }
        void display()
        {
            cout<<""<<id<<endl<<""<<name<<endl<<""<<marks<<endl;
        }
        
};

int main()
{
    myclass s1;
    s1.display();

    myclass s2(2, "althaf", 99.99);
    s2.display();

    return 0;
}