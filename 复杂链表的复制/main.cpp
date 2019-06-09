#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

/*
*˼·������ԭʼ�����ϲ����������ƵĽ��������ԭʼ���ĺ��棬Ȼ��random���ָ��Ľڵ����úã�
*�������ż��ϵ��ԭʼ������Ϊ��������
*/

class Solution {
public:
    //��ԭʼ�����渴�ƽ�㡣
    void CloneNodes(RandomListNode* pHead){
        RandomListNode *pNode = pHead;
        while(pNode != NULL){
            RandomListNode *pClone = new RandomListNode(pNode -> label);
            pClone -> next = pNode -> next;
            pNode -> next = pClone;
            pNode = pClone -> next;
        }
    }

    // ����Random����λ��
    void ConnectRandomNodes(RandomListNode* pHead){
        RandomListNode *pNode = pHead;
        while(pNode != NULL){
            RandomListNode *pClone = pNode -> next;
            if(pNode -> random != NULL){
                pClone -> random = pNode -> random -> next;
            }
            pNode = pClone -> next;
        }
    }

    // ��ԭʼ������Ϊ��������
    RandomListNode* ReconnectNodes(RandomListNode* pHead){
        RandomListNode* pNode = pHead;
        RandomListNode* pCloneHead = NULL;
        RandomListNode* pCloneNode = NULL;

        //��ʼ��
        if(pNode != NULL){
            pCloneHead = pCloneNode = pNode -> next;
            pNode -> next = pCloneNode -> next;
            pNode = pNode -> next;
        }

        while(pNode != NULL){
            pCloneNode -> next = pNode -> next;
            pCloneNode = pCloneNode -> next;
            pNode -> next = pCloneNode -> next;
            pNode = pNode -> next;
        }
        return pCloneHead;
    }

    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead) return NULL;
        CloneNodes(pHead);
        ConnectRandomNodes(pHead);
        return ReconnectNodes(pHead);
    }
};


//��ϣ��:�ù�ϣ��洢ԭʼ���͸��ƽ���ӳ�䡣
/*
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == nullptr){
            return nullptr;
        }
        unordered_map<RandomListNode* ,RandomListNode*> HashMap;
        //����Next���
        for(RandomListNode* pNode = pHead; pNode != nullptr; pNode = pNode->next){
            HashMap[pNode] = new RandomListNode(pNode->label);
        }
        //���Ӹ��ƵĽ��
        for(RandomListNode* pNode = pHead; pNode != nullptr; pNode = pNode->next){
            HashMap[pNode] -> next = HashMap[pNode -> next];
            HashMap[pNode] -> random = HashMap[pNode -> random];
        }
        return HashMap[pHead];
    }
};
*/

//����ͼ������������ͼ����
/*
class Solution {
    map<RandomListNode*, RandomListNode*> HashMap;
    set<RandomListNode*> visit;
    //����next���
    void DFS1(RandomListNode* u){
        //�����н�㸴�Ƶ�hashmap��
        if(u && HashMap.find(u) == HashMap.end()){
            HashMap[u] = new RandomListNode(u -> label);
            DFS1(u -> next);
            DFS2(u -> random);
        }
    }

    //����random���
    void DFS2(RandomListNode* u){
        if(u && visit.find(u) == visit.end()){
            if(u -> next) HashMap[u] -> next = HashMap[u->next];
            if(u -> random) HashMap[u] -> random = HashMap[u->random];
            visit.insert(u);  // ����Ƿ���ʹ�
            DFS2(u->next);
            DFS2(u->random);
        }
    }

public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead) return NULL;
        HashMap.clear();
        visit.clear();
        DFS1(pHead);
        DFS2(pHead);
        return HashMap[pHead];
    }
};
*/


int main()
{

    return 0;
}
