#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/****
思路：类似于筛选法的思想，每个丑数都是由前面的丑数乘以（2,3,5）中任意一个得到的，
所以我们就维护一个排好序的丑数序列，每次将当前最小的丑数插入数组，用3个指针记录当前丑数是由哪个得到的。
****/

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
       if(index < 7) return index;
       vector<int> res(index);
       res[0] = 1;
       int p2 = 0, p3 = 0, p5 = 0;
       for(int i = 1; i < index; ++i){
          res[i] = min(min(res[p2]*2, res[p3]*3),res[p5]*5);
          if(res[i] == res[p2]*2) p2++;
          if(res[i] == res[p3]*3) p3++;
          if(res[i] == res[p5]*5) p5++;
       }
       return res[index - 1];
    }
};

int main()
{
    Solution s;
    cout << s.GetUglyNumber_Solution(1500) << endl;
    return 0;
}
