#include <iostream>
#include <algorithm>
using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};

/***
�����������
   1.�����ǰ���������������ô��һ���������������������㡣
   2.�����ǰ���û���������������������������ӽ�㣬��ô��һ�����������ĸ���㡣
   3.�����ǰ����û�������������һ��������������ӽ�㣺
     ��ô����ָ�򸸽���ָ��һֱ���ϱ�����ֱ���ҵ�һ���������������ӽ��Ľ�㡣
     ��������Ľ����ڣ���ô������ĸ�����������Ҫ�ҵ���һ����㡣
***/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == NULL)
            return NULL;
        TreeLinkNode* pNext = NULL;
        // ��ǰ���������������һ���ڵ�����������������㡣
        if(pNode ->right != NULL)
        {
            TreeLinkNode* pRight = pNode->right;
            while(pRight->left != NULL)
                pRight = pRight->left;    // ��������
            pNext = pRight;
        }
        // û�������������
        else if(pNode ->next != NULL)
        {
            TreeLinkNode* pCurrent = pNode;
            TreeLinkNode* pParent = pNode ->next;
            // ��û�������������һ��������ڵ�����ӽ�㡣
            while(pParent != NULL && pCurrent == pParent->right)
            {
                pCurrent = pParent;
                pParent = pParent ->next;   // ���Ÿ��ڵ�һֱ���ϱ���
            }
            pNext = pParent;   // �Ǹ��ڵ�����ӽ�㣬��һ���ڵ���Ǹ����
        }
        return pNext;
    }
};

int main()
{

    return 0;
}
