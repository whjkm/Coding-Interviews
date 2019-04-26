#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
/***
*˼·������쳲������ı��֣�
*����f(n)����2*n�ľ����ж����и��Ƿ�����
*���������߿�ʼ���ǣ�����������2*1�ľ������ŷ�,�Ǿͻ���f(n-1)�֣�
*���2*1�ľ�����ŷţ���ô����ߵ�2*2�ľ����ȷ���ˣ�ֻ��������2*1�ľ�����ŷţ�
*�Ǿͻ���f(n-2)�֣�����f(n) = f(n-1) + f(n-2), f(1) = 1, f(2) = 2;
***/

class Solution {
public:
    int rectCover(int number) {
        if(number <= 0){
            return 0;
        }
        vector<int> result(number+1, 1);
        for(int i=2; i<=number; i++){
            result[i] = result[i-1] + result[i-2];
        }
        return result[number];
    }
};

int main()
{
    Solution s;
    cout << s.rectCover(2) << endl;
    return 0;
}
