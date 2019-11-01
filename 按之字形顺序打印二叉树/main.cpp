#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

// 使用两个栈
class Solution {
public:
    vector<vector<int>> Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if(pRoot == NULL) return res;
        stack<TreeNode*> st1, st2;
        st1.push(pRoot);
        while(!st1.empty() || !st2.empty())
        {
            vector<int> tmp;
            if(!st1.empty())
            {
                while(!st1.empty())
                {
                    TreeNode *top = st1.top();
                    st1.pop();
                    tmp.push_back(top->val);
                    if(top->left) st2.push(top->left);
                    if(top->right) st2.push(top->right);
                }
                res.push_back(tmp);
            }
            else if(!st2.empty())
            {
                while(!st2.empty())
                {
                    TreeNode *top = st2.top();
                    st2.pop();
                    tmp.push_back(top->val);
                    if(top->right) st1.push(top->right);
                    if(top->left)  st1.push(top->left);
                }
                res.push_back(tmp);
            }
        }
        return res;
    }
};


// 分为奇数和偶数，偶数就将vector逆置
/*
class Solution {
public:
    vector<vector<int>> Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if(pRoot == NULL)
            return res;
        queue<TreeNode*> qu;
        vector<int> tmp;
        qu.push(pRoot);
        bool even = false;
        while(!qu.empty())
        {
            tmp.clear();
            const int size = qu.size();
            for(int i = 0; i < size; ++i)
            {
                TreeNode *top = qu.front();
                qu.pop();
                tmp.push_back(top->val);
                if(top->left) qu.push(top->left);
                if(top->right) qu.push(top->right);
            }
            if(even)
                reverse(tmp.begin(), tmp.end());
            res.push_back(tmp);
            even = !even;
        }
        return res;
    }
};
*/


int main()
{

    return 0;
}
