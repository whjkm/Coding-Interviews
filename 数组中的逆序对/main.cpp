#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/***
˼·�����ù鲢�����˼�룬�Ȱ�����ָ��������飬��ͳ�Ƴ��������ڲ�������Ե���Ŀ��
Ȼ����ͳ�Ƴ���������������֮�������Ե���Ŀ��
***/
class Solution {
public:
    int InversePairs(vector<int> data) {
        int length = data.size();
        if(length == 0) return 0;
        vector<int> res(data);
        long long count = InversePairsCore(data, res, 0, length-1);
        return count;
    }
    int InversePairsCore(vector<int> &data, vector<int> &res, int begin, int end){
        if(begin == end){
            return 0;
        }
        int mid = begin + (end - begin) / 2;
        int left = InversePairsCore(res, data, begin, mid);
        int right = InversePairsCore(res, data, mid + 1, end);

        int i = mid;
        int j = end;
        int indexCopy = end;
        long long count = 0;
        while(i >= begin && j >= mid + 1){
            if(data[i] > data[j]){
                res[indexCopy--] = data[i--];
                count += j - mid;
            }else{
                res[indexCopy--] = data[j--];
            }
        }
        while(i >= begin){
            res[indexCopy--] = data[i--];
        }
        while(j >= mid + 1){
            res[indexCopy--] = data[j--];
        }
        return (left + right + count) % 1000000007;
    }
};

int main()
{
    vector<int> data = {7, 5, 6, 4};
    Solution s;
    cout << s.InversePairs(data) << endl;
    return 0;
}

