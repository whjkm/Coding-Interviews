#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
/*
*˼·���ݹ飬����BST�����ʣ�����������ֵ�����Ƕ��ȸ����С��
*�������ڵ��ֵ�����Ƕ��ȸ�����Ȼ����ݺ�����������н��ڵ��Ϊ����������
*Ȼ�����������ֱ��ж��ǲ���BST;
*/
/*
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        return BST(sequence, 0, sequence.size()-1);
    }
    bool BST(vector<int> sequence, int begin, int end){
        if(sequence.empty() || begin > end) return false;
        int root = sequence[end];   //����������ڵ��ֵ
        int i = begin;              //������������
        for(; i < end; ++i){
            if(sequence[i] > root)  //�ҵ��������ĸ��ڵ��λ��
                break;
        }
        int j = i;
        for(; j < end; ++j){
            if(sequence[j] < root)   //BST����������ֵҪ���ڸ����
                return false;
        }
        bool left = true;
        if(i > begin)
            BST(sequence, begin, i-1);    //�ж�������
        bool right = true;
        if(j < end - 1)
            BST(sequence, i, end-1);      //�ж�������
        return left && right;
    }
};
*/

//�ǵݹ�
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
