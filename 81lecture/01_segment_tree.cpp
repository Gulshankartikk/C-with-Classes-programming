

#include <iostream>
#include <vector>
using namespace std;

class SegmentTree
{
    vector<int> tree; // Segment Tree
    vector<int> arr;  // Original Array
    int n;            // Size of Array

public:
    // Constructor
    SegmentTree(vector<int> input)
    {
        n = input.size();
        arr = input;

        tree.resize(4 * n);

        // Build Segment Tree
        build(0, 0, n - 1);
    }

    // Build Segment Tree
    void build(int node, int start, int end)
    {
        // Leaf node
        if (start == end)
        {
            tree[node] = arr[start];
            return;
        }

        int mid = start + (end - start) / 2;

        // Left child
        build(2 * node + 1, start, mid);

        // Right child
        build(2 * node + 2, mid + 1, end);

        // Sum of left and right child
        tree[node] = tree[2 * node + 1] +
                     tree[2 * node + 2];
    }

    // Range Query
    int range(int node, int start, int end,
              int left, int right)
    {
        // Completely outside the range
        if (end < left || start > right)
            return 0;

        // Completely inside the range
        if (start >= left && end <= right)
            return tree[node];

        int mid = start + (end - start) / 2;

        // Partial overlap
        int leftSum = range(
            2 * node + 1,
            start,
            mid,
            left,
            right);

        int rightSum = range(
            2 * node + 2,
            mid + 1,
            end,
            left,
            right);

        return leftSum + rightSum;
    }

    // Update a single index
    void updating(int node, int start, int end,
                  int idx, int val)
    {
        // Leaf node
        if (start == end)
        {
            arr[idx] = val;
            tree[node] = val;
            return;
        }

        int mid = start + (end - start) / 2;

        // Go to left child
        if (idx <= mid)
        {
            updating(
                2 * node + 1,
                start,
                mid,
                idx,
                val);
        }
        // Go to right child
        else
        {
            updating(
                2 * node + 2,
                mid + 1,
                end,
                idx,
                val);
        }

        // Recalculate current node
        tree[node] = tree[2 * node + 1] +
                     tree[2 * node + 2];
    }

    // Public Query Function
    int query(int left, int right)
    {
        return range(0, 0, n - 1, left, right);
    }

    // Public Update Function
    void update(int idx, int val)
    {
        updating(0, 0, n - 1, idx, val);
    }
};

int main()
{
    vector<int> arr;

    arr.push_back(3);
    arr.push_back(6);
    arr.push_back(4);
    arr.push_back(25);
    arr.push_back(5);
    arr.push_back(13);
    arr.push_back(18);

    SegmentTree *Tree = new SegmentTree(arr);

    // Update index 2: 4 -> 10
    Tree->update(2, 10);

    // Query range [1, 5]
    cout << Tree->query(1, 5) << endl;

    delete Tree;

    return 0;
}





























































/*#include<iostream>
#include<vector>
using namespace std;

class SegmentTree
{
    vector<int>tree; // segment tree
    vector<int>arr;//array
    int n;//size of array
    public:

    SegmentTree(vector<int>input)
    {
      n=input.size();
      arr=input;
      tree.resize(4*n);
      build(0,0,n-1);//Segment tree// root ode index,star,end
    };
    void build(int node,int start,int end)
    {
        if(start==end)
        {
            tree[node]=arr[start];
            return;
        }
        int mid =start+(end-start)/2;
        //left child
         build(2*node+1,start,mid);
        //right child
        build(2*node+2,mid+1,end);

        tree[node] =tree[2*node+1]+tree[2*node+2];
    }
    int range(int node,int start,int end,int left,int right)
    {
        // fully out of range
        if(end<left || start>right)
        return 0;

        //fully in the range
        if(start>=left&&end<=right)
        return tree[node];

        int mid =start+(end=start)/2;
        // ovelaping or partially in the range
        //left child+right child
        return range(2*node+1, start, mid, left, right)+range(2*node+2, mid+1, end, left, right);
    }

    void updating(int node, int start, int end, int idx, int val)
    {
        if(start==end)
        {
            arr[idx]=val;
            tree[node]=val;
            return;
        }
        int mid=start+(end-start)/2;
        if(idx<=mid)
        updating(2*node+1, start, mid, idx, val);
        else
        updating(2*node+2, mid+1, end, idx, val);

        tree[node]=tree[2*node+1]+tree[2*node+2];
    }
    int query(int left,int right)
    {
        return range(0,0,n-1,left,right);// root node index(seg),start end
    }
    void update(int idx,int val)
    {
        arr[idx]=val;
        updating(0,0,n-1,idx,val);
    }
};
int main()
{
    vector<int> arr;
    arr.push_back(3);
    arr.push_back(6);
    arr.push_back(4);
    arr.push_back(25);
    arr.push_back(5);
    arr.push_back(13);
    arr.push_back(18);
    SegmentTree *Tree =new SegmentTree(arr);
    Tree->update(2,10);
    cout<<Tree->query(1,5)<<endl;
    return 0;

}

*/