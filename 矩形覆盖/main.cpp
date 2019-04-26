#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
/***
*思路：还是斐波拉契的变种；
*假设f(n)代表2*n的矩阵有多少中覆盖方法。
*假设从最左边开始覆盖，最左边如果把2*1的矩阵竖着放,那就还有f(n-1)种；
*如果2*1的矩阵横着放，那么最左边的2*2的矩阵就确定了，只能由两个2*1的矩阵横着放，
*那就还有f(n-2)种；所以f(n) = f(n-1) + f(n-2), f(1) = 1, f(2) = 2;
***/

class Solution {
public:
    int rectCover(int number) {
        if(number <= 0){
            return 0;
        }
        vector<int> result(number+1, 1);
        for(int i=2; i<=number; i++){
            result[i] = result[i-1] + result[i-2];
        }
        return result[number];
    }
};

int main()
{
    Solution s;
    cout << s.rectCover(2) << endl;
    return 0;
}
