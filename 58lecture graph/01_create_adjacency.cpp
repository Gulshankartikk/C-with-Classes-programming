#include<iostream>
#include<vector>
using namespace std;

int main(){

    int v,e;
    cin>>v>>e;
    /*
    int A[v] [v];
    int a,b;
    for(int i=0; i<e; i++){
        cin>>a>>b;
        A[a][b]=1;
        A[b][a]=11;
    }*/

    vector<int>A[v];
    int a,b;
    for(int i=0; i<e; i++){
        cin>>a>>b;
        A[a].push_back(b);
        A[b].push_back(a);
    }
    return 0;
}