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
˼·һ���ǵݹ飬����һ���µ���������Ҫ�ϲ���������������С�Ľ������µ�����
���һ�����������β�ڵ㣬�ͽ���һ������Ľ��ֱ�Ӽ����µ�����
*/

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode *pMergeHead = NULL, *pNode = NULL;
        if(pHead1 == NULL)   //����Ϊ�յ����
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
�ݹ鷨�����αȽ�����������ֵ��С��ͷ��㣬���������ӵ��Ѿ��ϲ�������֮��
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
