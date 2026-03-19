#include <iostream>
using namespace std;

int main()
{
    // ✅ Array must be sorted for binary search to work correctly
    int nums[10] = {2, 3, 6, 24, 45, 65, 65, 74, 74, 75}; 
    int target = 6;

    int start = 0, end = 9, mid;
    while (start <= end)
    {
        mid = (start + end) / 2;

        if (nums[mid] == target)
        {
            cout << "Target found at index: " << mid << endl;
            return 0;
        }
        else if (nums[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    cout << "Target not found" << endl;
    return -1; // ✅ Correct return type
}
