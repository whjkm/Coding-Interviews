#include <iostream>
#include <vector>
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

/*
˼·��
�������ö�������˵��Ҫ�ж�B�ǲ���A���ӽṹ�����ȵ�һ������A�в�����B���ڵ��ֵһ���Ľڵ㡣
ͨ�����ڲ�������ĳһ���ڵ㣬���Ƕ��ǲ��õݹ�ķ�����������������
�ڶ��������ж���A����RΪ���ڵ�������ǲ��Ǻ���B������ͬ�Ľṹ��
����ͬ�����õ��˵ݹ�ķ���������ڵ�R��ֵ�����ĸ��ڵ㲻��ͬ������RΪ���ڵ����������B�϶���������ͬ�Ľڵ㣻
�������ֵ����ͬ�ģ���ݹ���жϸ��Ե����ҽڵ��ֵ�ǲ�����ͬ��
�ݹ����ֹ���������Ǵﵽ����A������B��Ҷ�ڵ㡣
*/

class Solution {
public:
    bool DoseTree1HaveTree2(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        //������tree2��Ҷ�ӽڵ㣬˵��tree2������ϡ�
        if(pRoot2 == NULL)
            return true;
        //������tree1��û��ƥ��ɹ�
        if(pRoot1 == NULL)
            return false;
        if(pRoot1 -> val != pRoot2 -> val)
            return false;

        //ֻ�е������ڵ��ֵ���ʱ�����ű������ǵ���������
        return DoseTree1HaveTree2(pRoot1->left, pRoot2->left) &&
        DoseTree1HaveTree2(pRoot1->right, pRoot2->right);
    }

    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool result = false;
        if(!pRoot1 || !pRoot2)  return false;
        if(pRoot1 != NULL && pRoot2 != NULL){
            //��tree1���ҵ���tree2�ĸ��ڵ�ĵ�
            if(pRoot1 -> val == pRoot2 -> val)
                //��������ڵ�Ϊ��㣬�ж��Ƿ����tree2
                result = DoseTree1HaveTree2(pRoot1, pRoot2);
            //����������������
            if(!result)
                result = HasSubtree(pRoot1 -> left, pRoot2);
            //����������������
            if(!result)
                result = HasSubtree(pRoot1 -> right, pRoot2);
        }
        return result;
    }
};

int main()
{

    return 0;
}
