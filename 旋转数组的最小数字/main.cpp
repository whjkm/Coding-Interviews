#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

/***
˼·�����ö��ֲ��ҵ�˼�롣
��Ϊ������һ���ź�������飬��ת֮����Է�Ϊ�����֣�ǰ�������ֻ�������ģ�
�������ö��ֲ��ҵ�˼·����С���ҵķ�Χ��
���array[mid] > array[end], ˵����СԪ�صķ�Χ��mid+1��end֮�䣬mid��ǰ�벿�ֵ����������С�
���array[start] > array[mid],˵����СԪ�صķ�Χ��start��mid֮�䣬˵����벿��������ġ�
�������array[start]==array[mid],����Ԫ����ȵ�����������жϣ�ֻ��˳������ˡ�
***/

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
       int begin = 0, end = rotateArray.size() - 1, mid = begin;
       if(rotateArray.size() == 0){
            return 0;
        }
       while(begin < end){
         mid = begin + (end - begin) / 2;
         if(rotateArray[end] < rotateArray[mid]){
            begin = mid + 1;
         }
         else if(rotateArray[begin] > rotateArray[mid]){
            end = mid;
         }
         else {
            end--;
         }
       }
       return rotateArray[begin];
    }
};


/*class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int begin, end, mid;
        if(rotateArray.size() == 0){
            return 0;
        }
        begin = 0, end = rotateArray.size() - 1, mid = begin;
        while(rotateArray[begin] >= rotateArray[end]){
            if(end - begin == 1){
                mid = end;
                break;
            }
            mid = begin + (end - begin) / 2;
            if(rotateArray[mid] == rotateArray[begin]
               && rotateArray[mid] == rotateArray[end]){
                return MinInOrder(rotateArray, begin, end);
               }
            if(rotateArray[mid] >= rotateArray[end]){
                begin = mid;
            }else if(rotateArray[mid] <= rotateArray[begin]){
                end = mid;
            }
        }
        return rotateArray[mid];
    }
    int MinInOrder(vector<int> rotateArray, int begin, int end){
        int minValue = rotateArray[begin];
        for(int i=0; i<rotateArray.size(); i++){
            if(minValue > rotateArray[i]){
                minValue = rotateArray[i];
            }
        }
        return minValue;
    }
};
*/


int main()
{
    Solution s;
    vector<int> arr;
    int a;
    while(cin >> a){
       arr.push_back(a);
       if(cin.get() == '\n')
           break;
    }
    cout << s.minNumberInRotateArray(arr) << endl;
    return 0;
}
