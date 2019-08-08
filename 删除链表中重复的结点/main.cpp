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

//�ݹ�

class Solution
{
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead==NULL || pHead->next==NULL)
            return pHead;

        ListNode* current;

        if (pHead->next->val==pHead->val)  // ��ǰ������ظ����
        {
            int tmp=pHead->val;
            current=pHead->next->next;
            delete pHead->next;   // ɾ���ظ����
            delete pHead;

            while (current != NULL && current->val==tmp)
            {
                ListNode* node=current;
                current=current->next;
                delete node;     // ɾ���ظ����
            }
            return deleteDuplication(current);   // �ݹ�����ظ�Ԫ�غ�Ľ��
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
        ListNode* pPreNode = NULL;     // ��ǰ����ǰһ����㣬��ֹ����
        ListNode* pNode = pHead;       // ��ǰ���
        while(pNode != NULL)
        {
            ListNode* pNext = pNode->next;    // ��һ�����
            bool needDel = false;
            if(pNext != NULL && pNode->val == pNext->val)
                needDel = true;

            // û���ظ���㣬���±���
            if(!needDel)
            {
                pPreNode = pNode;
                pNode = pNode->next;
            }
            else
            {
                ListNode* ToBeDel = pNode;    // ��Ҫɾ���Ľ��
                int value = pNode ->val;
                // ɾ���ظ���Ԫ��
                while(ToBeDel != NULL && ToBeDel->val == value)
                {
                    pNext = ToBeDel->next;
                    delete ToBeDel;
                    ToBeDel = NULL;
                    ToBeDel = pNext;
                }
                // ǰһ�����Ϊ�գ�ɾ������ͷ���
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
