/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* dummy = new ListNode(0);
        ListNode* current = head;
        while(current != NULL){
            ListNode* nextNode = current->next;
            ListNode* previous = dummy;
            while(previous->next != NULL && previous->next->val < current->val){
                previous = previous->next;
            }
            current->next = previous->next;
            previous->next = current;
            current = nextNode;
        }
        return dummy->next;
    }
};