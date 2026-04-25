#include <iostream>
#include <cstring>
using namespace std;

class myclass
{
    int *id;
    char *name;

    public:
    myclass()
    {
        cout<<"Constructor is called"<<endl;
        //allocate 4bytes of memory in heap and initialize with 45 and store the starting address in pointer.
        id = new int(45);
        //allocate 10bytes of memory in the heap and store the starting address in the ponter.
        name = new char[10]();
        strcpy(name,"default");
    }
    
    myclass(int val, const char *str): id(new int(val)), name(new char[strlen(str)+1])
    {
        cout<<"parameter constructor is called"<<endl;
        strcpy(name, str);
    }

    void promote()
    {
        cout<<"The id of the student : ";
        cin>>*id;
        
        cout<<"The name of the student : ";
        cin>>name;
        cout<<"<----------------------->"<<endl;
        cout<<endl;
    }
    void deatiles()
    {
        cout<<"The id is "<<*id<<endl;
        cout<<"The name is "<<name<<endl;
        cout<<"<----------------------->"<<endl;
        cout<<endl;
    }
    
    ~myclass()
    {
        cout<<"Destructor is called"<<endl;
        delete(id);
        delete(name);
    }
};

int main()
{
    myclass s1;//first constructor will work
    s1.deatiles();

    myclass s2;//first constructor will work
    s2.promote();
    s2.deatiles();
    
    myclass s3(99, "virat");//second constructor will work
    s3.deatiles();

    return 0;
}