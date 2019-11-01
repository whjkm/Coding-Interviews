#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int cutRope(int number) {
        vector<int> dp(number + 1, 0);
        if(number < 2) return 0;
        if(number == 2) return 1;
        if(number == 3) return 2;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for(int i = 4; i <= number; ++i)
        {
            for(int j = 1; j <= i/2; ++j)
            {
                dp[i] = max(dp[i], dp[j]*dp[i-j]);
            }
        }
        return dp[number];
    }
};

int main()
{
    Solution s;
    cout << s.cutRope(8) << endl;
    return 0;
}
