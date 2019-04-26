#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

//动态规划，用f(n+1)的状态倒推f(n)的状态。
class Solution{
public:
    int Fibonacci(int n) {
        int f = 0, g = 1;
        while(n-- > 0){
            g += f;        //f(n+1)
            f = g - f;     //f(n)
        }
        return f;
    }
};

/*
//动态规划解法，用数组存储结果，避免重复计算。
class Solution {
public:
    int Fibonacci(int n) {
        if(n < 0){
            return 0;
        }
        vector<int> result(n+1,0);
        result[1] = 1;
        for(int i=2; i<=n; i++){
            result[i] = result[i-2] + result[i-1];
        }
        return result[n];
    }
};
*/

/*
//递推,循环
class Solution {
public:
    int Fibonacci(int n) {
        int result = n;   // n为0,1的情况
        if(n < 0){
            result = 0;
        }
        int f0 = 0, f1 = 1;
        for(int i=2; i<=n; i++){
            result = f0 + f1;
            f0 = f1;
            f1 = result;
        }
        return result;
    }
};
*/


/*
// 递归
class Solution {
public:
    int Fibonacci(int n) {
        if(n <= 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        return Fibonacci(n-1) + Fibonacci(n-2);
    }
};
*/
int main()
{
    Solution s;
    cout << s.Fibonacci(39) << endl;
    return 0;
}
