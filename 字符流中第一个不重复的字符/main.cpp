#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <unordered_map>
using namespace std;

// 使用hash map存储。
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
思路：使用数组统计字符出现的次数；
用一次队列保存第一次出现的字符，
然后判断队首元素是否只出现一次，如果是就直接返回。
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
