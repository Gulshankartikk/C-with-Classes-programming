#include<iostream>
#include<vector>
using namespace std;

int main()
{
 int low = 0;
        int high = arr.size() - 1;

        while (low <= high) {
            if (arr[low] == 0) {
                low++;
            } else {
                swap(arr[low], arr[high]);
                high--;
            }
        }
}