class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy=new ListNode(0);
        ListNode* current=dummy;
        ListNode* ptr=head->next;
        int sum=0;
        while(ptr!=NULL){
            if(ptr->val == 0){
                current->next=new ListNode(sum);
                current=current->next;
                sum=0;
            }
            sum=sum+ptr->val;
            
            ptr=ptr->next;
        }
        return dummy->next;
    }
};