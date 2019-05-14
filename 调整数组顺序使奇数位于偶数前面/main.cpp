#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
/***
*�ⷨһ��������ð�������˼�룬���αȽ��������ڵ�Ԫ�أ�����ż��������ǰ�棬�ͽ�����ֵ������
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
*˼·2�����ÿռ任ʱ�䣻
*ʹ��һ���µ�vector�洢,����ԭ����vector,���ν�������ż���洢���µ�vector�С�
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
˼·��������STL�⺯��stable_partition;
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
*��ָoffer�Ͻⷨ��������������ż��֮ǰ��û�п������λ�ã�
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
