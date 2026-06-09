#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
using namespace std;

int* solve(int** A, int n11, int n12, int *len1)
{
    vector<int> ans;

    int row = n11;
    int col = n12;

    priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>
    > minheap;

    for(int i = 0; i < row; i++)
        minheap.push(make_pair(A[i][0], make_pair(i,0)));

    pair<int,pair<int,int>> p;

    while(!minheap.empty())
    {
        p = minheap.top();
        minheap.pop();

        ans.push_back(p.first);

        row = p.second.first;
        col = p.second.second;

        if(col < n12 - 1)
            minheap.push(make_pair(A[row][col+1],
                                   make_pair(row,col+1)));
    }

    *len1 = ans.size();

    int *result = (int*)malloc(sizeof(int) * (*len1));

    for(int i = 0; i < *len1; i++)
        result[i] = ans[i];

    return result;
}

int main()
{
    int n11 = 3, n12 = 4;

    int data[3][4] = {
        {1, 4, 7, 10},
        {2, 5, 8, 11},
        {3, 6, 9, 12}
    };

    int** A = new int*[n11];
    for(int i = 0; i < n11; i++)
        A[i] = data[i];

    int len1;

    int* result = solve(A, n11, n12, &len1);

    cout << "Merged Array: ";
    for(int i = 0; i < len1; i++)
        cout << result[i] << " ";

    cout << endl;

    free(result);
    delete[] A;

    return 0;
}