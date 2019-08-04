#include <iostream>
using namespace std;

/***
��������������������ļӷ���ʹ��λ���㡣
�����ӷ���Ϊ������1.����λ�ӷ������� 5 + 17, �� 5 + 7 = 2 (���ӽ�λ), ʮλ��1 + 0 = 0��
2.����λ��5 + 7 �н�λ����λֵΪ10��
3.��ǰ�����õ���ֵ��ӡ�
***/
class Solution
{
public:
    int Add(int num1, int num2)
    {
        int sum = 0, carry = 0;
        do
        {
            sum = num1 ^ num2;              // ����λ�ӷ������
            carry = (num1 & num2) << 1;     // �����λ����������ֻ��ȫΪ1�Ż������λ����λ֮�����ơ�

            num1 = sum;
            num2 = carry;
        }
        while(num2 != 0);                  // ֱ����λ��ֵΪ0
        return sum;
    }
};

int main()
{
    Solution s;
    cout << s.Add(5, 17) << endl;
    return 0;
}
