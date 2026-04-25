#include<iostream>
using namespace std;
class polygon
{
    protected : 
    int height ,width;
    public:
    void set_values(int a,int b)
    {
        height =a;
        width =b;
    }
};

class rectangle: public polygon
{
    public:
    int area()
    {
        return height * width;
    }
};

class triangle:public polygon
{
    public:
    int area()
    {
        return 0.5*height *width;
    }
};

int main()
{
    rectangle rectl;
    triangle trgl;
    polygon *ob1 =&rectl;
    polygon *ob2 =&trgl;

    ob1->set_values(4,5);
    ob2->set_values(4,5);

    cout<<rectl.area()<<endl;
    cout<<trgl.area()<<endl;
}