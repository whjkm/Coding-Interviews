#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

// 使用Hash
class Solution {
public:
    bool duplicate(int numbers[], int length, int* duplication) {
        unordered_map<int, int> mp;
        if(numbers == NULL || length <= 0)
        {
            return false;
        }
        for(int i = 0; i < length; ++i)
        {
            if(numbers[i] < 0 || numbers[i] > length-1)
                return false;
        }
        for(int i = 0; i < length; ++i)
        {
            mp[numbers[i]]++;
            if(mp[numbers[i]] > 1)
            {
                *duplication = numbers[i];
                return true;
            }
        }
        return false;
    }
};


/***
思路：因为数组中的数字都在0~n-1的范围内。如果这个数组中没有重复的数字，那么当数组排序后；
那么数字i将出现在下标为i的位置。
重排这个数组，从头到尾依次扫描整个数组中的每个数组。当扫描到下标为i的数字时，
首先比较这个数字（m）是不是等于i；如果是，比较下一个;如果不是，比较它和第m个数字；
如果它和第m个数字相等，就找到了第一个重复的数字。如果不相等，就交换两个数，然后再重复这个过程。
***/
/*
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if(numbers == NULL || length <= 0)
        {
            return false;
        }
        for(int i = 0; i < length; ++i)
        {
            if(numbers[i] < 0 || numbers[i] > length-1)
                return false;
        }
        for(int i = 0; i < length; ++i)
        {
            while(numbers[i] != i)
            {
                if(numbers[i] == numbers[numbers[i]])
                {
                    *duplication = numbers[i];
                    return true;
                }
                swap(numbers[i], numbers[numbers[i]]);
            }
        }
        return false;
    }
};
*/

int main()
{
    Solution s;
    int numbers[7] = {2,3,1,0,4,5,3};
    int duplication = 0;
    cout << s.duplicate(numbers, 7, &duplication) << endl;
    cout << duplication << endl;
    return 0;
}
