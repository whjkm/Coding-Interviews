#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

//递归

class Solution
{
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead==NULL || pHead->next==NULL)
            return pHead;

        ListNode* current;

        if (pHead->next->val==pHead->val)  // 当前结点是重复结点
        {
            int tmp=pHead->val;
            current=pHead->next->next;
            delete pHead->next;   // 删除重复结点
            delete pHead;

            while (current != NULL && current->val==tmp)
            {
                ListNode* node=current;
                current=current->next;
                delete node;     // 删除重复结点
            }
            return deleteDuplication(current);   // 递归遍历重复元素后的结点
        }
        else
        {
            current=pHead->next;
            pHead->next=deleteDuplication(current);
            return pHead;
        }
    }
};


/*
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == NULL || pHead->next == NULL)
            return pHead;
        ListNode* pPreNode = NULL;     // 当前结点的前一个结点，防止断链
        ListNode* pNode = pHead;       // 当前结点
        while(pNode != NULL)
        {
            ListNode* pNext = pNode->next;    // 下一个结点
            bool needDel = false;
            if(pNext != NULL && pNode->val == pNext->val)
                needDel = true;

            // 没有重复结点，往下遍历
            if(!needDel)
            {
                pPreNode = pNode;
                pNode = pNode->next;
            }
            else
            {
                ListNode* ToBeDel = pNode;    // 需要删除的结点
                int value = pNode ->val;
                // 删除重复的元素
                while(ToBeDel != NULL && ToBeDel->val == value)
                {
                    pNext = ToBeDel->next;
                    delete ToBeDel;
                    ToBeDel = NULL;
                    ToBeDel = pNext;
                }
                // 前一个结点为空，删除的是头结点
                if(pPreNode == NULL)
                   pHead = pNext;
                else
                   pPreNode ->next = pNext;
                pNode = pNext;
            }
        }
        return pHead;
    }
};
*/



int main()
{

    return 0;
}
