#include<iostream>
using namespace std;
class polygon //abstract class -class atleast having one pure virtual function is known as 
{
    protected : 
    int height ,width;
    string shape;
    
    public:
    polygon()
    {

    }

    polygon(int a, int b,string name):width(a),height(b),shape(name)
    {

    }

    string get_name()
    {
        return shape;
    }

    virtual int get_area(void) =0; //pure virtual function(implementation not available with the parent class,
    //only available with the child class,this function must be inherited in the child class)

    void print_area(void)
    {
        cout<<"The area of the "<<this->get_name()<<this->get_area()<<endl;
    }
};

class rectangle : public polygon
{
    public:
    rectangle (int a, int b, string name):polygon(a,b,name)
    {
    }

    int get_area()
    {
        return height * width;
    }
};


class triangle : public polygon
{
    public:
    triangle (int a, int b, string name):polygon(a,b,name)
    {
    }

    int get_area()
    {
        return height * width * 0.5;
    }
};

int main()
{
    rectangle retl(4,5,"Rect");
    triangle trgl(2,5,"Tri");
    retl.print_area();
    trgl.print_area();
}