#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

/***
思路：利用二分查找的思想。
因为给的是一个排好序的数组，旋转之后可以分为两部分，前后两部分还是有序的；
可以利用二分查找的思路，缩小查找的范围；
如果array[mid] > array[end], 说明最小元素的范围在mid+1到end之间，mid在前半部分的上升序列中。
如果array[start] > array[mid],说明最小元素的范围在start到mid之间，说明后半部分是有序的。
如果存在array[start]==array[mid],存在元素相等的情况，不好判断，只能顺序查找了。
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
