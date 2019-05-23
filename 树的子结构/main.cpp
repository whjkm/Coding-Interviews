#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

/*
思路：
对于两棵二叉树来说，要判断B是不是A的子结构，首先第一步在树A中查找与B根节点的值一样的节点。
通常对于查找树中某一个节点，我们都是采用递归的方法来遍历整棵树。
第二步就是判断树A中以R为根节点的子树是不是和树B具有相同的结构。
这里同样利用到了递归的方法，如果节点R的值和树的根节点不相同，则以R为根节点的子树和树B肯定不具有相同的节点；
如果它们值是相同的，则递归的判断各自的左右节点的值是不是相同。
递归的终止条件是我们达到了树A或者树B的叶节点。
*/

class Solution {
public:
    bool DoseTree1HaveTree2(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        //遍历到tree2的叶子节点，说明tree2遍历完毕。
        if(pRoot2 == NULL)
            return true;
        //遍历完tree1，没有匹配成功
        if(pRoot1 == NULL)
            return false;
        if(pRoot1 -> val != pRoot2 -> val)
            return false;

        //只有当两个节点的值相等时，接着遍历它们的左右子树
        return DoseTree1HaveTree2(pRoot1->left, pRoot2->left) &&
        DoseTree1HaveTree2(pRoot1->right, pRoot2->right);
    }

    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool result = false;
        if(!pRoot1 || !pRoot2)  return false;
        if(pRoot1 != NULL && pRoot2 != NULL){
            //在tree1中找到了tree2的根节点的点
            if(pRoot1 -> val == pRoot2 -> val)
                //以这个根节点为起点，判断是否包含tree2
                result = DoseTree1HaveTree2(pRoot1, pRoot2);
            //从左子树继续遍历
            if(!result)
                result = HasSubtree(pRoot1 -> left, pRoot2);
            //从右子树继续遍历
            if(!result)
                result = HasSubtree(pRoot1 -> right, pRoot2);
        }
        return result;
    }
};

int main()
{

    return 0;
}
