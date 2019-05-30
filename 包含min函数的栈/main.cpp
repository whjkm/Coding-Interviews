#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

/*
*˼·��Ϊ�˱��⸨��ջ�д洢̫�������Ԫ�أ�ʹ��vectorģ��ջ��
*��һ������ջ�洢��СԪ����vector�е�������ÿ�θ����������С�
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
*˼·:ʹ��һ������ջ���洢��ǰ����Сֵ��ÿ��������ջ������ǰ����Сֵ���븨��ջ��
*��ջʱ����ջԪ�ض�Ҫ��ջ�����ָ���ջ�е�Ԫ���ǵ�ǰջ�е���Сֵ��
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
    stack<int> m_data, m_min;  //m_data�洢���ݣ�m_min�洢��ǰ����Сֵ
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
