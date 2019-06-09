#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
*思路：数组中有一个数字出现的次数超过数组长度的一半；
*我们可以考虑在遍历数组的时候保存两个值，一个是数组中的一个数字，一个是次数；
*当我们遍历到下一个数字的时候，如果下一个数字和我们之前保存的数字相同，则次数加1；
*否则就次数减1。如果次数减为0，我们需要保存下一个数字，并把次数设为1。
*要找的数字就是最后一次把次数设为1时对应的数字。
*/
/*class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int n = numbers.size();
        if(n == 0) return 0;
        int num = numbers[0], count = 1;
        for(int i=1; i < n; i++){
            if(numbers[i] == num)
                count++;
            else count--;
            if(count == 0){
                num = numbers[i];
                count = 1;
            }
        }
        //验证是否超过了原数组的一半
        count = 0;
        for(int i=0; i < n; i++){
            if(numbers[i] == num) count++;
        }
        if(count * 2 > n) return num;
        return 0;
    }
};
*/

/*
*思路：利用快排的思路，超过数组一半的数字排序之后一定位于数组的中间。
*借助快排划分数组的思路，找到数组的中位数，而不用完全排序。
*/
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int length = numbers.size();
        if(numbers.empty() || length <= 0) return 0;
        int middle = length >> 1;
        int start = 0;
        int end = length - 1;
        int index = Partition(numbers, start, end);
        while(index != middle){
            if(index > middle){
                end = index - 1;
                index = Partition(numbers, start, end);
            }
            else{
                start = index + 1;
                index = Partition(numbers, start, end);
            }
        }
        int result = numbers[middle];
        //验证是否超过了原数组的一半
        int count = 0;
        for(int i=0; i < length; i++){
            if(numbers[i] == result) count++;
        }
        if(count * 2 > length) return result;
        return 0;
    }
    // 快排划分数组
    /*
    int Partition(vector<int> numbers, int start, int end){
        int pivot = numbers[start];
        while(start < end){
            while(start < end && pivot < numbers[end])
                end--;
            swap(numbers[start], numbers[end]);
            while(start < end && pivot >= numbers[start])
                start++;
            swap(numbers[start], numbers[end]);
        }
        return start;
    }*/
    // 剑指offer写法
    int Partition(vector<int> numbers, int start, int end){
        int index = RandInRange(start, end); // 枢轴
        swap(numbers[index], numbers[end]);
        int small = start - 1;
        for(index = start; index < end; index++){
            if(numbers[index] < numbers[end]){
                ++small;
                if(small != index){
                    // 将小于枢轴的数交换到前面
                    swap(numbers[small], numbers[index]);
                }
            }
        }
        ++small;
        swap(numbers[small], numbers[end]);
        return small;
    }
    int RandInRange(int a, int b){
        int c;
        c = a + rand()%(b - a + 1);
        return c;
    }

};

int main()
{
    Solution s;
    vector<int> numbers = {1,2,3,2,2,2,5,4,2};
    cout << s.MoreThanHalfNum_Solution(numbers) << endl;
    return 0;
}
