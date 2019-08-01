#include <iostream>
#include <algorithm>
#include <vector>
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
/***
�ǵݹ�д�����������;
��������������ܲ�����
***/
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot == NULL)
            return 0;
        queue<TreeNode*> que;
        que.push(pRoot);
        int depth = 0;
        while(!que.empty())
        {
            int size = que.size();
            depth++;
            for(int i=0; i < size; ++i)
            {
                TreeNode *node = que.front();
                que.pop();
                if(node -> left != NULL)
                    que.push(node -> left);
                if(node -> right != NULL)
                    que.push(node -> right);
            }
        }
        return depth;
    }
};

/***
�ݹ�ⷨ:
���һ����ֻ��һ����㣬�������Ϊ1��
��������ֻ����������û������������ô�������Ӧ����������������ȼ�1��
ͬ�����û������������������������ȼ�1��
��������������������������Ǹ�������Ⱦ�����������������ȵĽϴ�ֵ�ټ�1��
***/
/*
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot == NULL)
            return 0;
        int nLeft = TreeDepth(pRoot -> left);
        int nRight = TreeDepth(pRoot -> right);

        return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
    }
};*/

int main()
{

    return 0;
}
