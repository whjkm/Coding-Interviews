#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/***
*思路：Kadane's algorithm
*分析数组的规律，用一个变量记录当前子数组的和，一个变量记录所有子数组和的最大值。
*如果当前子数组和小于0，则重新开始累加。
***/
/*
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.size() == 0) return 0;
        int CurSum, MaxSum;
        CurSum = MaxSum = array[0];
        for(int i = 1; i < array.size(); ++i){
            CurSum = max(array[i], CurSum + array[i]);   // 当前的和
            MaxSum = max(CurSum, MaxSum);       // 记录所有子数组的最大值
        }
        return MaxSum;
    }
};
*/

// 动态规划
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.size() == 0) return 0;
        int dp[array.size()];
        int MaxSum;
        MaxSum = dp[0] = array[0];
        for(int i = 1; i < array.size(); ++i){
            dp[i] = max(array[i], dp[i-1] + array[i]);
            MaxSum = max(MaxSum, dp[i]);
        }
        return MaxSum;
    }
};

int main()
{
    Solution s;
    vector<int> array = {1,-2,3,10,-4,7,2,-5};
    cout << s.FindGreatestSumOfSubArray(array) << endl;
    return 0;
}
