class Solution {
public:
    class compare{
        public:
        bool operator()(ListNode* a, ListNode* b){
            return a -> val > b -> val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        ListNode* head = NULL;
        ListNode* tail = NULL;
        for(int i = 0; i < lists.size(); i++){
            ListNode* temp = lists[i];
            if(temp != NULL)
                pq.push(temp);
        }

        while(!pq.empty()){
            ListNode* topNode = pq.top();
            pq.pop();
            
            if(head == NULL){
                head = topNode;
                tail = topNode;
                if(tail -> next != NULL){
                    pq.push(tail -> next);
                }
            }else{
                tail -> next = topNode;
                tail = topNode;
                if(tail -> next != NULL){
                    pq.push(tail -> next);
                }
            }
        }
        return head;
    }
};