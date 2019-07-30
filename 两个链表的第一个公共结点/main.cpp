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
��������ĵ�һ�������ڵ㣺
�������������ĳ��ȣ������������ĳ��Ȳ�dist���ýϳ���������dist���ȣ�
Ȼ����������ͬʱ�������õ���һ�������ڵ��������
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

// ������ָ��ɨ��"��������"����������ָ�뵽�� null ���ߵ��﹫����㡣
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
