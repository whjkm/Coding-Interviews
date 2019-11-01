#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

// 使用双端队列维护滑动窗口, 队列头即为滑动窗口的最大值
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        deque<int> qu;
        for(int i = 0; i < num.size(); ++i)
        {
            while(qu.size() && num[qu.back()] <= num[i])
                qu.pop_back();
            while(qu.size() && i - qu.front() + 1 > size)
                qu.pop_front();
            qu.push_back(i);
            if(size && i + 1 >= size)
                res.push_back(num[qu.front()]);
        }
        return res;
    }
};

int main()
{

    return 0;
}
