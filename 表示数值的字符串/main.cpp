#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
     bool isNumeric(char* str)
     {
         // ��Ƿ��ţ�С���㣬e�Ƿ���ֹ�
         bool sign = false, decimal = false, hasE = false;
         if(str == NULL) return false;
         for(int i = 0; i < strlen(str); ++i)
         {
             if(str[i] == 'e' || str[i] == 'E')
             {
                 // e����һ��Ҫ������
                 if(i == strlen(str) - 1)
                    return false;
                 // e���ܳ�������
                 if(hasE)
                    return false;
                 hasE = true;
             }
             else if(str[i] == '+' || str[i] == '-')
             {   // �ڶ��γ���+-���ţ�����������e֮��
                 if(sign && str[i-1] != 'e' && str[i-1] != 'E')
                    return false;
                // ��һ�γ���+-���ţ��Ҳ������ַ�����ͷ����Ҳ���������e֮��
                 if(!sign && i > 0 && str[i-1] != 'e' && str[i-1] != 'E')
                    return false;
                 sign = true;
             }
             else if(str[i] == '.')
             {
                 // e���治�ܽ�С���㣬 С���㲻�ܳ�������
                 if(hasE || decimal)
                    return false;
                decimal = true;
             }
             else if(str[i] < '0' || str[i] > '9') // ���Ϸ��ַ�
                return false;
         }
         return true;
     }
};

/***
�ж��ַ����Ƿ�����ֵ��
�����ж��Ƿ���������ţ�Ȼ��ɨ�����֣�
�ж��Ƿ���С��,����'.',ɨ�����֣�
�ж��Ƿ����ָ��'e', ָ���п��ܻ����������ţ�
�м���������Ƿ��ַ�ֱ�ӷ��ء�
***/

/*
class Solution {
public:
    // ɨ������
    void scanDigits(char **string)
    {
        while(**string != '\0' && **string >= '0' && **string <= '9')
        {
            ++(*string);
        }
    }
    // �ж��Ƿ���ָ��
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
