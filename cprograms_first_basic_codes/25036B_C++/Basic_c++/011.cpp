//shallowcopy

/*#include <iostream>
using namespace std;

class shallowcopy
{
    public:
    int *data;
    shallowcopy(int val)
    {
        data = new int (val);
    }

    shallowcopy(const shallowcopy &other)
    {
        data = other.data;
    }

    ~shallowcopy()
    {
        delete(data);
    }

    void print()
    {
        cout<<*data<<endl;
    }
};

int main()
{
    shallowcopy obj1(45);
    shallowcopy obj2(obj1);
    obj1.print();
    obj2.print();
    *obj1.data = 18;
    obj1.print();
    obj2.print();

    return 0;
}*/

//deep copy

#include<iostream>
#include<cstdlib>
using namespace std;
class shallowcopy
{
    public:
    int *data;
    shallowcopy(int val)
    {
        data =new int(val);
    }
    shallowcopy(const shallowcopy &other)
    {
        data =other.data;
    }

    // ~shallowcopy()
    // {
    //     delete(data);
    // }

    void print()
    {
        cout<<*data<<endl;
    }
};

class deepcopy
{
    public:
    int *data;
    deepcopy(int val)
    {
        data =new int(val);
    }
    deepcopy(const  deepcopy &other)
    {
        data = new int(*other.data);
    }

    ~deepcopy()
    {
        free(data);
    }

    void print()
    {
        cout<<*data<<endl;
    }

};

int main()
{
    deepcopy obj1(45);
    deepcopy obj2(obj1);
    obj1.print();
    obj2.print();
    *obj1.data =18;
    obj1.print();
    obj2.print();

}