#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

/***
思路2：利用数学归纳法推导；
假设f(n)为n级台阶的跳法数，f(1) = 1, f(2) = f(2-1) + f(2-2)；
f(3) = f(3-1) + f(3-2) + f(3-3) 可以选择跳1阶，2阶，3阶；
那么f(n) = f(n-1) + f(n-2) + f(n-3) +...+ f(n-n)
         = f(0) + f(1) + f(2) + ... + f(n-1)
依次类推：f(n-1) = f(0) + f(1) + .... + f(n-2)
可以得到：f(n) - f(n-1) = f(n-1) ->  f(n) = 2*f(n-1)
f(0) = 1, f(1) = 1;
***/

class Solution {
public:
    int jumpFloorII(int number) {
        if(number <= 0){
            return 0;
        }else if(number == 1){
            return 1;
        }else{
            return 2 * jumpFloorII(number - 1);
        }
    }
};

/***
*思路1:总共有n级台阶，除了最后一阶台阶外（最后一阶必须跳），
*其他n-1阶都有两种可能，可以选择跳或不跳；
*所以总的跳法为：2^(n-1)种。
***/
/*
class Solution {
public:
    int jumpFloorII(int number) {
        if(number <=0){
            return 0;
        }else{
            return 1<<(number - 1);  //利用左移乘2
        }
    }
};
*/

int main()
{
    Solution s;
    cout << s.jumpFloorII(3) << endl;
    return 0;
}
