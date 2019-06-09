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
*思路：先在原始链表上操作，将复制的结点链接在原始结点的后面，然后将random结点指向的节点设置好；
*最后按照奇偶关系将原始链表拆分为两个链表。
*/

class Solution {
public:
    //在原始结点后面复制结点。
    void CloneNodes(RandomListNode* pHead){
        RandomListNode *pNode = pHead;
        while(pNode != NULL){
            RandomListNode *pClone = new RandomListNode(pNode -> label);
            pClone -> next = pNode -> next;
            pNode -> next = pClone;
            pNode = pClone -> next;
        }
    }

    // 复制Random结点的位置
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

    // 将原始链表拆分为两个链表
    RandomListNode* ReconnectNodes(RandomListNode* pHead){
        RandomListNode* pNode = pHead;
        RandomListNode* pCloneHead = NULL;
        RandomListNode* pCloneNode = NULL;

        //初始化
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


//哈希表法:用哈希表存储原始结点和复制结点的映射。
/*
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == nullptr){
            return nullptr;
        }
        unordered_map<RandomListNode* ,RandomListNode*> HashMap;
        //复制Next结点
        for(RandomListNode* pNode = pHead; pNode != nullptr; pNode = pNode->next){
            HashMap[pNode] = new RandomListNode(pNode->label);
        }
        //链接复制的结点
        for(RandomListNode* pNode = pHead; pNode != nullptr; pNode = pNode->next){
            HashMap[pNode] -> next = HashMap[pNode -> next];
            HashMap[pNode] -> random = HashMap[pNode -> random];
        }
        return HashMap[pHead];
    }
};
*/

//有向图法：当成有向图处理
/*
class Solution {
    map<RandomListNode*, RandomListNode*> HashMap;
    set<RandomListNode*> visit;
    //遍历next结点
    void DFS1(RandomListNode* u){
        //将所有结点复制到hashmap中
        if(u && HashMap.find(u) == HashMap.end()){
            HashMap[u] = new RandomListNode(u -> label);
            DFS1(u -> next);
            DFS2(u -> random);
        }
    }

    //遍历random结点
    void DFS2(RandomListNode* u){
        if(u && visit.find(u) == visit.end()){
            if(u -> next) HashMap[u] -> next = HashMap[u->next];
            if(u -> random) HashMap[u] -> random = HashMap[u->random];
            visit.insert(u);  // 标记是否访问过
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
