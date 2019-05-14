#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

/*
*双指针法：设置两个指向头结点的指针，先让一个指针往前走k步，
*然后两个指针同时向后遍历，第一个指针指向尾节点时，第二个指针指向的便是倒数第k个节点。
*/

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode *p = pListHead, *q = pListHead;
        unsigned int i = k-1;
        if(pListHead == NULL || k <= 0){
            return NULL;
        }
        while(i){
            if(p -> next != NULL){
                p = p -> next;
                i--;
            }
            else{
                return NULL;
            }
        }
        while(p -> next != NULL){
            p = p -> next;
            q = q -> next;
        }
        return q;
    }
};

/*创建链表*/
void creatList(ListNode *head)
{
    ListNode *p = head;
    ListNode *q;
    for(int i=1; i<10; i++){
        q = new ListNode(i);
        p -> next = q;
        p = q;
    }
}

int main()
{
    Solution s;
    ListNode *head = NULL;
    head = new ListNode(0);
    creatList(head);

    /*
    while(head != NULL){
       cout << head -> val << endl;
       head = head ->next;
    }*/

    cout << s.FindKthToTail(head, 6)->val << endl;
    return 0;
}
