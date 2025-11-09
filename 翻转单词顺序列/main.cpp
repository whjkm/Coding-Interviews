#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

//LeetCode 151
class Solution {
public:
    string reverseWords(string s) {
        int m = s.size() - 1;
        string res;
        while(s[m] == ' ' && m > 0) m--;

        int n = m;
        while(m >= 0)
        {
            while(m>=0 && s[m]!= ' ') m--;
            res += s.substr(m+1, n-m) + " ";
            while(m>=0 && s[m]== ' ') m--;
            n = m;
        }
        return res.substr(0, res.size()-1);
    }
};


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

// 使用迭代器
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

// 思路：一个一个字符进行处理
/*
class Solution {
public:
    string ReverseSentence(string str) {
        string res = "", tmp = "";
        for(unsigned int i = 0; i < str.size(); ++i)
        {
            if(str[i] == ' ')
            {
                res = " " + tmp + res;   // 遇到空格就在单词前面加上空格，把之前的单词加到后面
                tmp = "";
            }
            else
            {
                tmp += str[i];         // 每一个单词
            }
        }
        if(tmp.size())
            res = tmp + res;      // 最后的单词
        return res;
    }
};
*/

/***
思路：进行两次翻转，首先对整体进行翻转；
然后对单词进行翻转。
***/
/*
class Solution {
public:
    string ReverseSentence(string str) {
        ReverseWord(str, 0, str.size() - 1);    // 整体翻转一次
        int s = 0, e = 0;
        int i = 0;
        while(i < str.size())
        {
            // 遇到空格跳过
            while(str[i] == ' ' && i < str.size())
                i++;
            s = e = i;  // 单词的开始位置
            while(i < str.size() && str[i] != ' ')  // 找到单词结束的位置
            {
                i++;
                e++;
            }
            ReverseWord(str, s, e - 1);      //翻转单词
        }
        return str;
    }
private:
    // 翻转str的s到e部分
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
