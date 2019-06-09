#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <functional>
#include <queue>
using namespace std;

/***
*思路：维护一个容量为k的最大堆，与剩下的元素进行比较，进行堆调整。
***/
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(input.empty() || input.size() < k || k <= 0) return res;
        for(int i = 0; i < k; ++i){
            res.push_back(input[i]);
        }
        for(int i = k/2-1; i >= 0; i--){ // 初始化堆
            adjustHeap(res, i, k);
        }
        for(int i = k; i < input.size(); i++){
            if(input[i] < res[0]){   // 存在更小的数字时
                res[0] = input[i];
                adjustHeap(res, 0, k);   // 重新调整堆
            }
        }
        return res;
    }
    void adjustHeap(vector<int> &input, int i, int length){//调整堆
        int temp = input[i], j;
        for(j = 2*i + 1; j <=length; j = j*2 + 1){
            // 沿关键字较大的孩子结点向下筛选
            if(j <= length && input[j] < input[j+1]){
                ++j;   // 较大关键字的下标
            }
            if(temp >= input[j])
                break;
            input[i] = input[j];
            i = j;
        }
        input[i] = temp;
    }

    void Heapsort(vector<int> &input, int length){
        for(int i = length/2 - 1; i >= 0; i--){
            adjustHeap(input, i, length);    //初始化堆
        }
        for(int i = length-1; i >= 0; i--){
            swap(input[i], input[0]);
            adjustHeap(input, 0, i);    // 重新调整堆
        }
    }
};


/***
思路：使用STL堆排序，O(nlogk)
***/

/*
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(input.empty() || input.size() < k || k <= 0) return res;

        for(int i = 0; i < k; ++i){
            res.push_back(input[i]);
        }
        // 建堆
        make_heap(res.begin(), res.end());
        for(int i = k; i < input.size(); ++i){
            if(input[i] < res[0]){
                // 出堆，然后再删除
                pop_heap(res.begin(), res.end());
                res.pop_back();
                res.push_back(input[i]);
                push_heap(res.begin(), res.end());
            }
        }
        // 堆排序
        sort_heap(res.begin(), res.end());

        return res;
    }
};
*/

/***
思路：使用优先队列，优先队列底层是堆实现的。O(nlogk)
***/
/*
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        priority_queue<int> pq;
        vector<int> res;
        if(input.empty() || input.size() < k || k <= 0) return res;
        for(int i = 0; i < input.size(); ++i){
            if(pq.size() < k){
                pq.push(input[i]);
            }else if(input[i] < pq.top()){
                pq.pop();
                pq.push(input[i]);
            }
        }
        while(!pq.empty()){
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};
*/

/***
*思路：使用STL的set容器实现，set和multiset是基于红黑树实现的。
*维护一个大小为k的数据容器来存储最小的k个数字; 时间复杂度O(nlogk)。
***/
/*
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        int length = input.size();
        if(input.empty() || k > length || k <=0) return res;

        multiset<int, greater<int>> leastNumbers;   // 从大到小排序
        multiset<int, greater<int>>::iterator setInterator;  // 迭代器

        vector<int>::iterator iter = input.begin();
        leastNumbers.clear();
        for(; iter != input.end(); ++iter){
            // 前k个数直接插入
            if(leastNumbers.size() < k){
                leastNumbers.insert(*iter);
            }else{
                setInterator = leastNumbers.begin();
                // 比较堆顶元素和要插入的元素之间的关系
                if((*leastNumbers.begin()) > (*iter)){
                    leastNumbers.erase(setInterator); // 删除堆顶元素
                    leastNumbers.insert(*iter);
                }
            }
        }
        for(setInterator = leastNumbers.begin(); setInterator != leastNumbers.end(); ++setInterator){
            res.push_back(*setInterator);
        }
        return res;
    }
};
*/


/****
思路：基于快排的思路，使用partition对数组进行划分，划分为两部分。
****/
/*
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        int length = input.size();
        // 特殊情况判断！！！超时的原因在这
        if(input.empty() || k > length || k<=0) return res;
        int start = 0, end = length - 1;
        int index = Partition(input, start, end);
        while(index != k - 1){
            if(index > k - 1){
                end = index - 1;
                index = Partition(input, start, end);
            }else{
                start = index + 1;
                index = Partition(input, start, end);
            }
        }
        for(int i=0; i < k; i++){
            res.push_back(input[i]);
        }
        return res;
    }

    // 需要修改传递的数组，使用引用形式(超时)
    int Partition(vector<int> &input, int start, int end){
        int pivot = input[start];
        while(start < end){
            while(start < end && pivot <= input[end])
                end--;
            input[start] = input[end];
            while(start < end && pivot >= input[start])
                start++;
            input[end] = input[start];
        }
        input[start] = pivot;
        return start;
    }

    int Partition(vector<int> &input, int start, int end){
        int index = start;
        swap(input[index], input[end]);
        int small = start - 1;
        for(index = start; index < end; ++index){
            if(input[index] <= input[end]){
                ++small;
                if(small != index)
                    swap(input[small], input[index]);
            }
        }
        ++small;
        swap(input[small], input[end]);
        return small;
    }
    void swap(int &fir, int &sec){
        int temp;
        temp = fir;
        fir = sec;
        sec = temp;
    }
};
*/

int main()
{
    Solution s;
    vector<int> input = {4,5,1,6,2,7,3,8};
    int k = 4;
    vector<int> res = s.GetLeastNumbers_Solution(input, k);
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << endl;
    return 0;
}
