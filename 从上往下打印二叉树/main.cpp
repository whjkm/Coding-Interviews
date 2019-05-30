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
*˼·��BFS���������Ĳ������������������ʵ�֣��Ƚ����ڵ���ӣ�Ȼ���ж������ӽڵ��Ƿ񶼴��ڣ�
*Ȼ�������ӽڵ���ӣ�������Ԫ�س��ӣ�������ֵ��vector���档
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
