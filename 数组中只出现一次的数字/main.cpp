#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/***
思路：两个相同的数异或结果为0，一个数和0异或结果为本身。
如果只有一个数只出现一次，其他数都出现两次，异或的结果就是只出现一次的那个数。
同理，两个数只出现一次，那么最终的结果就是出现一次的两个数的异或结果。
然后根据的结果1所在的最低位，把数组分为两部分，每部分都包含出现一次的数和出现两次的数。
然后分别对两部分异或，得到的就是只出现一次的数。
***/
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.size() < 2)
            return ;
        int res = 0;
        for(int i = 0; i < data.size(); ++i)
        {
            res ^= data[i];
        }
        unsigned int indexof1 = FindFirstBitIs1(res);
        *num1 = *num2 = 0;
        for(int i = 0; i < data.size(); ++i)
        {
            if(Isbit1(data[i], indexof1))
                *num1 ^= data[i];
            else
                *num2 ^= data[i];
        }
        cout << *num1 << *num2 <<endl;
    }

    unsigned int FindFirstBitIs1(int num)
    {
        int indexBit = 0;
        while(((num & 1) == 0) && (indexBit < 8 * sizeof(int)))
        {
            num = num >> 1;
            ++ indexBit;
        }
        return indexBit;
    }
    bool Isbit1(int num, unsigned int indexBit)
    {
        num = num >> indexBit;
        return (num & 1);
    }
};

int main()
{
    vector<int> data = {2,4,3,6,3,2,5,5};
    Solution s;
    int *num1 = 0, *num2 = 0;
    s.FindNumsAppearOnce(data, num1, num2);
    return 0;
}
