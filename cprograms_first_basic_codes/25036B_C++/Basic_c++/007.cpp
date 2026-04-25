#include<iostream>
#include<string.h>
using namespace std;
class student
{
    int* id;
    char* name;

    public:
    student()
    {
        cout<<"constructor called"<<endl;
        id = new int(45); // allocate 4 bytes of memory in heap and initialize with 45 and store the 
        //stsrting address in id
        name=new char[10];//allocate 10 bytes of memory in the heap and store the starting address  in the name
        strcpy(name,"rohit"); 

    }
    void display()
    {
        cout<<"ID is "<<*id<<"Name is "<<name<<endl;
    }
    ~student()
    {
        cout<<"destructor called"<<endl; 
        
        cout<<"Destructor called"<<endl;
        delete (id);      // free integer memory
        delete (name);
    }

};
int main()
{
    student s1;
    s1.display();
    //s2.display();
}