#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
/***
思路：双指针法
先统计字符串中空格的数量，用一个指针j记录替换的长度，一个指针i记录原字符串长度；
从后往前遍历，遇到空格，将j移动3步，将“%20”插入;
不是空格，两个指针同时向前移动。
***/
class Solution {
public:
	void replaceSpace(char *str, int length) {
	    if(str == NULL || length <= 0){
            return ;
	    }
	    int countSpace = 0,len = 0;
	    for(int i=0; str[i] != '\0'; i++){
            if(str[i] == ' ')
                countSpace++;
            len++;
	    }
	    int i = len, j = countSpace*2 + len;
	    while(i >= 0 && j > i){
            if(str[i] == ' '){
                str[j--] = '0';
                str[j--] = '2';
                str[j--] = '%';
            }
            else{
                str[j--] = str[i];
            }
            i--;
	    }
	}
};

int main()
{
    Solution s;
    char str[15] = "We are happy.";
    s.replaceSpace(str, 15);
    cout << str << endl;
    return 0;
}
