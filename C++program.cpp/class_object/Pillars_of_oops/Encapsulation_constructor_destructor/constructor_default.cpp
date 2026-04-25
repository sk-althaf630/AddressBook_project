//NOTE :- when the object of the class is created then only the constructor will be called.
#include <iostream>
using namespace std;

class myclass
{
    int id;
    string name;
    float marks;

    public:
        //default constructor
        myclass()
        {
            cout<<"constructor is called"<<endl;
        }
        
        void promote()
        {
            cout<<"The id of the student: ";
            cin>>id;
            cout<<"The name of the student: ";
            cin>>name;
            cout<<"The marks of the student: ";
            cin>>marks;
        }

        void display()
        {
            cout<<""<<id<<endl<<""<<name<<endl<<""<<marks<<endl;
        }
        
};

int main()
{
    myclass s1;
    s1.promote();
    s1.display();

    myclass s2;
    s2.promote();
    s2.display();

    return 0;
}