#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    enum Status{kValid = 0, kInvalid};
    int g_nStatus = kValid;
    int StrToInt(string str) {
        int g_nStatus = kInvalid;     // 判断非法状态
        int symbol = 1;               // 判断正负号
        long long res = 0;
        if(str.size() > 0)            // 非空
        {
            if(str[0] == '-')
            {
                symbol = -1;
            }
            for(int i = (str[0] == '+' || str[0] == '-') ? 1: 0; i < str.size(); ++i)
            {
                if(str[i] >= '0' && str[i] <= '9')
                {
                    g_nStatus = kValid;
                    res = (res << 1) + (res << 3) + (str[i] & 0xf);   // res = res*10 + str[i]-'0';
                    // 判断是否溢出
                    if(((symbol > 0) && (res > 0x7FFFFFFF)) ||
                      ((symbol < 0) && (res > 0x80000000)))
                    {
                        g_nStatus = kInvalid;
                        res = 0;
                        break;
                    }
                }
                else
                {
                    // 出现非法符号
                    g_nStatus = kInvalid;
                    res = 0;
                    break;
                }
            }
            if(g_nStatus == kValid)
                res = res * symbol;
        }
        return (int) res;
    }
};

/***
边界条件：
数据上下 溢出
空字符串
只有正负号
有无正负号
错误标志输出
***/
/*
class Solution {
public:
    enum Status{kValid = 0, kInvalid};
    int g_nStatus = kValid;
    int StrToInt(string str) {
        g_nStatus = kInvalid;
        long long num = 0;
        const char* cstr = str.c_str();
        if((cstr != NULL) && (*cstr != '\0'))
        {
            int minus = 1;
            if(*cstr == '-')
            {
                minus = -1;
                cstr++;
            }
            else if(*cstr == '+')
                cstr++;
            while(*cstr != '\0')
            {
                if(*cstr >= '0' && *cstr <= '9')
                {
                    g_nStatus = kValid;
                    num = num * 10 + (*cstr - '0');
                    cstr++;
                    if(((minus > 0) && (num > 0x7FFFFFFF)) ||
                      ((minus < 0) && (num > 0x80000000)))
                    {
                        g_nStatus = kInvalid;
                        num = 0;
                        break;
                    }
                }
                else
                {
                    g_nStatus = kInvalid;
                    num = 0;
                    break;
                }
            }
            if(g_nStatus == kValid)
                num = num * minus;
        }
        return (int) num;
    }
};
*/

// 将字符转为数字，需要考虑空指针NULL，空字符串"",正负号,溢出等测试用例。
/*
class Solution {
public:
    int StrToInt(string str) {
        int n = str.size(), symbol = 1;
        long long res = 0;
        if(!n)  return 0;
        if(str[0] == '-')    // 符号
            symbol = -1;
        for(int i = (str[0] == '+' || str[0] == '-') ? 1: 0; i < n; ++i)
        {
            if(!(str[i] >= '0' && str[i] <= '9'))  // 非法字符
                return 0;
        // 左移是乘以2的次方。(res << 1) + (res << 3) = res * 2 + res * 8 = res * 10 。
        // 字符'0'到'9'的ascii值的低4个二进制位刚好就是0到9所以str[i]&0xf等于str[i]-'0'。
            res = (res << 1) + (res << 3) + (str[i] & 0xf);   // res = res*10 + str[i]-'0';
        }
        return res * symbol;
    }
};
*/
int main()
{
    Solution s;
    cout << s.StrToInt("") << endl;
    return 0;
}
