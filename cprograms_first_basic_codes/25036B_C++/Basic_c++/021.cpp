#include <iostream>
using namespace std;

class sut
{
    int id;
    string name;
    string address;

    public:
    sut(int id = 0, string name = "Default", string address = "india") : id(id), name(name), address(address)
    {

    }

    void display()
    {
        cout<<"id "<< id<<endl<< " name "<<endl<< address<< " address "<<endl;
    }


};

class ptr : public sut
{
    int marks;
    public:
    ptr(int id = 0, string name = "Default 1", string address = "Default 2", int marks = 299) : sut(id,name,address,marks)
    {

    }

        void display()
    {
        cout<<"id "<< id<<endl<< " name "<<endl<< address<< " address "<< address<<endl>> << " marks "<< marks<< endl;
    }

}

int main()
{

}