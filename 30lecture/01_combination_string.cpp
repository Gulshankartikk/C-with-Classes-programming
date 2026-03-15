#include<iostream>
using namespace std;

void print(string s,int index,string ans)
{
    if(ans.size())
    cout<<ans<<" ";
    if(index==s.size())
    return;

    if(ans.size()==0)
    print(s,index+1,ans);

    print(s,index+1,ans+s[index]);

}
int main()
{
    string s;
    cin>>s;
    print(s,0,"");
    return 0;
}
