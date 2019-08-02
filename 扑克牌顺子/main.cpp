#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

/***
max ��¼ ���ֵ
min ��¼  ��Сֵ
min ,max ������0
�������� 1 max - min <5
         2 ��0��û���ظ�������(��)
         3 ���鳤�� Ϊ5

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
˼·�������򣬼�¼������0�ĸ�������С���ĸ�������
Ȼ��Ƚ�����Ԫ�صĹ�ϵ���Ƿ��м���������� < ��С���ĸ������Ϳ��Թ���˳�ӡ�
***/
/*
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size() <= 0)
            return false;
        sort(numbers.begin(), numbers.end());
        int numOfZero = 0;
        // ͳ������0�ĸ���
        for(int i = 0; i < numbers.size(); ++i)
            if(numbers[i] == 0)
                numOfZero++;
        // ͳ�������еļ����Ŀ
        int small = numOfZero;
        int big = small + 1;
        int numOfGap = 0;
        while(big < numbers.size())
        {
            // ��������ȣ���������˳�ӡ�
            if(numbers[small] == numbers[big])
                return false;
            // �ж����������Ĺ�ϵ
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
