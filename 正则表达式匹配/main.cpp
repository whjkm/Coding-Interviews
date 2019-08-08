#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

/***
���������
1.ģʽ����һ���ַ�����'*'��ʱ���Ƚϼ򵥣�
�����һ�ַ���ƥ�䣬��ô�ַ�����ģʽ������һλ��
�����ƥ�䣬ֱ�ӷ���false;
2.ģʽ����һ���ַ���'*'��ʱ�����ж��ֿ��ܡ�
����ַ�����һ���ַ���ģʽ��һ���ַ���ƥ�䣬��ģʽ������λ���൱��*ƥ��0λ��������ƥ�䡣
�����һ���ַ���ƥ�䣬�����ִ��������
    1.���԰�ģʽ������λ���൱��x*�����ԡ�
    2.�ַ�������һλ��ģʽ���䣬����ƥ���ַ�����һλ��*����ƥ���λ��
    3.�ַ�������һλ��ģʽ������λ��ƥ����һ���ַ�������*��ģʽ���൱��*ƥ��һ���ַ�����
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
                // ��һ���ַ�ƥ��ɹ���ƥ����һ���ַ�������*��ģʽ���൱��*ƥ��һ���ַ�����
                return matchCore(str + 1, pattern + 2)
                // ģʽ���䣬ƥ����һ���ַ���*����ƥ����
                || matchCore(str + 1, pattern)
                // ��һ���ַ�ƥ��ɹ���ƥ�������*��ģʽ��*ƥ��0λ��
                || matchCore(str, pattern + 2);
            }
            else
                // ��һ���ַ�û��ƥ��ɹ��� ģʽ�ƶ�2λ�� �൱��*ƥ��0λ
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
