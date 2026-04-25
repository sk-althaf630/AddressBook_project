#include <iostream>
using namespace std;

class myclass
{
    int id;
    string name;
    float marks;

    public:
        myclass(int id = 0, string name = "default", float marks = 78):id(id),name(name),marks(marks)//initializer list
        {
            cout<<"parametrized constructor is called"<<endl;
        }

        void display()
        {
            cout<<""<<id<<endl<<""<<name<<endl<<""<<marks<<endl;
        }

        ~myclass()
        {
            cout<<"Desturctor is called"<<endl;
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