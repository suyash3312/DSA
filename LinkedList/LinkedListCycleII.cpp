// Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
            if(slow==fast){
                slow=head;
                while(fast!=NULL){
                    if(slow==fast){
                        return slow;
                    }
                    slow=slow->next;
                    fast=fast->next;
                }
            }
        }
        return NULL;
    }
};