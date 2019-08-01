#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
// �ǵݹ��
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k)
    {
        int res = 0;
        if(data.size() != 0)
        {
            int first = FirstOfK(data, k);
            int last = LastOfK(data, k);
            if(first > -1 && last > -1)
            {
                res = last - first + 1;
            }
        }
        return res;
    }
private:
    int FirstOfK(vector<int> data, int k)
    {
        int start = 0, end = data.size() - 1;
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            if(data[mid] == k)
            {
                if((mid != 0 && data[mid - 1] != k) || mid == 0)
                {
                    return mid;
                }
                else
                {
                    end = mid - 1;
                }
            }
            else if(data[mid] > k)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return -1;
    }
    int LastOfK(vector<int> data, int k)
    {
        int start = 0, end = data.size() - 1;
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            if(data[mid] == k)
            {
                if((mid != data.size() - 1 && data[mid + 1] != k) || mid == data.size() - 1)
                {
                    return mid;
                }
                else
                {
                    start = mid + 1;
                }
            }
            else if(data[mid] > k)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return -1;
    }
};

/*
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
      //������������count��������������
        return count(data.begin(),data.end(),k);
    }
};
*/

/***
˼·����
��Ϊdata�ж������������Կ�����΢��һ�£���������k������λ�ã���������k-0.5��k+0.5
��������Ӧ�ò����λ�ã�Ȼ��������ɡ�
***/
/*
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k)
    {
        return bSearch(data, k + 0.5) - bSearch(data, k - 0.5);
    }
private:
    int bSearch(vector<int> data, double k)
    {
        int start = 0, end = data.size() - 1;
        while(start <= end)
        {
           int mid = start + (end - start) / 2;
           if(data[mid] > k)
           {
               end = mid - 1;
           }
           else if(data[mid] < k)
           {
               start = mid + 1;
           }
        }
        return start;
    }
};
*/

/***
˼·һ: ��������飬���ö��ֵ�˼·���ҵ�k���ֵĵ�һ��λ�ã�
Ȼ�����ҵ�k���ֵ����һ��λ�ã����ֲ��ҵ�ʱ�临�Ӷ�ΪO(logn);
***/
/*
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k)
    {
        int res = 0;
        if(data.size() != 0)
        {
            int first = FirstofK(data, 0, data.size()-1, k);
            int last = LastofK(data, 0, data.size()-1, k);
            if(first > -1 && last > -1)
            {
                res = last - first + 1;
            }
        }
        return res;
    }
    int FirstofK(vector<int> data, int left, int right, int k)
    {
        if(left > right)
            return -1;
        int mid = left + (right - left) / 2;
        if(data[mid] == k){
            if((mid > 0 && data[mid - 1] != k) || mid == 0){
                return mid;
            }
            else{
                right = mid - 1;
            }
        }else if(data[mid] > k){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
        return FirstofK(data, left, right, k);
    }
    int LastofK(vector<int> data, int left, int right, int k)
    {
        if(left > right)
            return -1;
        int mid = left + (right - left) / 2;
        if(data[mid] == k){
            if((mid < data.size() - 1 && data[mid + 1] != k) || mid == data.size() - 1)
            {
                return mid;
            }else{
                left = mid + 1;
            }
        }else if(data[mid] < k){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
        return LastofK(data, left, right, k);
    }
};
*/

int main()
{
    Solution s;
    vector<int> data = {1,2,3,3,3,3,3,4,5};
    cout << s.GetNumberOfK(data, 3) << endl;
    return 0;
}
