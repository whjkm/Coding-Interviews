#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

//后序遍历时，遍历到一个节点，其左右子树已经遍历；
//依次自底向上判断，每个节点只需要遍历一次

class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int depth = 0;
        return IsBalance(pRoot, depth);
    }
    bool IsBalance(TreeNode* pRoot, int &depth)
    {
        if(pRoot == NULL)
            return true;
        int left = 0;
        int right = 0;
        if(IsBalance(pRoot->left, left) && (IsBalance(pRoot->right, right)))
        {
            if(abs(left - right) > 1)
                return false;
            depth = max(left, right) + 1;
            return true;
        }
        return false;
    }
};

// 剪枝
/*
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        return TreeDepth(pRoot) != -1;
    }

    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot == NULL)
            return 0;
        // 左子树的高度
        int left = TreeDepth(pRoot->left);
        // 如果左子树不是平衡的，则子结点也不是
        if(left == -1)
            return -1;
        // 右子树的高度
        int right = TreeDepth(pRoot->right);
        // 如果右子树不是平衡的，则子结点也不是
        if(right == -1)
            return -1;
        if(abs(left - right) > 1)
            return -1;
        return max(left, right) + 1;
    }
};
*/

/***
判断是否是平衡二叉树：如果每个结点的左右子树的深度相差都不过1，
对每个节点进行遍历，然后进行判断。一个结点可能会遍历多次。
***/
/*
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot == NULL)
            return true;
        int left = MaxDepth(pRoot->left);
        int right = MaxDepth(pRoot->right);
        int diff = left - right;
        if(diff > 1 || diff < -1)
            return false;

        return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);

    }
private:
    int MaxDepth(TreeNode* pRoot)
    {
        if(pRoot == NULL)
            return 0;
        return max(MaxDepth(pRoot->left), MaxDepth(pRoot->right)) + 1;
    }
};
*/
int main()
{

    return 0;
}
