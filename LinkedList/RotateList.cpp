class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0){
            return head;
        }
        ListNode* current=head;
        int length=1;
        while(current->next!=NULL){
            current=current->next;
            length++;
        }
        current->next=head;
        k=k%length;
        int NodesToSkip=length-k;
        ListNode* newTail=head;
        while(NodesToSkip!=1){
            newTail=newTail->next;
            NodesToSkip--;
        }
        ListNode* newHead=newTail->next;
        newTail->next=NULL;
        return newHead;

    }
};