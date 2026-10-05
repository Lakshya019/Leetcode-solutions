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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head->next;
        ListNode* ans = nullptr;
        ListNode* tail = nullptr;
        int s = 0;
        while(temp != nullptr){
            if(temp->val != 0){
                s += temp->val;
            }else{
                ListNode* newNode = new ListNode(s);
                if(ans == nullptr){
                    ans = newNode;
                    tail = newNode;
                }else{
                    tail->next = newNode;
                    tail = newNode;
                }
                s = 0;
            }
            temp = temp->next;
        }
        return ans;
    }
};