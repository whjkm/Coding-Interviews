#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/***
˼·��˫ָ�뷨
���е���������ͷβ����ָ�룬start, end;
���array[start] + array[end] == sum, ���Ǵ𰸣����ԽԶ�˻�ԽС��;
��array[start] + array[end] < sum, start++, ����Ѱ�Ҹ��������
��array[start] + array[end] > sum, end--, ����Ѱ��Сһ�������
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
