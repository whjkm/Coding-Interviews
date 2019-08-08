#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

/***
����ͷ������ڵľ���=�����㵽����ڵľ���+��k-1��Ȧ�����ȡ�
����k>=1,����k-1>=0Ȧ����������ָ��ֱ������ͷ����������������һ�������ڻ���ڡ�
***/

class Solution {
public:
    // �ҵ�һ��һ������������㣬�������һ���ڻ���
    ListNode* MeetingNode(ListNode* pHead)
    {
        if(pHead == NULL)
            return NULL;
        ListNode* pSlow = pHead->next;
        if(pSlow == NULL)
            return NULL;
        ListNode* pFast = pSlow->next;
        while(pFast != NULL && pSlow != NULL)
        {
            if(pSlow == pFast)   // ����
                return pFast;
            pSlow = pSlow -> next;

            pFast = pFast -> next;
            if(pFast != NULL)
                pFast = pFast -> next;
        }
        return NULL;
    }

    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode* meetNode = MeetingNode(pHead);
        if(meetNode == NULL)
            return NULL;
        int nodeInLoop = 1;
        ListNode* pNode1 = meetNode;
        while(pNode1 ->next != meetNode)
        {
            pNode1 = pNode1 ->next;
            ++nodeInLoop;
        }
        // �ƶ���ͷ��㴦
        pNode1 = pHead;
        for(int i = 0; i < nodeInLoop; ++i)  // ������еĽ����
        {
            pNode1 = pNode1 ->next;
        }
        ListNode* pNode2 = pHead;
        while(pNode1 != pNode2)
        {
            pNode1 = pNode1 ->next;
            pNode2 = pNode2 ->next;
        }
        return pNode1;
    }
};

int main()
{

    return 0;
}
