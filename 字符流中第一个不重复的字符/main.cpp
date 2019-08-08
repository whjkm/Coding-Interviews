#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <unordered_map>
using namespace std;

// ʹ��hash map�洢��
class Solution
{
public:
    void Insert(char ch)
    {
        data.push_back(ch);
        unmap[ch]++;
    }
    char FirstAppearingOnce()
    {
        for(int i = 0; i < data.size(); ++i)
        {
            if(unmap[data[i]] == 1)
                return data[i];
        }
        return '#';
    }
    vector<char> data;
    unordered_map<char,int> unmap;
};


/***
˼·��ʹ������ͳ���ַ����ֵĴ�����
��һ�ζ��б����һ�γ��ֵ��ַ���
Ȼ���ж϶���Ԫ���Ƿ�ֻ����һ�Σ�����Ǿ�ֱ�ӷ��ء�
***/
/*
class Solution
{
public:
    void Insert(char ch)
    {
        ++hash[ch];
        if(hash[ch] == 1)
            data.push(ch);
    }

    char FirstAppearingOnce()
    {
        while(!data.empty() && hash[data.front()] >=2 ) data.pop();
        if(data.empty()) return '#';
        return data.front();
    }
private:
    queue<char> data;
    unsigned int hash[256] = {0};
};
*/


int main()
{
    Solution s;
    string str = "googale";
    for(int i = 0; i < str.size(); ++i)
    {
        s.Insert(str[i]);
    }
    cout << s.FirstAppearingOnce() << endl;
    return 0;
}
