#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

/***
两种情况：
1.模式的下一个字符不是'*'号时：比较简单；
如果第一字符相匹配，那么字符串和模式都后移一位，
如果不匹配，直接返回false;
2.模式的下一个字符是'*'号时：又有多种可能。
如果字符串第一个字符和模式第一个字符不匹配，把模式后移两位（相当于*匹配0位），继续匹配。
如果第一个字符相匹配，有三种处理情况：
    1.可以把模式后移两位，相当于x*被忽略。
    2.字符串后移一位，模式不变，继续匹配字符串的一位，*可以匹配多位。
    3.字符串后移一位，模式后移两位，匹配下一个字符和跳过*的模式（相当于*匹配一个字符）。
***/

class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if(str == NULL || pattern == NULL)
            return false;
        return matchCore(str, pattern);
    }
    bool matchCore(char* str, char* pattern)
    {
        if(*str == '\0' && *pattern == '\0')
            return true;
        if(*str != '\0' && *pattern == '\0')
            return false;
        if(*(pattern + 1) == '*')
        {
            if(*pattern == *str || (*pattern == '.' && *str != '\0'))
            {
                // 第一个字符匹配成功，匹配下一个字符和跳过*的模式（相当于*匹配一个字符）。
                return matchCore(str + 1, pattern + 2)
                // 模式不变，匹配下一个字符，*可以匹配多个
                || matchCore(str + 1, pattern)
                // 第一个字符匹配成功，匹配和跳过*的模式，*匹配0位。
                || matchCore(str, pattern + 2);
            }
            else
                // 第一个字符没有匹配成功， 模式移动2位， 相当于*匹配0位
                return match(str, pattern + 2);

        }
        if(*str == *pattern || (*pattern == '.' && *str != '\0'))
        {
            return matchCore(str + 1, pattern + 1);
        }
        return false;
    }
};

int main()
{
    Solution s;
    char *str = "aaa\0";
    char *pattern = "ab*ac*a\0";
    cout << s.match(str, pattern) << endl;
    return 0;
}
