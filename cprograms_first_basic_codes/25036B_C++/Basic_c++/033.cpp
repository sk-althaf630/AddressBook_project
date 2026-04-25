//vector
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v(5, 10);
    vector<int> ::iterator ptr;
    for(ptr = v.begin(); ptr != v.end(); ptr++)
    {
        cout<<*ptr<<endl;
    }

    cout<<"<------------------>\n";
    v.push_back(18);
    v.push_back(23);

    for(int i = 0; i< v.size(); i++)
    {
        cout<<v[i]<<endl;
    }
    v.pop_back();
    cout<<"<------------------->"<<endl;
    for(int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<endl;
    }
}