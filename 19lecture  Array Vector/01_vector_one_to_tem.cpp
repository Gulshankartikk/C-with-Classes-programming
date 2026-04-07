#include<iostream>
#include<vector>
using namespace std;

int main()
{
  int x=10;
  vector<int>v;
  for(int i=1;i<=10;i++)
  v.push_back(i);

  for(int i=0;i<v.size();i++)
  cout<<v[i]<<" ";

  for (auto x:v)
  cout<<x<<" ";
    return 0;
}