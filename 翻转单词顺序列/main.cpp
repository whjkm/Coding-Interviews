#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {
        reverse(str.begin(), str.end());
        string::size_type s = 0, e;
        while((e = str.find(' ', s)) != string::npos)
        {
            reverse(str.begin() + s, str.begin() + e);
            s = e + 1;
        }
        reverse(str.begin() + s, str.end());
        return str;
    }
};

// ʹ�õ�����
/*
class Solution {
public:
    string ReverseSentence(string str) {
        reverse(str.begin(), str.end());
        string::iterator it = str.begin();
        string::iterator s = str.begin(),  e = str.begin();
        while(it != str.end())
        {
            while(it != str.end() && *it == ' ')
                it++;
            s = e = it;
            while(it != str.end() && *it != ' ')
            {
                it++;
                e++;
            }
            reverse(s, e);
        }
        return str;
    }
};
*/

// ˼·��һ��һ���ַ����д���
/*
class Solution {
public:
    string ReverseSentence(string str) {
        string res = "", tmp = "";
        for(unsigned int i = 0; i < str.size(); ++i)
        {
            if(str[i] == ' ')
            {
                res = " " + tmp + res;   // �����ո���ڵ���ǰ����Ͽո񣬰�֮ǰ�ĵ��ʼӵ�����
                tmp = "";
            }
            else
            {
                tmp += str[i];         // ÿһ������
            }
        }
        if(tmp.size())
            res = tmp + res;      // ���ĵ���
        return res;
    }
};
*/

/***
˼·���������η�ת�����ȶ�������з�ת��
Ȼ��Ե��ʽ��з�ת��
***/
/*
class Solution {
public:
    string ReverseSentence(string str) {
        ReverseWord(str, 0, str.size() - 1);    // ���巭תһ��
        int s = 0, e = 0;
        int i = 0;
        while(i < str.size())
        {
            // �����ո�����
            while(str[i] == ' ' && i < str.size())
                i++;
            s = e = i;  // ���ʵĿ�ʼλ��
            while(i < str.size() && str[i] != ' ')  // �ҵ����ʽ�����λ��
            {
                i++;
                e++;
            }
            ReverseWord(str, s, e - 1);      //��ת����
        }
        return str;
    }
private:
    // ��תstr��s��e����
    void ReverseWord(string &str, int s, int e)
    {
        while(s < e)
        {
            swap(str[s++], str[e--]);
        }
    }
};
*/

int main()
{
    string str = "student. a am I";
    string res;
    Solution s;
    res = s.ReverseSentence(str);
    cout << res << endl;
    return 0;
}
