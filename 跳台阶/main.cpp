#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

/***
*思路：斐波拉契变种，斐波拉契解法可以参看第7题;
*这里直接用F(n)保存第n级有多少种跳法；而每次可以跳1级楼梯或2级楼梯；
*所以F(n)可以是由跳一级楼梯或2级楼梯得到的；
*可以得到F(n)=F(n-1)+F(n-2)；问题就转化为F(n-1)和F(n-2)的跳法了。
***/

class Solution {
public:
    int jumpFloor(int number) {
        vector<int> result(number+1, 1);
        result[1] = 1;
        for(int i=2; i<=number; i++){
            result[i] = result[i-1] + result[i-2];
        }
        return result[number];
    }
};

int main()
{
    Solution s;
    cout << s.jumpFloor(5) << endl;
    return 0;
}
