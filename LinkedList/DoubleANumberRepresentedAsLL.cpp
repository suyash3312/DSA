class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* prevNode=NULL;
        ListNode* currNode=head;
        
        while(currNode!=NULL){
            ListNode* temp=currNode->next;
            currNode->next=prevNode;
            prevNode=currNode;
            currNode=temp;
        }
        return prevNode;
    }
    ListNode* doubleIt(ListNode* head) {
        if(head == NULL){
            return head;
        }
        ListNode* temp=reverse(head);
        ListNode* temporaryHead=new ListNode(0);
        temporaryHead->next=temp;
        int carry=0;
        while(temp!=NULL){
            int multipliedValue=temp->val * 2;
            if(carry!=0){
                multipliedValue = multipliedValue + carry;
            }
            int digit=multipliedValue % 10;
            carry=multipliedValue / 10;
            temp->val=digit;
            temp=temp->next;
        }
        if(carry!=0){
            head->next=new ListNode(carry);
            head=head->next;
        }
        return reverse(temporaryHead->next);
    }
};