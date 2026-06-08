#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
   //create pair

  vector<pair<int,int> >v;
  v.push_back(make_pair(10,20));
  v.push_back(make_pair(8,7));
  v.push_back(make_pair(4,9));
  v.push_back(make_pair(4,7));
  v.push_back(make_pair(9,15));
//accending order
//   sort(v.begin(),v.end());
  //decending order
  sort(v.rbegin(),v.rend());

  for(int i=0;i<5;i++)
  cout<<v[i].first<<" "<<v[i].second<<endl;



   return 0;
}