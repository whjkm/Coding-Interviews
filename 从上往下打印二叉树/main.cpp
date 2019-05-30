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

/*
*思路：BFS，二叉树的层序遍历，借助队列来实现，先将根节点入队，然后判断左右子节点是否都存在；
*然后将左右子节点入队，将队首元素出队，将它的值用vector保存。
*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        queue<TreeNode *> node;
        vector<int> m_data;
        if(root == NULL)  return m_data;
        node.push(root);
        while(!node.empty()){
           TreeNode *tmp = node.front();
           m_data.push_back(tmp -> val);
           node.pop();
           if(tmp -> left != NULL){
              node.push(tmp -> left);
           }
           if(tmp -> right != NULL){
              node.push(tmp -> right);
           }
        }
        return m_data;
    }
};


int main()
{

    return 0;
}
