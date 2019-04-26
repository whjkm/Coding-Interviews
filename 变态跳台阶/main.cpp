#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

/***
˼·2��������ѧ���ɷ��Ƶ���
����f(n)Ϊn��̨�׵���������f(1) = 1, f(2) = f(2-1) + f(2-2)��
f(3) = f(3-1) + f(3-2) + f(3-3) ����ѡ����1�ף�2�ף�3�ף�
��ôf(n) = f(n-1) + f(n-2) + f(n-3) +...+ f(n-n)
         = f(0) + f(1) + f(2) + ... + f(n-1)
�������ƣ�f(n-1) = f(0) + f(1) + .... + f(n-2)
���Եõ���f(n) - f(n-1) = f(n-1) ->  f(n) = 2*f(n-1)
f(0) = 1, f(1) = 1;
***/

class Solution {
public:
    int jumpFloorII(int number) {
        if(number <= 0){
            return 0;
        }else if(number == 1){
            return 1;
        }else{
            return 2 * jumpFloorII(number - 1);
        }
    }
};

/***
*˼·1:�ܹ���n��̨�ף��������һ��̨���⣨���һ�ױ���������
*����n-1�׶������ֿ��ܣ�����ѡ����������
*�����ܵ�����Ϊ��2^(n-1)�֡�
***/
/*
class Solution {
public:
    int jumpFloorII(int number) {
        if(number <=0){
            return 0;
        }else{
            return 1<<(number - 1);  //�������Ƴ�2
        }
    }
};
*/

int main()
{
    Solution s;
    cout << s.jumpFloorII(3) << endl;
    return 0;
}
