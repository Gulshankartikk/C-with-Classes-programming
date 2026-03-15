#include<iostream>
using namespace std;

void print(string s,int index)
{
    if(index==s.size()-1)
    {
        cout<<s<<" ";
        return;
    }
    for(int i=index;i<s.size();i++)
    {
        swap(s[i],s[index]);
        print(s,index+1);
        swap(s[i],s[index]);
    }
}
int main()
{
    string s="ABC";
    print(s,0);
    return 0;
}
