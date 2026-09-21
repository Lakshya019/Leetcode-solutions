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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* temp = head;
        while(temp != nullptr){
            n++;
            temp = temp->next;
        }
        int size = n / k;
        int extra = n % k;
        vector<ListNode*> ans;
        temp = head;
        for(int i = 0; i < k; i++){
            int partsize = size;
            if(extra > 0){
                partsize++;
                extra--;
            }
            if(partsize == 0){
                ans.push_back(nullptr);
                continue;
            }
            ListNode* partHead = temp;
            for(int j = 1; j < partsize; j++){
                temp = temp->next;
            }
            ListNode* nextPart = temp->next;
            temp->next = nullptr;
            ans.push_back(partHead);
            temp = nextPart;
        }
        return ans;
    }
};