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
*思路：中序遍历树中的每一个结点；
然后将分别把左右子树都转换成排序的双向链表再和根节点链接起来；
*/
/*
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == nullptr) return nullptr;
        TreeNode* pre = nullptr;
        ConvertNode(pRootOfTree, pre);

        //返回双向链表的头结点。
        TreeNode* pHeadofList = pre;
        while(pHeadofList != nullptr && pHeadofList->left != nullptr){
            pHeadofList = pHeadofList -> left;
        }
        return pHeadofList;
    }
    //中序遍历
    void ConvertNode(TreeNode* pNode, TreeNode*& pre){
        if(pNode == nullptr) return ;

        TreeNode* pCurrent = pNode;
        //遍历左子树
        if(pCurrent -> left != nullptr){
            ConvertNode(pCurrent->left, pre);
        }
        pCurrent->left = pre;
        if(pre != nullptr)
            pre -> right = pCurrent;
        pre = pCurrent;
        //遍历右子树
        if(pCurrent->right != nullptr){
            ConvertNode(pCurrent->right, pre);
        }
    }
};
*/

/*
非递归中序遍历；
*/
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == nullptr) return nullptr;
        stack<TreeNode*> st;
        TreeNode* pNode = pRootOfTree;
        TreeNode* pre = nullptr;  //pre记录上一次出栈值
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
                    pHead = pNode;  //pre为空，表示st第一次出栈,即为最左值
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
