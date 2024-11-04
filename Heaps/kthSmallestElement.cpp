class Solution {
public:
    int findKthSmallest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i = 0; i < k; i++){
            int element = nums[i];
            pq.push(element);
        }
        for(int i = k; i < nums.size(); i++){
            int element = nums[i];
            if(element < pq.top()){
                pq.pop();
                pq.push(element);
            }
        }
        return pq.top();
    }
};