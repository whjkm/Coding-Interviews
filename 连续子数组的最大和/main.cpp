#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/***
*˼·��Kadane's algorithm
*��������Ĺ��ɣ���һ��������¼��ǰ������ĺͣ�һ��������¼����������͵����ֵ��
*�����ǰ�������С��0�������¿�ʼ�ۼӡ�
***/
/*
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.size() == 0) return 0;
        int CurSum, MaxSum;
        CurSum = MaxSum = array[0];
        for(int i = 1; i < array.size(); ++i){
            CurSum = max(array[i], CurSum + array[i]);   // ��ǰ�ĺ�
            MaxSum = max(CurSum, MaxSum);       // ��¼��������������ֵ
        }
        return MaxSum;
    }
};
*/

// ��̬�滮
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
