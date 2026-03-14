#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& arr, int low, int high);

void quickSort(vector<int>& arr, int low, int high) {
    if(low >= high)
        return;
        
    int pos = partition(arr, low, high);
        
    quickSort(arr, low, pos - 1);
    quickSort(arr, pos + 1, high);
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int pos = low;

    for(int i = low; i < high; i++) {
        if(arr[i] <= pivot) {
            swap(arr[i], arr[pos]);
            pos++;
        }
    }

    swap(arr[pos], arr[high]);
    return pos;
}

int main() {
    vector<int> arr = {4,1,3,9,7};

    int n = arr.size();
    
    quickSort(arr,0,n-1);

    for(int x : arr)
        cout << x << " ";
}