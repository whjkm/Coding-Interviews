#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <stack>
#include <cstring>
using namespace std;
/***
˼·��������ջģ����У�
ջa�����������Ԫ����ӣ��Ͱ�Ԫ�ؽ�ջ��
ջb������������ж�ջbΪ��Ϊ�գ�Ϊ�վͰ�ջa�е�Ԫ����ջ������ͽ�Ԫ�س�ջ��
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
