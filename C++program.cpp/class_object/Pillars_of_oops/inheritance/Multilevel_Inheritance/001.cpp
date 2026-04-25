#include <iostream>
using namespace std;

class parent
{

    public:
    parent()
    {
            cout<<"<-------------------------------->"<<endl;
    cout<<endl;

        cout<<"Parent constructor is called"<<endl;
            cout<<"<-------------------------------->"<<endl;
    cout<<endl;

    }
    ~parent()
    {
            cout<<"<-------------------------------->"<<endl;
    cout<<endl;

        cout<<"Parent Destructor is called"<<endl;
            cout<<"<-------------------------------->"<<endl;
    cout<<endl;

    }

};

class child : public parent
{
    public:
    child()
    {
            cout<<"<-------------------------------->"<<endl;
    cout<<endl;

        cout<<"Child constructor is called"<<endl;
            cout<<"<-------------------------------->"<<endl;
    cout<<endl;

    }
    ~child()
    {
            cout<<"<-------------------------------->"<<endl;
    cout<<endl;

        cout<<"Child Destructor is called"<<endl;
            cout<<"<-------------------------------->"<<endl;
    cout<<endl;

    }

};

class Grandchild : public child
{

    public:
    Grandchild()
    {
            cout<<"<-------------------------------->"<<endl;
    cout<<endl;

        cout<<"Grandchild constructor is called"<<endl;
            cout<<"<-------------------------------->"<<endl;
    cout<<endl;

    }
    ~Grandchild()
    {
            cout<<"<-------------------------------->"<<endl;
    cout<<endl;

        cout<<"Grandchild Destructor is called"<<endl;
            cout<<"<-------------------------------->"<<endl;
    cout<<endl;

    }
};

int main()
{
int main() {
    parent object1;     // calls parent constructor once
        cout<<endl;
    child obj2;         // calls parent constructor again (before child constructor)
        cout<<endl;
    Grandchild obj3;    // calls parent constructor again (before child → grandchild constructor)
        cout<<endl;

}
}