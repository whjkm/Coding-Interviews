#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <stack>
#include <cstring>
using namespace std;

struct ListNode {
       int val;
       struct ListNode *next;
       ListNode(int x) :
            val(x), next(NULL) {
    }
};
/***
˼·����β��ͷ��ӡ����
����һ��ջ�洢�����е�Ԫ��ֵ��Ȼ����һ������洢��ջ��˳��
***/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        ListNode *p = head;
        stack<int> s;
        vector<int> v;
        while(p != NULL){
            s.push(p->val);
            p = p->next;
        }
        while(!s.empty()){
            v.push_back(s.top());
            s.pop();
        }
        return v;
    }
};

int main()
{

    return 0;
}
