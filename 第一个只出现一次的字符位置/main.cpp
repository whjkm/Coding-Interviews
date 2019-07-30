#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <map>
using namespace std;

/****
思路： 以空间换时间，用hash表存储字母，和字母出现的个数，
遍历两遍字符串，第一遍将元素构建hash表，第二遍从hash表中判断元素出现的次数。
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
    int hashmap[256];  // ASCII码范围
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
