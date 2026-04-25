#include <iostream>
using namespace std;

class A
{
    public:
        int id;
    private:
        string name;
    protected:
        string address;

    public:
        A(int id = 0, string name = "Def_name", string address = "Def_address"):id(id),name(name),address(address)
        {
            cout<<"Parent Constructor is called"<<endl;
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

        ~A()
        {
            cout<<"Destructor is called"<<endl;
        }
};

class B : public A 
{
   int marks;
   public:
        B(int id = 0, string name = "Def_name", string address = "Def_address", int marks = 95):A(id,name,address),marks(marks)
        {
            cout<<"chiled Constructor is called"<<endl;
        }
        void setter()
        {
            cout<<"The id is ";
            cin>>id;
            // cout<<"The name is ";//it inaccessible private
            // cin>>name;
            cout<<"The address is ";
            cin>>address;
            cout<<"The markes is ";
            cin>>marks;
        }

        void getter()
        {
            cout<<""<<id<<endl;
           // cout<<""<<name<<endl;//it inaccessible private
            cout<<""<<address<<endl;
            cout<<""<<marks<<endl;
        }

        ~B()
        {
            cout<<"Chiled Destructor is called"<<endl;
        }


};

int main()
{
    B s1;
    s1.setter();
    s1.getter();
    A s2;
    s2.setter();
    s2.getter();


    return 0;
}