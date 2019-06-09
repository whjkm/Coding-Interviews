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

/*
*˼·������������е�ÿһ����㣻
Ȼ�󽫷ֱ������������ת���������˫�������ٺ͸��ڵ�����������
*/
/*
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == nullptr) return nullptr;
        TreeNode* pre = nullptr;
        ConvertNode(pRootOfTree, pre);

        //����˫�������ͷ��㡣
        TreeNode* pHeadofList = pre;
        while(pHeadofList != nullptr && pHeadofList->left != nullptr){
            pHeadofList = pHeadofList -> left;
        }
        return pHeadofList;
    }
    //�������
    void ConvertNode(TreeNode* pNode, TreeNode*& pre){
        if(pNode == nullptr) return ;

        TreeNode* pCurrent = pNode;
        //����������
        if(pCurrent -> left != nullptr){
            ConvertNode(pCurrent->left, pre);
        }
        pCurrent->left = pre;
        if(pre != nullptr)
            pre -> right = pCurrent;
        pre = pCurrent;
        //����������
        if(pCurrent->right != nullptr){
            ConvertNode(pCurrent->right, pre);
        }
    }
};
*/

/*
�ǵݹ����������
*/
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == nullptr) return nullptr;
        stack<TreeNode*> st;
        TreeNode* pNode = pRootOfTree;
        TreeNode* pre = nullptr;  //pre��¼��һ�γ�ջֵ
        TreeNode* pHead = nullptr;
        while(pNode!=nullptr || !st.empty()){
            while(pNode != nullptr){
                st.push(pNode);
                pNode = pNode -> left;
            }
            if(!st.empty()){
                pNode = st.top();
                st.pop();
                if(pre != nullptr){
                    pre -> right = pNode;
                    pNode -> left = pre;
                }else{
                    pHead = pNode;  //preΪ�գ���ʾst��һ�γ�ջ,��Ϊ����ֵ
                }
                pre = pNode;
                pNode = pNode -> right;
            }
        }
        return pHead;
    }
};


int main()
{

    return 0;
}
