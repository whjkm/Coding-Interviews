#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
typedef TreeNode* BiTree;

/*
思路：先前序遍历这颗树的每个结点，如果遍历到的结点有子结点，就交换它的两个子结点，
当交换完所有非叶子结点的左右子结点之后，就得到了树的镜像。
*/

class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if(pRoot == NULL)
            return ;
        if(pRoot -> left == NULL && pRoot -> right == NULL)
            return ;

        TreeNode *pTemp = pRoot->left;
        pRoot -> left = pRoot -> right;
        pRoot -> right = pTemp;

        if(pRoot -> left)
            Mirror(pRoot -> left);
        if(pRoot -> right)
            Mirror(pRoot -> right);
    }
};

//栈的非递归
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if(pRoot == NULL)
            return ;
        if(pRoot -> left == NULL && pRoot -> right == NULL)
            return ;
        stack<TreeNode *> st;
        TreeNode *p = NULL;
        st.push(pRoot);
        while(st.size()){
            p = st.top();
            st.pop();
            swap(p->left, p->right);
            if(p->left) st.push(p->left);
            if(p->right) st.push(p->right);
        }
    }
};


//递归建树
void createTree(BiTree &T){
    int num;
    cin >> num;
    if(num == 0){
        T = NULL;
    }else{
        T = new TreeNode(num);
        createTree(T->left);
        createTree(T->right);
    }
}

void preTraverse(BiTree T){
    if(T){
        cout << T -> val << endl;
        preTraverse(T->left);
        preTraverse(T->right);
    }
}

int main()
{
    BiTree T;
    createTree(T);
    cout << "end" << endl;
    preTraverse(T);
    Solution s;
    s.Mirror(T);
    preTraverse(T);
    return 0;
}

