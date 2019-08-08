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
链表头到环入口的距离=相遇点到环入口的距离+（k-1）圈环长度。
其中k>=1,所以k-1>=0圈。所以两个指针分别从链表头和相遇点出发，最后一定相遇于环入口。
***/

class Solution {
public:
    // 找到一块一慢结点的相遇结点，相遇结点一定在环中
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
            if(pSlow == pFast)   // 相遇
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
        // 移动到头结点处
        pNode1 = pHead;
        for(int i = 0; i < nodeInLoop; ++i)  // 求出环中的结点数
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
