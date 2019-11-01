#include <iostream>
#include <algorithm>
#include <vector>
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

// 用栈实现，两两配对输出
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot == NULL) return true;
        stack<TreeNode*> st;
        st.push(pRoot->left);
        st.push(pRoot->right);
        while(!st.empty())
        {
            TreeNode* left = st.top();
            st.pop();
            TreeNode* right = st.top();
            st.pop();
            if(left == NULL && right == NULL)
                continue;
            if(left == NULL || right == NULL)
                return false;
            if(left->val != right->val)
                return false;
            st.push(left->left);
            st.push(right->right);
            st.push(left->right);
            st.push(right->left);
        }
        return true;
    }
};

// 递归
/*
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot == NULL) return true;
        return judge(pRoot->left, pRoot->right);
    }
    bool judge(TreeNode* left, TreeNode* right)
    {
        if(left == NULL && right == NULL)
            return true;
        if(left == NULL || right == NULL)
            return false;
        return left->val == right->val
               && judge(left->left, right->right)
               && judge(left->right, right->left);
    }
};
*/


int main()
{

    return 0;
}
