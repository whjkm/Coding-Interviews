#include <iostream>
#include <vector>
#include <algorithm>
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

// 层序遍历
class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int>> res;
            if(pRoot == NULL) return res;
            queue<TreeNode*> qu;
            qu.push(pRoot);
            vector<int> tmp;
            int len = 1;
            while(!qu.empty())
            {
                TreeNode *top = qu.front();
                qu.pop();
                tmp.push_back(top->val);
                if(top->left) qu.push(top->left);
                if(top->right) qu.push(top->right);
                if(--len == 0)
                {
                    len = qu.size();
                    res.push_back(tmp);
                    tmp.clear();
                }
            }
            return res;
        }
};

int main()
{

    return 0;
}
