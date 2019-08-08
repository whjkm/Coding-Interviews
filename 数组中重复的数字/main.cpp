#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

// ʹ��Hash
class Solution {
public:
    bool duplicate(int numbers[], int length, int* duplication) {
        unordered_map<int, int> mp;
        if(numbers == NULL || length <= 0)
        {
            return false;
        }
        for(int i = 0; i < length; ++i)
        {
            if(numbers[i] < 0 || numbers[i] > length-1)
                return false;
        }
        for(int i = 0; i < length; ++i)
        {
            mp[numbers[i]]++;
            if(mp[numbers[i]] > 1)
            {
                *duplication = numbers[i];
                return true;
            }
        }
        return false;
    }
};


/***
˼·����Ϊ�����е����ֶ���0~n-1�ķ�Χ�ڡ�������������û���ظ������֣���ô�����������
��ô����i���������±�Ϊi��λ�á�
����������飬��ͷ��β����ɨ�����������е�ÿ�����顣��ɨ�赽�±�Ϊi������ʱ��
���ȱȽ�������֣�m���ǲ��ǵ���i������ǣ��Ƚ���һ��;������ǣ��Ƚ����͵�m�����֣�
������͵�m��������ȣ����ҵ��˵�һ���ظ������֡��������ȣ��ͽ�����������Ȼ�����ظ�������̡�
***/
/*
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if(numbers == NULL || length <= 0)
        {
            return false;
        }
        for(int i = 0; i < length; ++i)
        {
            if(numbers[i] < 0 || numbers[i] > length-1)
                return false;
        }
        for(int i = 0; i < length; ++i)
        {
            while(numbers[i] != i)
            {
                if(numbers[i] == numbers[numbers[i]])
                {
                    *duplication = numbers[i];
                    return true;
                }
                swap(numbers[i], numbers[numbers[i]]);
            }
        }
        return false;
    }
};
*/

int main()
{
    Solution s;
    int numbers[7] = {2,3,1,0,4,5,3};
    int duplication = 0;
    cout << s.duplicate(numbers, 7, &duplication) << endl;
    cout << duplication << endl;
    return 0;
}
