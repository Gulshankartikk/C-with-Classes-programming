#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


void insertHeap(vector<int> &maxHeap)
{
    int index = maxHeap.size() - 1;
    
    while(index > 0)
    {
        int parentIndex = (index - 1) / 2;

        if(maxHeap[parentIndex] < maxHeap[index])
        {
            swap(maxHeap[parentIndex], maxHeap[index]);
            index = parentIndex;
        }
        else
            break;
    }
}
int main()
{
    vector<int>maxHeap;
    int n, element;

    // size of heap
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>element;
        maxHeap.push_back(element);
        insertHeap(maxHeap);
    }
    for(int i=0;i<maxHeap.size();i++)
        cout<<maxHeap[i]<<" ";
    return 0;
}