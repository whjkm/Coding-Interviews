#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/***
˫ָ�뷨����ʼ������ָ��small = 1, big =2;
�����small ��big �����еĺʹ���s,���ǿ��Դ�������ȥ����С��ֵ,Ҳ��������small��ֵ��
�����small ��big �����еĺ�С��s,���ǿ�������big��
***/
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        //������㣬�൱�ڶ�̬���ڵ����ߣ������䴰���ڵ�ֵ�ĺ���ȷ�����ڵ�λ�úʹ�С
        int small = 1, big = 2;
        vector<vector<int>> res;
        vector<int> tmp;
        while(big > small)
        {
            //�����������ģ���Ϊ1��һ�����У���ô��͹�ʽ��(a0+an)*n/2
            int curSum = (small + big) * (big - small + 1) / 2;
            //��ȣ���ô�ͽ����ڷ�Χ����������ӽ������
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
            //�����ǰ�����ڵ�ֵ֮��С��sum����ô�ұߴ�������һ��
            else if(curSum < sum)
            {
                big++;
            }
            //�����ǰ�����ڵ�ֵ֮�ʹ���sum����ô��ߴ�������һ��
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
