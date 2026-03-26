#include <iostream>
#include <stack>
#include <vector>   // ✅ required
using namespace std;

class Solution {
  public:
    int maxEqualSum(int N1, int N2, int N3, vector<int> &S1, vector<int> &S2,
                    vector<int> &S3) {
        
        int sum1 = 0, sum2 = 0, sum3 = 0;
        
        for(int i = 0; i < N1; i++) sum1 += S1[i];
        for(int i = 0; i < N2; i++) sum2 += S2[i];
        for(int i = 0; i < N3; i++) sum3 += S3[i];
        
        int i = 0, j = 0, k = 0;
        
        while(i < N1 && j < N2 && k < N3) {
            
            if(sum1 == sum2 && sum2 == sum3)
                return sum1;
            
            if(sum1 >= sum2 && sum1 >= sum3)
                sum1 -= S1[i++];
            else if(sum2 >= sum1 && sum2 >= sum3)
                sum2 -= S2[j++];
            else
                sum3 -= S3[k++];
        }
        
        return 0;
    }
};

int main() {
    vector<int> S1 = {3, 2, 1, 1, 1};
    vector<int> S2 = {4, 3, 2};
    vector<int> S3 = {1, 1, 4, 1};

    int N1 = S1.size();
    int N2 = S2.size();
    int N3 = S3.size();

    Solution obj;
    int result = obj.maxEqualSum(N1, N2, N3, S1, S2, S3);

    cout << "Maximum Equal Sum: " << result << endl;

    return 0;
}