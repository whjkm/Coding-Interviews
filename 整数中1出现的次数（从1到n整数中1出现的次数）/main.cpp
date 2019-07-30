#include <iostream>
#include <vector>
using namespace std;

/***
*参考：https://www.cnblogs.com/nailperry/p/4752987.html
*思路：首先要明白一点：
*1~10: 在它们的个位中，x出现1次(x可取1~9)；
*1~100: 在它们的十位中，x出现10次；
*1~1000: 在它们的百位中，x出现100次；
*依此类推：1~10^i: 在它们的左数第二位（右数第i位），x出现了10^i-2次。
*得到规律如下：
*1.如果第i位（个位开始）为0，则第i位可能出现1的次数由更高位决定，等于高位数字x当前位数的权重10^i-1；
*2.如果第i位等于1，则第i位可能出现1的次数不仅受更高位影响，还受到低位影响，等于高位数字x当前位数的权重10^i-1 + 低位数字x+1；
*3.如果第i位大于1，则第i位可能出现1的次数仅由更高位决定，等于高位数字x+1当前位数的权重10^i-1。
***/

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int count = 0;
        int i = 1;     // 当前位数，从个位开始
        int current = 0, high = 0, low = 0;
        while((n/i) != 0){
            current = (n/i) % 10;      // 当前位数的数字
            high = n / (i*10);         // 高位的数字
            low = n - (n/i)*i;         // 低位的数字
            if(current == 1){
                count += high * i + low + 1;
            }else if(current == 0){   // 小于1
                count += high * i;
            }else{
                count += (high + 1) * i;
            }
            i *= 10;
        }
        return count;
    }
};

int main()
{
    Solution s;
    cout << s.NumberOf1Between1AndN_Solution(12013) << endl;
    return 0;
}
