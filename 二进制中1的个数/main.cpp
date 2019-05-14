#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

/***
* ˼·һ������λ���㣬���n-1��Ϊ0����ôn�Ķ����Ʊ�ʾ��������һλ��1��
* ��һ��������ȥ1�����ǰ����ұߵ�1��Ϊ0��
* ��һ������������ȥ1�Ľ����λ�����㣬�൱�ڰ������ұߵ�1���0��
* һ�������Ķ������ж��ٸ�1���Ϳ��Խ��ж��ٴ������Ĳ�����
***/
class Solution {
public:
     int  NumberOf1(int n) {
         int count = 0;
         while(n){
            count++;
            n = n & (n-1);
         }
         return count;
     }
};


/***
* ˼·����λ���㣻
* һ��������������1�ĸ�����1��1��λ������Ľ��Ϊ1��
* �൱�ڰ������е�ÿһλ����1��λ�����㣬���ܵõ����ٸ�Ϊ1�Ľ����
* �����������ʼ��һ����Ϊflag=1��������Ҫ�������λ�����㣬Ȼ�󲻶Ͻ������flag���ƣ��ٽ���λ�����㡣
***/
/*
class Solution {
public:
     int  NumberOf1(int n) {
         int count = 0;
         unsigned int flag = 1;
         while(flag){
            if(n & flag){
                count++;
            }
            flag = flag << 1;
         }
         return count;
     }
};
*/

int main()
{
    Solution s;
    cout << s.NumberOf1(-1) << endl;
    return 0;
}
