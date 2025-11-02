#include<iostream>
using namespace std;

int main()
{
    int total_rows;
    cin >>total_rows;

    for(int row = 1;row<=total_rows; row++)
    {
        // space
        for(int col = 1;col<=total_rows-row; col++)
         cout<<" ";
        {
            // print "*" with space
            for(int col=1;col<=row;col++)
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}