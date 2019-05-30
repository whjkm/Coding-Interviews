#include <iostream>
#include <algorithm>
#include <vector>
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
*思路：树的根结点到叶子结点所经过的结点形成一条路径。
*前序遍历树结点，保存和为给定值的路径，用栈保存，依次将每个结点入栈；
*如果总和不为给定值，将元素出栈。
*/
class Solution {
public:
    vector<vector<int> > res;
    vector<int> path;    // 保存每次的路径
    void DFS(TreeNode* pNode, int sum){
        path.push_back(pNode->val);
        // 到达叶子结点，且路径和为给定的值。
        if(sum - pNode->val == 0 && !pNode->left && !pNode->right){
            res.push_back(path);
        }else{
            if(pNode -> left) DFS(pNode->left, sum - pNode->val);
            if(pNode -> right) DFS(pNode->right, sum - pNode->val);
        }
        path.pop_back();   //将当前结点移除
    }
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root)
            DFS(root, expectNumber);
        return res;
    }
};

int main()
{

    return 0;
}
