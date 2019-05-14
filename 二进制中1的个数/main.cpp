#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

/***
* 思路一：利用位运算，如果n-1不为0，那么n的二进制表示中至少有一位是1；
* 把一个整数减去1，都是把最右边的1变为0；
* 把一个整数和它减去1的结果做位与运算，相当于把它最右边的1变成0；
* 一个整数的二进制有多少个1，就可以进行多少次这样的操作。
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
* 思路二：位运算；
* 一个整数二进制中1的个数，1和1做位与运算的结果为1；
* 相当于把整数中的每一位都和1做位与运算，看能得到多少个为1的结果；
* 具体操作：初始化一个数为flag=1，把它和要求的数做位与运算，然后不断将这个数flag左移，再进行位与运算。
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
