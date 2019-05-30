#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

/*
*˼·����һ��ջģ���������̣�����ջ�����е�Ԫ��������ջ��
*Ȼ�������ж�ջ��Ԫ�غͳ�ջ������Ԫ�صĹ�ϵ������ͳ�ջ���еĵ�ǰԪ����ȣ�
*�ͽ�ջ��Ԫ�س�ջ��������ջΪ�գ�˵����������ȷ�ģ�������˵�������Ǵ���ġ�
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
