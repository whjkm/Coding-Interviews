#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <cstring>
using namespace std;

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/***
思路：根据前序遍历和中序遍历重建二叉树。
建树需要根节点，前序遍历的第一个节点就是树的根节点；然后在中序遍历中找到根节点的位置；
根据中序遍历根节点的位置，将树分为左子树和右子树部分，然后递归进行建树。
***/
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
         if(pre.size() == 0 || vin.size() == 0){
            return nullptr;
         }
         int *preBegin = &pre[0];
         int *preEnd = &pre[pre.size() - 1];
         int *vinBegin = &vin[0];
         int *vinEnd = &vin[vin.size() - 1];
         return ConstructCore(preBegin, preEnd, vinBegin, vinEnd);
    }
    TreeNode* ConstructCore(int* preBegin, int* preEnd, int* vinBegin, int* vinEnd){
        int rootValue = preBegin[0];
        TreeNode* root = new TreeNode(preBegin[0]);
        root->val = rootValue;
        root->left = nullptr;
        root->right = nullptr;
        if(preBegin == preEnd){
            if(vinBegin == vinEnd && *preBegin == *vinBegin){
                return root;           //只有一个节点的情况
            }
        }
        //从中序遍历中找到根节点的值
        int *rootVin = vinBegin;
        while(rootVin <= vinEnd && *rootVin != rootValue){
            rootVin++;  //根节点在中序遍历中的位置
        }
        int leftLength = rootVin - vinBegin;
        int* preLeftEnd = preBegin + leftLength; // 记录前序遍历左子树结束的位置
        if(leftLength > 0){
            //构建左子树
            root->left = ConstructCore(preBegin+1, preLeftEnd, vinBegin, rootVin - 1);
        }
        if(leftLength < preEnd - preBegin){
            //构建右子树
            root->right = ConstructCore(preLeftEnd+1, preEnd, rootVin + 1, vinEnd);
        }
        return root;
    }
};



