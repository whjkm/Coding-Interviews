#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
     bool isNumeric(char* str)
     {
         // 标记符号，小数点，e是否出现过
         bool sign = false, decimal = false, hasE = false;
         if(str == NULL) return false;
         for(int i = 0; i < strlen(str); ++i)
         {
             if(str[i] == 'e' || str[i] == 'E')
             {
                 // e后面一定要接数字
                 if(i == strlen(str) - 1)
                    return false;
                 // e不能出现两次
                 if(hasE)
                    return false;
                 hasE = true;
             }
             else if(str[i] == '+' || str[i] == '-')
             {   // 第二次出现+-符号，则必须紧接在e之后
                 if(sign && str[i-1] != 'e' && str[i-1] != 'E')
                    return false;
                // 第一次出现+-符号，且不是在字符串开头，则也必须紧接在e之后
                 if(!sign && i > 0 && str[i-1] != 'e' && str[i-1] != 'E')
                    return false;
                 sign = true;
             }
             else if(str[i] == '.')
             {
                 // e后面不能接小数点， 小数点不能出现两次
                 if(hasE || decimal)
                    return false;
                decimal = true;
             }
             else if(str[i] < '0' || str[i] > '9') // 不合法字符
                return false;
         }
         return true;
     }
};

/***
判断字符串是否是数值。
首先判断是否包含正负号，然后扫描数字；
判断是否是小数,包含'.',扫描数字；
判断是否包含指数'e', 指数中可能还含有正负号；
中间如果包含非法字符直接返回。
***/

/*
class Solution {
public:
    // 扫描数字
    void scanDigits(char **string)
    {
        while(**string != '\0' && **string >= '0' && **string <= '9')
        {
            ++(*string);
        }
    }
    // 判断是否是指数
    bool isExponential(char **string)
    {
        if(**string != 'e' && **string != 'E')
            return false;
        ++(*string);
        if(**string == '+' || **string == '-')
            ++(*string);

        if(**string == '\0')
            return false;

        scanDigits(string);
        return (**string == '\0') ? true : false;
    }

    bool isNumeric(char* string)
    {
        if(string == NULL)
            return false;
        if(*string == '-' || *string == '+')
            ++string;
        if(*string == '\0')
            return false;

        bool numeric = true;

        scanDigits(&string);

        if(*string != '\0')
        {
            if(*string == '.')
            {
                ++string;
                scanDigits(&string);
                if(*string == 'e' || *string == 'E')
                {
                    numeric = isExponential(&string);
                }

            }
            else if(*string == 'e' || *string == 'E')
            {
                numeric = isExponential(&string);
            }
            else
                numeric = false;
        }
        return numeric && *string == '\0';
    }
};
*/


int main()
{
    Solution s;
    char *str = "3.1416\0";
    cout << s.isNumeric(str) << endl;
    return 0;
}
