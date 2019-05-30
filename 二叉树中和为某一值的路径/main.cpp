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
*˼·�����ĸ���㵽Ҷ�ӽ���������Ľ���γ�һ��·����
*ǰ���������㣬�����Ϊ����ֵ��·������ջ���棬���ν�ÿ�������ջ��
*����ܺͲ�Ϊ����ֵ����Ԫ�س�ջ��
*/
class Solution {
public:
    vector<vector<int> > res;
    vector<int> path;    // ����ÿ�ε�·��
    void DFS(TreeNode* pNode, int sum){
        path.push_back(pNode->val);
        // ����Ҷ�ӽ�㣬��·����Ϊ������ֵ��
        if(sum - pNode->val == 0 && !pNode->left && !pNode->right){
            res.push_back(path);
        }else{
            if(pNode -> left) DFS(pNode->left, sum - pNode->val);
            if(pNode -> right) DFS(pNode->right, sum - pNode->val);
        }
        path.pop_back();   //����ǰ����Ƴ�
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
