#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void find (string S,string used,vector<string>&ans,string temp)
{
    if(temp.size()==S.size())
    {
        ans.push_back(temp);
        return;
    }
    for(int i=0;i<S.size();i++)
    {
        if(used[i]=='0')
        {
            used[i]='1';
            temp=temp+S[i];
            find(S,used,ans,temp);
            temp.pop_back();
            used[i]='0';
        }
    }
}

bool checkInclusion(string s1, string s2) {

    string used="";
    for(int i=0;i<s1.size();i++)
        used=used+'0';

    vector<string>ans;
    string temp="";
    find(s1,used,ans,temp);

    sort(ans.begin(),ans.end());

    if(ans.size()==0) return false;

    vector<string>final;
    final.push_back(ans[0]);

    int i=0,j=1;
    while(j<ans.size())
    {
        if(final[i]!=ans[j])
        {
            final.push_back(ans[j]);
            i++;
        }
        j++;
    }

    for(int k=0;k<final.size();k++)
    {
        if(s2.find(final[k])!=string::npos)
            return true;
    }

    return false;
}