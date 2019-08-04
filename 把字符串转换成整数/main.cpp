#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    enum Status{kValid = 0, kInvalid};
    int g_nStatus = kValid;
    int StrToInt(string str) {
        int g_nStatus = kInvalid;     // �жϷǷ�״̬
        int symbol = 1;               // �ж�������
        long long res = 0;
        if(str.size() > 0)            // �ǿ�
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
                    // �ж��Ƿ����
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
                    // ���ַǷ�����
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
�߽�������
�������� ���
���ַ���
ֻ��������
����������
�����־���
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

// ���ַ�תΪ���֣���Ҫ���ǿ�ָ��NULL�����ַ���"",������,����Ȳ���������
/*
class Solution {
public:
    int StrToInt(string str) {
        int n = str.size(), symbol = 1;
        long long res = 0;
        if(!n)  return 0;
        if(str[0] == '-')    // ����
            symbol = -1;
        for(int i = (str[0] == '+' || str[0] == '-') ? 1: 0; i < n; ++i)
        {
            if(!(str[i] >= '0' && str[i] <= '9'))  // �Ƿ��ַ�
                return 0;
        // �����ǳ���2�Ĵη���(res << 1) + (res << 3) = res * 2 + res * 8 = res * 10 ��
        // �ַ�'0'��'9'��asciiֵ�ĵ�4��������λ�պþ���0��9����str[i]&0xf����str[i]-'0'��
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
