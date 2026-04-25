//scope how it is on class
#include<iostream>
using namespace std;
namespace first
{
    class student
    {
        public:
        int id;
        string name;
    };
}

class student
{
    public:
    int id;
    string name;
};

int main()
{
    student s1;
    first::student s2;
    s1.name = "Virat";
    s2.name = "Rohit";
    cout<<s1.name<<endl<<s2.name<<endl;
}