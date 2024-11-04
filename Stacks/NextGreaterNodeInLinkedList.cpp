class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ll;
        while(head){
            ll.push_back(head->val);
            head=head->next;
        }
        stack<int>st;
        vector<int> ans(ll.size(), 0); 
        for(i=0; i<ll.size(); i++){
            while(!st.empty() && ll[i] > ll[st.top()]){
                int temp=st.top();
                st.pop();
                ans[temp]=ll[i];
            }
            st.push_back(i);
        }
        return ans;                 
    }
};