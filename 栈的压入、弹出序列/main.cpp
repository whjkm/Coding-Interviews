#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

/*
*思路：用一个栈模拟整个过程，将入栈序列中的元素依次入栈；
*然后依次判断栈顶元素和出栈序列中元素的关系，如果和出栈序列的当前元素相等，
*就将栈顶元素出栈；最后如果栈为空，说明序列是正确的，否则则说明序列是错误的。
*/
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> m_data;
        if(pushV.size() == 0 || popV.size() == 0) return 0;
        for(auto i = 0, j = 0; i != pushV.size();){
            m_data.push(pushV[i++]);
            while(j < popV.size() && m_data.top() == popV[j]){
                m_data.pop();
                j++;
            }
        }
        return m_data.empty();
    }
};

int main()
{
    Solution s;
    vector<int> pushV = {1,2,3,4,5};
    vector<int> popV = {4,3,5,1,2};
    cout << s.IsPopOrder(pushV,popV) << endl;
    return 0;
}
