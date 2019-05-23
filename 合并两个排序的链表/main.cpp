#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

/*
思路一：非递归，创建一个新的链表，遍历要合并的两个链表，将较小的结点加入新的链表，
如果一个链表遍历到尾节点，就将另一个链表的结点直接加入新的链表。
*/

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode *pMergeHead = NULL, *pNode = NULL;
        if(pHead1 == NULL)   //链表为空的情况
            return pHead2;
        else if(pHead2 == NULL)
            return pHead1;
        while(pHead1 != NULL && pHead2 != NULL){
            if(pHead1 -> val <= pHead2 -> val){
                if(pMergeHead == NULL){
                    pMergeHead = pNode = pHead1;
                }else{
                    pNode -> next = pHead1;
                    pNode = pNode -> next;
                }
                pHead1 = pHead1 -> next;
            }else{
                if(pMergeHead == NULL){
                    pMergeHead = pNode = pHead2;
                }else{
                    pNode -> next = pHead2;
                    pNode = pNode -> next;
                }
                pHead2 = pHead2 -> next;
            }
        }
        if(pHead1 != NULL){
            pNode -> next = pHead1;
        }
        if(pHead2 != NULL){
            pNode -> next = pHead2;
        }
        return pMergeHead;
    }
};


/*
递归法：依次比较两个链表中值较小的头结点，并把它链接到已经合并的链表之后。
*/
/*
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == NULL)
            return pHead2;
        else if(pHead2 == NULL)
            return pHead1;
        ListNode *pMergeHead = NULL;
        if(pHead1 -> val < pHead2 -> val){
            pMergeHead = pHead1;
            pMergeHead -> next = Merge(pHead1->next, pHead2);
        }else{
            pMergeHead = pHead2;
            pMergeHead -> next = Merge(pHead1, pHead2 -> next);
        }
        return pMergeHead;
    }
};
*/
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
    ListNode *pHead1 = new ListNode(0);
    createList(pHead1);
    ListNode *pHead2 = new ListNode(0);
    createList(pHead2);
    ListNode *pHead3 = s.Merge(pHead1, pHead2);
    while(pHead3 != NULL){
        cout << pHead3 -> val << endl;
        pHead3 = pHead3 -> next;
    }
    return 0;
}
