#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/***
˼·��������ͬ���������Ϊ0��һ������0�����Ϊ����
���ֻ��һ����ֻ����һ�Σ����������������Σ����Ľ������ֻ����һ�ε��Ǹ�����
ͬ��������ֻ����һ�Σ���ô���յĽ�����ǳ���һ�ε����������������
Ȼ����ݵĽ��1���ڵ����λ���������Ϊ�����֣�ÿ���ֶ���������һ�ε����ͳ������ε�����
Ȼ��ֱ����������򣬵õ��ľ���ֻ����һ�ε�����
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
