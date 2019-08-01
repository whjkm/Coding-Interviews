#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/***
思路：双指针法
数列递增，设置头尾两个指针，start, end;
如果array[start] + array[end] == sum, 就是答案（相差越远乘积越小）;
若array[start] + array[end] < sum, start++, 右移寻找更大的数；
若array[start] + array[end] > sum, end--, 左移寻找小一点的数。
***/

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {
        int start = 0, end = array.size() - 1;
        vector<int> res;
        while(start < end)
        {
            int CurSum = array[start] + array[end];
            if(CurSum == sum)
            {
                res.push_back(array[start]);
                res.push_back(array[end]);
                break;
            }
            else if(CurSum > sum)
            {
                end--;
            }
            else
            {
                start++;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> array = {1,2,4,7,11,15};
    vector<int> res;
    Solution s;
    res = s.FindNumbersWithSum(array, 15);
    for(int i = 0; i < res.size(); ++i)
    {
        cout << res[i] << endl;
    }
    return 0;
}
