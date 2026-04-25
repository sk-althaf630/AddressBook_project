#include <iostream>
using namespace std;

class vehicle
{
    public:
        vehicle()
        {
            cout<<"<-------------------------------->"<<endl;
            cout<<endl;
            cout<<"Vehicle constructor is called"<<endl;
            cout<<"<-------------------------------->"<<endl;
            cout<<endl;
        }
        ~vehicle()
        {
            cout<<"<-------------------------------->"<<endl;
            cout<<endl;
            cout<<"Vehicle Destructor is called"<<endl;
            cout<<"<-------------------------------->"<<endl;
            cout<<endl;
        }
};

class car : public vehicle
{
    public:
        car()
        {
            cout<<"<-------------------------------->"<<endl;
            cout<<endl;
            cout<<"car constructor is called"<<endl;
            cout<<"<-------------------------------->"<<endl;
            cout<<endl;
        }
        ~car()
        {
            cout<<"<-------------------------------->"<<endl;
            cout<<endl;
            cout<<"car Destructor is called"<<endl;
            cout<<"<-------------------------------->"<<endl;
            cout<<endl;
        }
};

class Bike : public vehicle
{
    public:
        Bike()
        {
            cout<<"<-------------------------------->"<<endl;
            cout<<endl;
            cout<<"Bike constructor is called"<<endl;
            cout<<"<-------------------------------->"<<endl;
            cout<<endl;
        }
        ~Bike()
        {
            cout<<"<-------------------------------->"<<endl;
            cout<<endl;
            cout<<"Bike Destructor is called"<<endl;
            cout<<"<-------------------------------->"<<endl;
            cout<<endl;
        }
};

int main()
{
    vehicle s1; // only vehicle constructor
    cout<<endl;
    car s2; // vehicle constructor -> car constructor
    cout<<endl;
    Bike s3;//vehicle constructor -> Bike constructor
    cout<<endl;
}