#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

// 用数组来模拟
class Solution {
public:
    int LastRemaining_Solution(int n, int m){
        if(n < 1 || m < 1)
            return -1;
        vector<int> numbers(n, 0);
        // i为每次删除的数字，count 模拟圆环，step记录每轮的步数。
        int i = -1, count = n, step = 0;
        while(count > 0)
        {
            i++;
            if(i >= n) i = 0;  // 循环
            if(numbers[i] == -1) continue;  // 删除的元素标记为-1;
            step ++;
            if(step == m)    // 找到要删除的数字
            {
                numbers[i] = -1;
                step = 0;   // 开始新的一轮
                count --;   // 圆环数字减1
            }
        }
        return i;
    }
};

/***
list容器模拟圆圈
***/
/*
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n < 1 || m < 1)
            return -1;
        list<int> numbers;
        for(int i = 0; i < n; ++i)
            numbers.push_back(i);
        list<int>::iterator current = numbers.begin();
        while(numbers.size() > 1)
        {
            for(int i = 0; i < m - 1; ++i)
            {
                current ++;
                if(current == numbers.end())   // 扫描到链表尾部
                    current = numbers.begin();
            }
            list<int>::iterator next = ++current;
            if(next == numbers.end())
                next = numbers.begin();
            -- current;
            numbers.erase(current);
            current = next;
        }
        return *(current);
    }
};
*/

/***
约瑟夫环：
令f[i]表示i个人玩游戏报m退出最后胜利者的编号，最后的结果自然是f[n]。
递推公式
f[1]=0;
f[i]=(f[i-1]+m)%i;  (i>1)
***/
/*
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n < 1 || m < 1)
            return -1;
        int last = 0;
        for(int i = 2; i <= n; ++i)
        {
            last = (last + m) % i;
        }
        return last;
    }
};
*/

int main()
{
    Solution s;
    cout << s.LastRemaining_Solution(5, 3) << endl;
    return 0;
}
