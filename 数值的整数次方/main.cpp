#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
/***
*思路：数值的整数次方；使用快速幂算法求n次方；
*考虑全面，考虑异常等情况，用位运算提升效率；
*指数为负数的情况，底数为0的情况，浮点数之间的比较，精度的比较。
***/
class Solution {
public:
    double Power(double base, int exponent) {
        double ans = 1.0;
        if(equal(base,0) && exponent < 0){
            return 0;         // 底数为0，指数为负的情况，可能发生异常。
        }else if(exponent == 0){   // 指数为0的情况
            return 1;
        }
        int p = abs(exponent);    // 指数为负的情况
        // 快速幂求n次方
        while(p > 0){
            if(p & 1){
                ans = ans * base;
            }
            p >>= 1;    // 左移除2
            base *= base;
        }
        return (exponent > 0) ? ans : (1.0 / ans);
    }
    bool equal(double num1, double num2){
        if(num1 - num2 < abs(1e-6))   // 浮点数之间的精度足够小就认为相等
            return true;
        else
            return false;
    }
};


/*
class Solution {
public:
    double Power(double base, int exponent) {
        double ans = 1.0;
        if(exponent < 0){
            exponent = abs(exponent);
            ans = calPow(base, exponent);
            return 1 / ans;
        }else if(exponent == 0){
            return 1;
        }else{
            return calPow(base, exponent);
        }
    }
    double calPow(double base, int exponent){
         double ans = 1.0;
         while(exponent > 0){
            if(exponent & 1){
                ans = ans * base;
            }
            exponent = exponent / 2;
            base = base * base;
        }
        return ans;
    }
};
*/


int main()
{
    Solution s;
    cout << s.Power(0, -4) << endl;
    return 0;
}
