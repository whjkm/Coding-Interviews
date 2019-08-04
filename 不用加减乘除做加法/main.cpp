#include <iostream>
using namespace std;

/***
不用四则运算进行两数的加法，使用位运算。
正常加法分为三步：1.不进位加法：例如 5 + 17, 先 5 + 7 = 2 (不加进位), 十位：1 + 0 = 0；
2.做进位，5 + 7 有进位，进位值为10；
3.把前两步得到的值相加。
***/
class Solution
{
public:
    int Add(int num1, int num2)
    {
        int sum = 0, carry = 0;
        do
        {
            sum = num1 ^ num2;              // 不进位加法（异或）
            carry = (num1 & num2) << 1;     // 处理进位，二进制中只有全为1才会产生进位，进位之后左移。

            num1 = sum;
            num2 = carry;
        }
        while(num2 != 0);                  // 直到进位的值为0
        return sum;
    }
};

int main()
{
    Solution s;
    cout << s.Add(5, 17) << endl;
    return 0;
}
