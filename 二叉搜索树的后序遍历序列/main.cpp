#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
/*
*思路：递归，根据BST的性质，左子树结点的值，它们都比根结点小；
*右子树节点的值，它们都比根结点大；然后根据后序遍历的序列将节点分为左右子树；
*然后左右子树分别判断是不是BST;
*/
/*
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        return BST(sequence, 0, sequence.size()-1);
    }
    bool BST(vector<int> sequence, int begin, int end){
        if(sequence.empty() || begin > end) return false;
        int root = sequence[end];   //后序遍历根节点的值
        int i = begin;              //划分左右子树
        for(; i < end; ++i){
            if(sequence[i] > root)  //找到左子树的根节点的位置
                break;
        }
        int j = i;
        for(; j < end; ++j){
            if(sequence[j] < root)   //BST中右子树的值要大于根结点
                return false;
        }
        bool left = true;
        if(i > begin)
            BST(sequence, begin, i-1);    //判断左子树
        bool right = true;
        if(j < end - 1)
            BST(sequence, i, end-1);      //判断右子树
        return left && right;
    }
};
*/

//非递归
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty()) return false;
        int length = sequence.size();
        int i=0;
        while(--length){
            while(sequence[i++] < sequence[length]);
            while(i < length && sequence[i++] > sequence[length]);
            if(i < length) return false;
            i = 0;
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<int> sequence = {5,7,6,9,11,10,8};
    cout << s.VerifySquenceOfBST(sequence) << endl;
    return 0;
}
