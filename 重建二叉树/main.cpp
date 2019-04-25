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
˼·������ǰ���������������ؽ���������
������Ҫ���ڵ㣬ǰ������ĵ�һ���ڵ�������ĸ��ڵ㣻Ȼ��������������ҵ����ڵ��λ�ã�
��������������ڵ��λ�ã�������Ϊ�����������������֣�Ȼ��ݹ���н�����
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
                return root;           //ֻ��һ���ڵ�����
            }
        }
        //������������ҵ����ڵ��ֵ
        int *rootVin = vinBegin;
        while(rootVin <= vinEnd && *rootVin != rootValue){
            rootVin++;  //���ڵ�����������е�λ��
        }
        int leftLength = rootVin - vinBegin;
        int* preLeftEnd = preBegin + leftLength; // ��¼ǰ�����������������λ��
        if(leftLength > 0){
            //����������
            root->left = ConstructCore(preBegin+1, preLeftEnd, vinBegin, rootVin - 1);
        }
        if(leftLength < preEnd - preBegin){
            //����������
            root->right = ConstructCore(preLeftEnd+1, preEnd, rootVin + 1, vinEnd);
        }
        return root;
    }
};



