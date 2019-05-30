#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

/*
*思路：为了避免辅助栈中存储太多冗余的元素，使用vector模拟栈，
*用一个辅助栈存储最小元素在vector中的索引，每次更新索引就行。
*/
class Solution {
public:
    void push(int value) {
        m_data.push_back(value);
        if(m_min.empty()){
            m_min.push(0);
        }else {
           if(value < min()){
             m_min.push(m_data.size() - 1);
           }
        }
    }
    void pop() {
        if(!m_data.empty()){
            if((m_data.size() - 1) == m_min.top())
                m_min.pop();
            m_data.pop_back();
        }
    }
    int top() {
        return m_data[m_data.size() - 1];
    }
    int min() {
        return m_data[m_min.top()];
    }
private:
    vector<int> m_data;
    stack<int> m_min;
};

/*
*思路:使用一个辅助栈来存储当前的最小值，每次数据入栈，将当前的最小值存入辅助栈，
*出栈时两个栈元素都要出栈，保持辅助栈中的元素是当前栈中的最小值。
*/
/*
class Solution {
public:
    void push(int value) {
        m_data.push(value);
        if(m_min.empty()){
            m_min.push(value);
        }else if(m_min.top() < value){
            m_min.push(m_min.top());
        }else{
            m_min.push(value);
        }
    }
    void pop() {
        if(!m_data.empty()){
            m_data.pop();
            m_min.pop();
        }
    }
    int top() {
        return m_data.top();
    }
    int min() {
        return m_min.top();
    }
private:
    stack<int> m_data, m_min;  //m_data存储数据，m_min存储当前的最小值
};
*/

int main()
{
    Solution s;
    for(int i=0; i<5; ++i){
        s.push(i);
    }
    cout << s.min() << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.min() << endl;
    cout << s.top() << endl;
    return 0;
}
