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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* first = list1;
        for(int i = 0; i < a - 1; i++){
            first = first->next;
        }
        ListNode* last = first;
        for(int i = 0; i < b-a+2; i++){
            last = last->next;
        }
        first->next = list2;
        ListNode* temp = list2;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = last;

        return list1;
    }
};