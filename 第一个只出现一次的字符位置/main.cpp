#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <map>
using namespace std;

/****
˼·�� �Կռ任ʱ�䣬��hash��洢��ĸ������ĸ���ֵĸ�����
���������ַ�������һ�齫Ԫ�ع���hash���ڶ����hash�����ж�Ԫ�س��ֵĴ�����
****/
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.size() == 0) return -1;
        map<char, int> res;
        for(int i = 0; i < str.size(); ++i){
            res[str[i]] ++;
        }
        for(int i = 0; i < str.size(); ++i){
            if(res[str[i]] == 1)
                return i;
        }
        return -1;
    }
};


/*
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.empty()) return -1;
        for(auto i = 0; i < str.size(); ++i){
            if(str.find(str[i]) == str.rfind(str[i]))
                return i;
        }
        return -1;
    }
};
*/

/*
class Solution {
public:
    int hashmap[256];  // ASCII�뷶Χ
    int FirstNotRepeatingChar(string str) {
        memset(hashmap, 0 , sizeof(hashmap));
        for(int i = 0; i < str.length(); ++i) hashmap[int(str[i])]++;
        for(int i = 0; i < str.length(); ++i){
            if(hashmap[int(str[i])] == 1)
                return i;
        }
        return -1;
    }
};
*/


int main()
{
    Solution s;
    string str = "hello world";
    cout << s.FirstNotRepeatingChar(str) << endl;
    return 0;
}
