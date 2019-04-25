#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <stack>
#include <cstring>
using namespace std;
/***
思路：用两个栈模拟队列；
栈a负责存数，当元素入队，就把元素进栈；
栈b负责输出，先判断栈b为不为空，为空就把栈a中的元素入栈；否则就将元素出栈。
***/
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.size()<=0){
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int result = 0;
        if(!stack2.empty()){
            result = stack2.top();
            stack2.pop();
        }
        return result;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main()
{
    Solution s;
    for(int i=0; i<3; i++){
        s.push(i);
    }
    for(int i=0; i<3; i++){
        cout << s.pop() << endl;
    }
    return 0;
}
