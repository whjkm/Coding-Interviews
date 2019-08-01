#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

//�������ʱ��������һ���ڵ㣬�����������Ѿ�������
//�����Ե������жϣ�ÿ���ڵ�ֻ��Ҫ����һ��

class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int depth = 0;
        return IsBalance(pRoot, depth);
    }
    bool IsBalance(TreeNode* pRoot, int &depth)
    {
        if(pRoot == NULL)
            return true;
        int left = 0;
        int right = 0;
        if(IsBalance(pRoot->left, left) && (IsBalance(pRoot->right, right)))
        {
            if(abs(left - right) > 1)
                return false;
            depth = max(left, right) + 1;
            return true;
        }
        return false;
    }
};

// ��֦
/*
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        return TreeDepth(pRoot) != -1;
    }

    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot == NULL)
            return 0;
        // �������ĸ߶�
        int left = TreeDepth(pRoot->left);
        // �������������ƽ��ģ����ӽ��Ҳ����
        if(left == -1)
            return -1;
        // �������ĸ߶�
        int right = TreeDepth(pRoot->right);
        // �������������ƽ��ģ����ӽ��Ҳ����
        if(right == -1)
            return -1;
        if(abs(left - right) > 1)
            return -1;
        return max(left, right) + 1;
    }
};
*/

/***
�ж��Ƿ���ƽ������������ÿ�������������������������1��
��ÿ���ڵ���б�����Ȼ������жϡ�һ�������ܻ������Ρ�
***/
/*
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot == NULL)
            return true;
        int left = MaxDepth(pRoot->left);
        int right = MaxDepth(pRoot->right);
        int diff = left - right;
        if(diff > 1 || diff < -1)
            return false;

        return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);

    }
private:
    int MaxDepth(TreeNode* pRoot)
    {
        if(pRoot == NULL)
            return 0;
        return max(MaxDepth(pRoot->left), MaxDepth(pRoot->right)) + 1;
    }
};
*/
int main()
{

    return 0;
}
