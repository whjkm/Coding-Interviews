#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// ԭ��YX = (XTY T)T
class Solution {
public:
    string LeftRotateString(string str, int n) {
        int length = str.size();
        if(length == 0) return "";
        n %= length;
        for(int i = 0, j = n - 1; i < j; ++i, --j) swap(str[i], str[j]);
        for(int i = n, j = length - 1; i < j; ++i, --j) swap(str[i], str[j]);
        for(int i = 0, j = length - 1; i < j; ++i, --j) swap(str[i], str[j]);
        return str;
    }
};

// ˼·����ԭ�ַ�����ӵ��ַ�����ĩβ��Ȼ���n��ʼ��ȡ����Ϊlength���ַ�����
/*
class Solution {
public:
    string LeftRotateString(string str, int n) {
        int length = str.size();
        if(length == 0)  return "";
        n = n % length;
        str += str;
        return str.substr(n, length);
    }
};
*/
/*
class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(str.size() == 0) return "";
        n %= str.size();
        reverse(str.begin(), str.begin() + n);
        reverse(str.begin() + n, str.end());
        reverse(str.begin(), str.end());
        return str;
    }
};
*/

int main()
{
    string str = "abcdefg";
    Solution s;
    string res = s.LeftRotateString(str, 2);
    cout << res << endl;
    return 0;
}
