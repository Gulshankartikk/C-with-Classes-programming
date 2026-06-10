#include<map>
#include<iostream>
using namespace std;

int main()
{
map<int,int>m;
//insert the data
m[3] = 93;
m[2] = 8;
m[9] = 15;
m[10] = 0;
cout<<m.size()<<endl;
//  cout<<m[10]<<" ";
// cout<<m.count(11)<<" ";
// count to find whether the key exist or not

for(auto i = m.begin(); i!=m.end();i++)
{
   cout<<i->first<<" "<<i->second<<endl;
}
return 0;

}
