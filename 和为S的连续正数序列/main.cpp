#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/***
双指针法：初始化两个指针small = 1, big =2;
如果从small 到big 的序列的和大于s,我们可以从序列中去掉较小的值,也就是增大small的值；
如果从small 到big 的序列的和小于s,我们可以增大big。
***/
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        //两个起点，相当于动态窗口的两边，根据其窗口内的值的和来确定窗口的位置和大小
        int small = 1, big = 2;
        vector<vector<int>> res;
        vector<int> tmp;
        while(big > small)
        {
            //由于是连续的，差为1的一个序列，那么求和公式是(a0+an)*n/2
            int curSum = (small + big) * (big - small + 1) / 2;
            //相等，那么就将窗口范围的所有数添加进结果集
            if(curSum == sum)
            {
                tmp.clear();
                for(int i = small; i <= big; ++i)
                {
                    tmp.push_back(i);
                }
                res.push_back(tmp);
                small++;
            }
            //如果当前窗口内的值之和小于sum，那么右边窗口右移一下
            else if(curSum < sum)
            {
                big++;
            }
            //如果当前窗口内的值之和大于sum，那么左边窗口右移一下
            else
            {
                small++;
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> res;
    Solution s;
    res = s.FindContinuousSequence(15);
    for(int i = 0; i < res.size(); ++i)
        for(int j =0; j < res[i].size(); ++j)
            cout << res[i][j] << endl;
    return 0;
}
