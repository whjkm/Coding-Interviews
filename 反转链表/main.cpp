#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

/*LeetCode 206
思路1：使用3个指针保存当前位置，前一个位置，直接将指针逆置。
思路2：递归，每次改变当前指针的位置。
思路3：利用一个栈保存原始的顺序，然后按照出栈顺序重新构造一个链表。
*/


/*
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
       if(pHead == NULL)
          return NULL;
       ListNode *pNode = pHead;      //保存当前节点
       ListNode *pPrev = NULL;       //前一个节点
       ListNode *pReverseHead = NULL;   //反转后的头节点
       while(pNode != NULL){
          ListNode *pNext = pNode -> next;    //保存当前节点的后一个节点
          if(pNext == NULL){
             pReverseHead = pNode;
          }
          pNode -> next = pPrev;     //指针反转
          pPrev = pNode;
          pNode = pNext;
       }
       return pReverseHead;
    }
};
*/

//递归
/*
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        // 如果链表为空或者链表中只有一个元素
        if(pHead==NULL||pHead->next==NULL) return pHead;

        //递归访问后面的结点
        ListNode *pReverseHead = ReverseList(pHead -> next);

        //将当前结点逆置
        pHead -> next -> next = pHead;
        pHead -> next = NULL;
        return pReverseHead;
    }
};
*/

//利用栈存储
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == NULL || pHead -> next == NULL) return pHead;
        stack<ListNode*> s;
        ListNode *pNode = pHead;
        while(pNode -> next != NULL){
            s.push(pNode);
            pNode = pNode -> next;   //最后一个结点
        }
        ListNode *pReverseHead = pNode;
        while(!s.empty()){
            pNode -> next = s.top();
            pNode = pNode -> next;
            s.pop();
        }
        pNode -> next = NULL;
        return pReverseHead;
    }
};

void createList(ListNode *pHead){
    ListNode *pNode = pHead;
    for(int i=1; i<10; i++){
        ListNode *pTemp = new ListNode(i);
        pNode -> next = pTemp;
        pNode = pTemp;
    }

}

int main()
{
    Solution s;
    ListNode *pHead = new ListNode(0);
    createList(pHead);
    ListNode *p = s.ReverseList(pHead);
    while(p!=NULL){
        cout << p->val << endl;
        p = p->next;
    }
    return 0;
}
