#include <iostream>
#include <vector>
using namespace std;

/***
*�ο���https://www.cnblogs.com/nailperry/p/4752987.html
*˼·������Ҫ����һ�㣺
*1~10: �����ǵĸ�λ�У�x����1��(x��ȡ1~9)��
*1~100: �����ǵ�ʮλ�У�x����10�Σ�
*1~1000: �����ǵİ�λ�У�x����100�Σ�
*�������ƣ�1~10^i: �����ǵ������ڶ�λ��������iλ����x������10^i-2�Ρ�
*�õ��������£�
*1.�����iλ����λ��ʼ��Ϊ0�����iλ���ܳ���1�Ĵ����ɸ���λ���������ڸ�λ����x��ǰλ����Ȩ��10^i-1��
*2.�����iλ����1�����iλ���ܳ���1�Ĵ��������ܸ���λӰ�죬���ܵ���λӰ�죬���ڸ�λ����x��ǰλ����Ȩ��10^i-1 + ��λ����x+1��
*3.�����iλ����1�����iλ���ܳ���1�Ĵ������ɸ���λ���������ڸ�λ����x+1��ǰλ����Ȩ��10^i-1��
***/

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int count = 0;
        int i = 1;     // ��ǰλ�����Ӹ�λ��ʼ
        int current = 0, high = 0, low = 0;
        while((n/i) != 0){
            current = (n/i) % 10;      // ��ǰλ��������
            high = n / (i*10);         // ��λ������
            low = n - (n/i)*i;         // ��λ������
            if(current == 1){
                count += high * i + low + 1;
            }else if(current == 0){   // С��1
                count += high * i;
            }else{
                count += (high + 1) * i;
            }
            i *= 10;
        }
        return count;
    }
};

int main()
{
    Solution s;
    cout << s.NumberOf1Between1AndN_Solution(12013) << endl;
    return 0;
}
