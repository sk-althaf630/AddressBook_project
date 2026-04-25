/*Create a class called Book with the following attributes:

title (string)
author (string)
year (int)
Then create two objects of the class and print their attribute values.

Expected Output
Matilda, Roald Dahl, 1988
The Giving Tree, Shel Silverstein, 1964*/

#include <iostream>
using namespace std;

class myBook
{
    private:
    int year;
    string title;
    string author;
     
    public:
    void promote()
    {
        cout<<"Enter the titale of the Book: ";
        cin>>title;
        cout<<"Enter the author of the Book: ";
        cin>>author;
        cout<<"Enter the year of the Book: ";
        cin>>year;
    }

    void disply()
    {
        cout<<" "<<title<<","<<" "<<author<<","<<" "<<year<<endl;
    }
};

int main()
{
    myBook s1,s2;
    s1.promote();
    s1.disply();

    s2.promote();
    s2.disply();
    
    return 0;
}