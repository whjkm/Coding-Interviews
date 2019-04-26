#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

/***
*˼·��쳲��������֣�쳲������ⷨ���Բο���7��;
*����ֱ����F(n)�����n���ж�������������ÿ�ο�����1��¥�ݻ�2��¥�ݣ�
*����F(n)����������һ��¥�ݻ�2��¥�ݵõ��ģ�
*���Եõ�F(n)=F(n-1)+F(n-2)�������ת��ΪF(n-1)��F(n-2)�������ˡ�
***/

class Solution {
public:
    int jumpFloor(int number) {
        vector<int> result(number+1, 1);
        result[1] = 1;
        for(int i=2; i<=number; i++){
            result[i] = result[i-1] + result[i-2];
        }
        return result[number];
    }
};

int main()
{
    Solution s;
    cout << s.jumpFloor(5) << endl;
    return 0;
}
