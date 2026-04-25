#include <iostream>
using namespace std;

class student
{
    public:
        int id;
        string name;
        string address;

    public:
        student(int id = 0, string name = "Def_name", string address = "Def_address"):id(id),name(name),address(address)
        {
            cout<<"Parent-1 Constructor is called"<<endl;
        }
        void setter()
        {
            cout<<"The id is ";
            cin>>id;
            cout<<"The name is ";
            cin>>name;
            cout<<"The address is ";
            cin>>address;
        }

        void getter()
        {
            cout<<""<<id<<endl;
            cout<<""<<name<<endl;
            cout<<""<<address<<endl;
        }

        ~student()
        {
            cout<<"Parent-1 Destructor is called"<<endl;
        }
};

class Athlete
{
    public:
        string number;
        string Parent_name;
        string bethor_name;

    public:
        Athlete(string number = "0", string Parent_name = "Def_name", string bethor_name = "Def_address"):number(number),Parent_name(Parent_name),bethor_name(bethor_name)
        {
            cout<<"Parent-2 Constructor is called"<<endl;
        }
        void setter()
        {
            cout<<"The number is ";
            cin>>number;
            cout<<"The parent_name is ";
            cin>>Parent_name;
            cout<<"The bethor_name is ";
            cin>>bethor_name;
        }

        void getter()
        {
            cout<<""<<number<<endl;
            cout<<""<<Parent_name<<endl;
            cout<<""<<bethor_name<<endl;
        }

        ~Athlete()
        {
            cout<<"Parent-2 Destructor is called"<<endl;
        }
};

class studentAthlete : private student, private Athlete
{
    public:
        int score;
        studentAthlete(int id = 0, string name = "Def_name", string address = "Def_address", string number = "0", string Parent_name = "Def_parentname", string bethor_name = "Def_bethor", int score = 0):student(id,name, address), Athlete(number, Parent_name, bethor_name), score(score)
        {
            cout<<"Chailed Constructor is called"<<endl;
        }
        void setter()
        {
            cout<<"The id is ";
            cin>>id;
            cout<<"The name is ";
            cin>>name;
            cout<<"The address is ";
            cin>>address;
            cout<<"The number is ";
            cin>>number;
            cout<<"The parent_name is ";
            cin>>Parent_name;
            cout<<"The bethor_name is ";
            cin>>bethor_name;
            cout<<"The score is ";
            cin>>score;
        }

        void getter()
        {
            cout<<""<<id<<endl;
            cout<<""<<name<<endl;
            cout<<""<<address<<endl;
            cout<<""<<number<<endl;
            cout<<""<<Parent_name<<endl;
            cout<<""<<bethor_name<<endl;
            cout<<""<<score<<endl;
        }

        ~studentAthlete()
        {
            cout<<"Chailed Destructor is called"<<endl;
        }
};

int main()
{
    studentAthlete s1;
    cout<<"<------------------->"<<endl;
    cout<<endl;
    s1.setter();
    cout<<"<------------------->"<<endl;
    cout<<endl;
    s1.getter();
}