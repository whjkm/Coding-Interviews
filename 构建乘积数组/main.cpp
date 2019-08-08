#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 分为两个矩阵
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int n = A.size();
        vector<int> B(n,1);
        if(n == 0) return B;
        B[0] = 1;
        for(int i = 1; i < n; ++i)  // 自上而下
        {
            B[i] = B[i-1] * A[i-1];
        }

        int temp = 1;
        for(int i = n - 2; i >=0; --i)  // 自下而上
        {
            temp *= A[i+1];
            B[i] *= temp;
        }
        return B;
    }
};

int main()
{
    vector<int> A = {1,2,3,4,5,6,7,8};
    Solution s;
    vector<int> B;
    B = s.multiply(A);
    for(int i = 0; i < B.size(); ++i)
    {
        cout << B[i] << endl;
    }
    return 0;
}
