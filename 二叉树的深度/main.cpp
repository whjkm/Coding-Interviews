#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
/***
非递归写法，层序遍历;
按层遍历，计算总层数。
***/
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot == NULL)
            return 0;
        queue<TreeNode*> que;
        que.push(pRoot);
        int depth = 0;
        while(!que.empty())
        {
            int size = que.size();
            depth++;
            for(int i=0; i < size; ++i)
            {
                TreeNode *node = que.front();
                que.pop();
                if(node -> left != NULL)
                    que.push(node -> left);
                if(node -> right != NULL)
                    que.push(node -> right);
            }
        }
        return depth;
    }
};

/***
递归解法:
如果一颗树只有一个结点，它的深度为1；
如果根结点只有左子树而没有右子树，那么树的深度应该是其左子树的深度加1；
同理，如果没有左子树，就是右子树的深度加1；
如果既有右子树又有左子树，那该树的深度就是其左、右子树的深度的较大值再加1。
***/
/*
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot == NULL)
            return 0;
        int nLeft = TreeDepth(pRoot -> left);
        int nRight = TreeDepth(pRoot -> right);

        return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
    }
};*/

int main()
{

    return 0;
}
