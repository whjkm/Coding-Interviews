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

/***
两个链表的第一个公共节点：
先求出两个链表的长度，求出两个链表的长度差dist，让较长链表先走dist长度；
然后两个链表同时遍历，得到第一个公共节点就是所求。
***/
class Solution {
public:
    unsigned int getListLength(ListNode* pHead){
        unsigned int nlength = 0;
        ListNode* pNode = pHead;
        while(pNode != NULL)
        {
            pNode = pNode -> next;
            nlength++;
        }
        return nlength;
    }
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        unsigned int len1 = getListLength(pHead1);
        unsigned int len2 = getListLength(pHead2);
        unsigned int dist = len1 - len2;
        ListNode* pListLong = pHead1;
        ListNode* pListShort = pHead2;
        if(dist < 0)
        {
            ListNode* pListLong = pHead2;
            ListNode* pListShort = pHead1;
            dist = len2 - len1;
        }
        for(int i=0; i < dist; ++i)
        {
            pListLong = pListLong -> next;
        }
        while(pListLong != NULL && pListShort != NULL && pListLong != pListShort)
        {
            pListLong = pListLong -> next;
            pListShort = pListShort -> next;
        }
        return pListLong;
    }
};

// 用两个指针扫描"两个链表"，最终两个指针到达 null 或者到达公共结点。
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode* pNode1 = pHead1;
        ListNode* pNode2 = pHead2;
        while(pNode1 != pNode2)
        {
            pNode1 = ((pNode1 == NULL) ? pHead2 : pNode1->next);
            pNode2 = ((pNode2 == NULL) ? pHead1 : pNode2->next);
        }
        return pNode1;
    }
};


int main()
{
    return 0;
}
