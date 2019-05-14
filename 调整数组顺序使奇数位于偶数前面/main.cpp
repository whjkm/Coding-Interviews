#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
/***
*解法一：类似于冒泡排序的思想，依次比较两个相邻的元素，遇到偶数在奇数前面，就将两个值交换。
***/
/*
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if(array.size() == 0){
            return ;
        }
        for(vector<int>::size_type i = 0; i != array.size(); i++){
            for(vector<int>::size_type j = array.size()-1; j > i; j--){
                if(!isEven(array[j]) && isEven(array[j-1])){
                    swap(array[j], array[j-1]);
                }
            }
        }
    }
    bool isEven(int n){
        return (n & 1) == 0;
    }
};
*/

/***
*思路2：利用空间换时间；
*使用一个新的vector存储,遍历原来的vector,依次将奇数和偶数存储到新的vector中。
***/
/*
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> res;
        for(vector<int>::iterator iter = array.begin(); iter != array.end(); iter++){
            if((*iter) & 1){
                res.push_back(*iter);
            }
        }
        for(vector<int>::iterator iter = array.begin(); iter != array.end(); iter++){
             if(((*iter) & 1)== 0){
                res.push_back(*iter);
            }
        }
        array = res;
    }
};
*/

/***
思路三：利用STL库函数stable_partition;
***/
/*
bool isEven(int n){
        return (n & 1) == 1;
}
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        stable_partition(array.begin(), array.end(),isEven);
    }
};
*/

/***
*剑指offer上解法：将奇数调整到偶数之前，没有考虑相对位置：
***/
/*
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if(array.size() == 0){
            return ;
        }
        int i = 0, j = array.size() - 1;
        while(i < j){
            while(i < j && !isEven(array[i])){
                i++;
            }
            while(i < j && isEven(array[j])){
                j--;
            }
            if(i < j){
                swap(array[i], array[j]);
            }
        }
    }
    bool isEven(int n){
        return (n & 1) == 0;
    }
};
*/


int main()
{
    vector<int> array;
    Solution s;
    int a;
    while(cin >> a){
        array.push_back(a);
        if(cin.get() == '\n')
            break;
    }
    s.reOrderArray(array);

    for(vector<int>::iterator iter = array.begin(); iter != array.end(); ++iter){
        cout << *iter << endl;
    }
    return 0;
}
