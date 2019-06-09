#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;

/*
˼·: �ݹ�
ÿ�ι̶�һλ�����ν��������Ԫ�أ�
��setȥ�أ�
*/
class Solution {
public:
    vector<string> Permutation(string str) {
        if(str.size() != 0){
            int nSize = str.size();
            Permutation(str, nSize, 0);
        }
        // ����setȥ��
        for(set<string>::iterator iter = permutationSet.begin(); iter != permutationSet.end(); ++iter){
            permutation.push_back(*iter);
        }
        return permutation;
    }
    void Permutation(string str, int nSize, int n){
        if(n == nSize){
            permutationSet.insert(str);
        }
        else{
            for(int i = n; i < nSize; ++i){
                swap(str[n], str[i]);  // ����Ԫ��
                Permutation(str, nSize, n+1);
                swap(str[n], str[i]);  // ��λ
            }
        }
    }
private:
    vector<string> permutation;
    set<string> permutationSet;
};


/*
˼·���ֵ�������
   ��������εõ�346987521����һ��
    1����β����ǰ�ҵ�һ��P(i-1) < P(i)��λ��
            3 4 6 <- 9 <- 8 <- 7 <- 5 <- 2 <- 1
        �����ҵ�6�ǵ�һ����С�����֣���¼��6��λ��i-1
    2����iλ�������ҵ����һ������6����
            3 4 6 -> 9 -> 8 -> 7 5 2 1
        �����ҵ�7��λ�ã���¼λ��Ϊm
    3������λ��i-1��m��ֵ
            3 4 7 9 8 6 5 2 1
    4������iλ�ú����������
            3 4 7 1 2 5 6 8 9
    ��347125689Ϊ346987521����һ������
*/
/*
class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        int len = str.length();
        if(len == 0) return res;
        vector<char> char_list;
        for(int i = 0; i < len; ++i){
            char_list.push_back(str[i]);
        }
        //���ȶ�ԭʼ���ݽ�������
        sort(char_list.begin(), char_list.end());
        for(int i = 0; i < len; ++i){
            str[i] = char_list[i];
        }
        res.push_back(str);

        while(true){
            int l = len - 1;
            int r;
            // ������ҵ�һ����С��λ��
            while(l >= 1 && str[l-1] >= str[l]){
                l--;
            }
            if(l == 0)
                break;
            r = l;
            while(r < len && str[r] > str[l-1]){
                r++;
            }
            // ����λ��
            swap(str[l-1], str[r-1]);
            // ����
            for(int i = l, j = len -1; i < j; i++, j--){
                swap(str[i], str[j]);
            }
            res.push_back(str);
        }
        return res;
    }
};
*/

int main()
{
    Solution s;
    string str = "abc";
    vector<string> res;
    res = s.Permutation(str);
    for(int i = 0; i != res.size(); i++){
        cout << res[i] << endl;
    }
    return 0;
}
