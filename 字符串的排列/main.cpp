#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;

/*
思路: 递归
每次固定一位，依次交换后面的元素；
用set去重；
*/
class Solution {
public:
    vector<string> Permutation(string str) {
        if(str.size() != 0){
            int nSize = str.size();
            Permutation(str, nSize, 0);
        }
        // 利用set去重
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
                swap(str[n], str[i]);  // 交换元素
                Permutation(str, nSize, n+1);
                swap(str[n], str[i]);  // 复位
            }
        }
    }
private:
    vector<string> permutation;
    set<string> permutationSet;
};


/*
思路：字典序排序
   【例】如何得到346987521的下一个
    1，从尾部往前找第一个P(i-1) < P(i)的位置
            3 4 6 <- 9 <- 8 <- 7 <- 5 <- 2 <- 1
        最终找到6是第一个变小的数字，记录下6的位置i-1
    2，从i位置往后找到最后一个大于6的数
            3 4 6 -> 9 -> 8 -> 7 5 2 1
        最终找到7的位置，记录位置为m
    3，交换位置i-1和m的值
            3 4 7 9 8 6 5 2 1
    4，倒序i位置后的所有数据
            3 4 7 1 2 5 6 8 9
    则347125689为346987521的下一个排列
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
        //首先对原始数据进行排序
        sort(char_list.begin(), char_list.end());
        for(int i = 0; i < len; ++i){
            str[i] = char_list[i];
        }
        res.push_back(str);

        while(true){
            int l = len - 1;
            int r;
            // 倒序查找第一个变小的位置
            while(l >= 1 && str[l-1] >= str[l]){
                l--;
            }
            if(l == 0)
                break;
            r = l;
            while(r < len && str[r] > str[l-1]){
                r++;
            }
            // 交换位置
            swap(str[l-1], str[r-1]);
            // 逆序
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
