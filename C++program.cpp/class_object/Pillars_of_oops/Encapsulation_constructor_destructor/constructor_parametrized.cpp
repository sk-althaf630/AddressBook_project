#include <iostream>
using namespace std;

class myclass
{
    int id;
    string name;
    float marks;

    public:
        //parametrized constructor
       /* //way 1:-
        myclass()
        {
            cout<<"way_1 -->parametrized constructor is called"<<endl;
            id = 0;
            name = "default";
            marks = 36;
        }*/
       
        
        //way :- 3
        myclass(int id = 0, string name = "default", float marks = 78):id(id),name(name),marks(marks)//initializer list
        {
            cout<<"way_3 ---> parametrized constructor is called"<<endl;
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