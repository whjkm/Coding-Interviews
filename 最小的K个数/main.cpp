#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <functional>
#include <queue>
using namespace std;

/***
*˼·��ά��һ������Ϊk�����ѣ���ʣ�µ�Ԫ�ؽ��бȽϣ����жѵ�����
***/
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(input.empty() || input.size() < k || k <= 0) return res;
        for(int i = 0; i < k; ++i){
            res.push_back(input[i]);
        }
        for(int i = k/2-1; i >= 0; i--){ // ��ʼ����
            adjustHeap(res, i, k);
        }
        for(int i = k; i < input.size(); i++){
            if(input[i] < res[0]){   // ���ڸ�С������ʱ
                res[0] = input[i];
                adjustHeap(res, 0, k);   // ���µ�����
            }
        }
        return res;
    }
    void adjustHeap(vector<int> &input, int i, int length){//������
        int temp = input[i], j;
        for(j = 2*i + 1; j <=length; j = j*2 + 1){
            // �عؼ��ֽϴ�ĺ��ӽ������ɸѡ
            if(j <= length && input[j] < input[j+1]){
                ++j;   // �ϴ�ؼ��ֵ��±�
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
            adjustHeap(input, i, length);    //��ʼ����
        }
        for(int i = length-1; i >= 0; i--){
            swap(input[i], input[0]);
            adjustHeap(input, 0, i);    // ���µ�����
        }
    }
};


/***
˼·��ʹ��STL������O(nlogk)
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
        // ����
        make_heap(res.begin(), res.end());
        for(int i = k; i < input.size(); ++i){
            if(input[i] < res[0]){
                // ���ѣ�Ȼ����ɾ��
                pop_heap(res.begin(), res.end());
                res.pop_back();
                res.push_back(input[i]);
                push_heap(res.begin(), res.end());
            }
        }
        // ������
        sort_heap(res.begin(), res.end());

        return res;
    }
};
*/

/***
˼·��ʹ�����ȶ��У����ȶ��еײ��Ƕ�ʵ�ֵġ�O(nlogk)
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
*˼·��ʹ��STL��set����ʵ�֣�set��multiset�ǻ��ں����ʵ�ֵġ�
*ά��һ����СΪk�������������洢��С��k������; ʱ�临�Ӷ�O(nlogk)��
***/
/*
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        int length = input.size();
        if(input.empty() || k > length || k <=0) return res;

        multiset<int, greater<int>> leastNumbers;   // �Ӵ�С����
        multiset<int, greater<int>>::iterator setInterator;  // ������

        vector<int>::iterator iter = input.begin();
        leastNumbers.clear();
        for(; iter != input.end(); ++iter){
            // ǰk����ֱ�Ӳ���
            if(leastNumbers.size() < k){
                leastNumbers.insert(*iter);
            }else{
                setInterator = leastNumbers.begin();
                // �Ƚ϶Ѷ�Ԫ�غ�Ҫ�����Ԫ��֮��Ĺ�ϵ
                if((*leastNumbers.begin()) > (*iter)){
                    leastNumbers.erase(setInterator); // ɾ���Ѷ�Ԫ��
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
˼·�����ڿ��ŵ�˼·��ʹ��partition��������л��֣�����Ϊ�����֡�
****/
/*
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        int length = input.size();
        // ��������жϣ�������ʱ��ԭ������
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

    // ��Ҫ�޸Ĵ��ݵ����飬ʹ��������ʽ(��ʱ)
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
