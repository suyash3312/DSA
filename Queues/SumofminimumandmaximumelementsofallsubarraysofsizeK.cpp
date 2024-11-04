#include<iostream>
#include<deque>
#include<vector>
using namespace std;
    int SumOfMinimumAndMaximumElements(vector<int>& nums, int k) {
        deque<int> dq, dq2;
        int ans = 0;
        for (int i = 0; i < k; i++) {
            int element = nums[i];
            while (!dq.empty() && element >= nums[dq.back()]) {
                dq.pop_back();
            }
            while (!dq2.empty() && element <= nums[dq2.back()]) {
                dq2.pop_back();
            }
            dq.push_back(i);
            dq2.push_back(i);
        }
        ans += (nums[dq.front()] + nums[dq2.front()]);
        for (int i = k; i < nums.size(); i++) {

            if (i - dq.front() >= k) {
                dq.pop_front();
            }
            if (i - dq2.front() >= k) {
                dq2.pop_front();
            }
            int element = nums[i];
            while (!dq.empty() && element >= nums[dq.back()]) {
                dq.pop_back();
            }
            while (!dq2.empty() && element <= nums[dq2.back()]) {
                dq2.pop_back();
            }
            dq.push_back(i);
            dq2.push_back(i);
            ans += (nums[dq.front()] + nums[dq2.front()]);
        }
        return ans;
    }
int main(){
  vector<int>nums{2, 5, -1, 7, -3, -1, -2};
  cout << SumOfMinimumAndMaximumElements(nums, 4);
}
