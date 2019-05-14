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
*˫ָ�뷨����������ָ��ͷ����ָ�룬����һ��ָ����ǰ��k����
*Ȼ������ָ��ͬʱ����������һ��ָ��ָ��β�ڵ�ʱ���ڶ���ָ��ָ��ı��ǵ�����k���ڵ㡣
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

/*��������*/
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
