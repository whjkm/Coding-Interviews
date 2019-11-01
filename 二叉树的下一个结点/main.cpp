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
有三种情况：
   1.如果当前结点有右子树，那么下一个结点就是右子树的最左结点。
   2.如果当前结点没有右子树，但是是它父结点的左子结点，那么下一个结点就是他的父结点。
   3.如果当前结点既没有右子树，并且还是它父结点的右子结点：
     那么沿着指向父结点的指针一直向上遍历，直到找到一个是它父结点的左子结点的结点。
     如果这样的结点存在，那么这个结点的父结点就是我们要找的下一个结点。
***/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == NULL)
            return NULL;
        TreeLinkNode* pNext = NULL;
        // 当前结点有右子树，下一个节点就是右子树的最左结点。
        if(pNode ->right != NULL)
        {
            TreeLinkNode* pRight = pNode->right;
            while(pRight->left != NULL)
                pRight = pRight->left;    // 找最左结点
            pNext = pRight;
        }
        // 没有右子树的情况
        else if(pNode ->next != NULL)
        {
            TreeLinkNode* pCurrent = pNode;
            TreeLinkNode* pParent = pNode ->next;
            // 既没有右子树，而且还是他父节点的右子结点。
            while(pParent != NULL && pCurrent == pParent->right)
            {
                pCurrent = pParent;
                pParent = pParent ->next;   // 沿着父节点一直向上遍历
            }
            pNext = pParent;   // 是父节点的左子结点，下一个节点就是父结点
        }
        return pNext;
    }
};

int main()
{

    return 0;
}
