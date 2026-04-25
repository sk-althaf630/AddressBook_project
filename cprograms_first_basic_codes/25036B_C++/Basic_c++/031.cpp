// Exceptional handling
#include<iostream>
using namespace std;
int main()
{
    int num1,num2;
    cout<<"Enter two numbers : ";
    cin>>num1>>num2;
    cout<<"helloworld1"<<endl;
    try
    {
        
        if(num2== 0)
            throw num2;
        else if(num2 < 0)
            throw "negative number not allowed\n";
        else
            cout<<num1/num2<<endl;
    }
    
catch(int var)
  {
    cout<<"Tring to divide by "<<var<<endl;
  }
  catch( const char * error)
  {
    cout<<error;

  }

  //default catch block
  catch(...)
  {
    cout<<"Default catch block ----- negative number\n";
  }

  cout<<"helloworld2"<<endl;
}