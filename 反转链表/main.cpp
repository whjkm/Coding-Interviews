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
˼·1��ʹ��3��ָ�뱣�浱ǰλ�ã�ǰһ��λ�ã�ֱ�ӽ�ָ�����á�
˼·2���ݹ飬ÿ�θı䵱ǰָ���λ�á�
˼·3������һ��ջ����ԭʼ��˳��Ȼ���ճ�ջ˳�����¹���һ������
*/


/*
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
       if(pHead == NULL)
          return NULL;
       ListNode *pNode = pHead;      //���浱ǰ�ڵ�
       ListNode *pPrev = NULL;       //ǰһ���ڵ�
       ListNode *pReverseHead = NULL;   //��ת���ͷ�ڵ�
       while(pNode != NULL){
          ListNode *pNext = pNode -> next;    //���浱ǰ�ڵ�ĺ�һ���ڵ�
          if(pNext == NULL){
             pReverseHead = pNode;
          }
          pNode -> next = pPrev;     //ָ�뷴ת
          pPrev = pNode;
          pNode = pNext;
       }
       return pReverseHead;
    }
};
*/

//�ݹ�
/*
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        // �������Ϊ�ջ���������ֻ��һ��Ԫ��
        if(pHead==NULL||pHead->next==NULL) return pHead;

        //�ݹ���ʺ���Ľ��
        ListNode *pReverseHead = ReverseList(pHead -> next);

        //����ǰ�������
        pHead -> next -> next = pHead;
        pHead -> next = NULL;
        return pReverseHead;
    }
};
*/

//����ջ�洢
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == NULL || pHead -> next == NULL) return pHead;
        stack<ListNode*> s;
        ListNode *pNode = pHead;
        while(pNode -> next != NULL){
            s.push(pNode);
            pNode = pNode -> next;   //���һ�����
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
