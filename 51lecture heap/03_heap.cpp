#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void Heapify(vector<int>& maxHeap, int index)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int size = maxHeap.size();

    if(left < size && maxHeap[left] > maxHeap[largest])
        largest = left;

    if(right < size && maxHeap[right] > maxHeap[largest])
        largest = right;

    if(largest != index)
    {
        swap(maxHeap[largest], maxHeap[index]);
        Heapify(maxHeap, largest);
    }
}

int main()
{
    vector<int> MaxHeap;
    int n, element;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> element;
        MaxHeap.push_back(element);
    }

    // Build max heap
    for(int i = n/2 - 1; i >= 0; i--)
        Heapify(MaxHeap, i);

    // Print heap
    for(int i = 0; i < MaxHeap.size(); i++)
        cout << MaxHeap[i] << " ";
}