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
void Heapify(vector<int>&maxHeap,int index)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int size =maxHeap.size();
    //first check for left side
    if(left < size && maxHeap[left] > maxHeap[largest])
        largest = left;
    // then check for right side
    if(right < size && maxHeap[right] > maxHeap[largest])
        largest = right;
    // if largest is not root
    if(largest != index)
    {
        swap(maxHeap[largest], maxHeap[index]);
        Heapify(maxHeap, largest);
    }
    return;

}

void DeleteHeap(vector<int>&maxHeap)
{

    // replace first element by last element
    maxHeap[0] = maxHeap[maxHeap.size()-1];
    // delete last element
    maxHeap.pop_back();
    // correct position pe leke jaao
    Heapify(maxHeap,0);

/*
    
    if(maxHeap.empty())
        return;

    // Step 1: Swap the root with the last element and remove the last element
    swap(maxHeap[0], maxHeap[maxHeap.size() - 1]);
    maxHeap.pop_back();

    // Step 2: Heapify down from the root to restore the heap property
    int index = 0;
    int size = maxHeap.size();

    while(true)
    {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if(leftChild < size && maxHeap[leftChild] > maxHeap[largest])
            largest = leftChild;

        if(rightChild < size && maxHeap[rightChild] > maxHeap[largest])
            largest = rightChild;

        if(largest != index)
        {
            swap(maxHeap[index], maxHeap[largest]);
            index = largest;
        }
        else
            break;
    }
    */
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
    DeleteHeap(maxHeap);
    DeleteHeap(maxHeap);
    for(int i=0;i<maxHeap.size();i++)
        cout<<maxHeap[i]<<" ";
    return 0;
}