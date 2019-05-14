#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
/***
*˼·����ֵ�������η���ʹ�ÿ������㷨��n�η���
*����ȫ�棬�����쳣���������λ��������Ч�ʣ�
*ָ��Ϊ���������������Ϊ0�������������֮��ıȽϣ����ȵıȽϡ�
***/
class Solution {
public:
    double Power(double base, int exponent) {
        double ans = 1.0;
        if(equal(base,0) && exponent < 0){
            return 0;         // ����Ϊ0��ָ��Ϊ������������ܷ����쳣��
        }else if(exponent == 0){   // ָ��Ϊ0�����
            return 1;
        }
        int p = abs(exponent);    // ָ��Ϊ�������
        // ��������n�η�
        while(p > 0){
            if(p & 1){
                ans = ans * base;
            }
            p >>= 1;    // ���Ƴ�2
            base *= base;
        }
        return (exponent > 0) ? ans : (1.0 / ans);
    }
    bool equal(double num1, double num2){
        if(num1 - num2 < abs(1e-6))   // ������֮��ľ����㹻С����Ϊ���
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
