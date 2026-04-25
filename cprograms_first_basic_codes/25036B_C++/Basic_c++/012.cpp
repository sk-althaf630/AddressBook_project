#include <iostream>
using namespace std;

class emertxe_members
{
    public:
    int id;
    string name;
    string address;

    public:
    emertxe_members(int id =0, string name = "Default", string address = "Earth"):id(id), name(name), address(address)
    {
        cout<<"parent constructor called"<<endl;
    }

    ~emertxe_members()
    {
        cout<<"parent destructor called"<<endl;
    }

    void display()
    {
        cout<<"--> id "<< id<<"name"<< name<<"address "<<address<<endl;
    }


};

class student : public emertxe_members
{
    int marks;
    public:
    student(int id = 1, string name = "def", string address = "buffer", int marks = 345):emertxe_members(id,name,address),marks(marks)
    {
        //this->marks = 345;
        cout<<"chiled constructor called"<<endl;
    }

    void display()
    {
        cout<<"--> id "<< id<<"name"<< name<<"address "<<address<< "marks "<<marks<<endl;
    }
 
};

int main()
{
    student em1,em2(45,"rohit","mumbai",183);
    em1.display();
    em2.display();
}
