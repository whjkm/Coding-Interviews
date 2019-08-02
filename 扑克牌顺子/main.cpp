#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

/***
max 记录 最大值
min 记录  最小值
min ,max 都不记0
满足条件 1 max - min <5
         2 除0外没有重复的数字(牌)
         3 数组长度 为5

***/
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size() < 5)
            return false;
        int arr[14] = {0};
        memset(arr, 0, sizeof(int));
        int max = -1, min = 14;
        for(int i = 0; i < numbers.size(); ++i)
        {
            arr[numbers[i]]++;
            if(numbers[i] == 0)
            {
                continue;
            }
            if(arr[numbers[i]] > 1)
            {
                return false;
            }
            if(numbers[i] > max)
            {
                max = numbers[i];
            }
            if(numbers[i] < min)
            {
                min = numbers[i];
            }
        }
        cout << max << min << endl;
        if(max - min < 5)
            return true;
        return false;
    }
};


/***
思路：先排序，记录数组中0的个数（大小王的个数）；
然后比较相邻元素的关系，是否有间隔，如果间隔 < 大小王的个数，就可以构成顺子。
***/
/*
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size() <= 0)
            return false;
        sort(numbers.begin(), numbers.end());
        int numOfZero = 0;
        // 统计数组0的个数
        for(int i = 0; i < numbers.size(); ++i)
            if(numbers[i] == 0)
                numOfZero++;
        // 统计数组中的间隔数目
        int small = numOfZero;
        int big = small + 1;
        int numOfGap = 0;
        while(big < numbers.size())
        {
            // 两个数相等，不可能是顺子。
            if(numbers[small] == numbers[big])
                return false;
            // 判断相邻两数的关系
            numOfGap += numbers[big] - numbers[small] - 1;
            small = big;
            ++big;
        }
        if(numOfZero >=  numOfGap)
            return true;
        return false;
    }
};
*/

int main()
{
    vector<int> numbers = {4,2,3,1,5};
    Solution s;
    cout << s.IsContinuous(numbers) << endl;
    return 0;
}
