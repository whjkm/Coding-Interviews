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
思路：从尾到头打印链表
借助一个栈存储链表中的元素值，然后用一个数组存储出栈的顺序。
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
