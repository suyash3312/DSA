class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            int element = nums[i];
            while (!dq.empty() && element > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        for (int i = k; i < nums.size(); i++) {
            if (dq.empty()) {
                ans.push_back(0);
            } else {
                ans.push_back(nums[dq.front()]);
            }

            if (i - dq.front() >= k) {
                dq.pop_front();
            }

            int element = nums[i];
            while (!dq.empty() && element > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        if (dq.empty()) {
            ans.push_back(0);
        } else {
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};