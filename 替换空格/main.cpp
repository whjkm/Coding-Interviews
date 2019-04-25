#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
/***
˼·��˫ָ�뷨
��ͳ���ַ����пո����������һ��ָ��j��¼�滻�ĳ��ȣ�һ��ָ��i��¼ԭ�ַ������ȣ�
�Ӻ���ǰ�����������ո񣬽�j�ƶ�3��������%20������;
���ǿո�����ָ��ͬʱ��ǰ�ƶ���
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
