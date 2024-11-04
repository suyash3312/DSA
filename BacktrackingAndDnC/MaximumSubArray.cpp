class Solution {
public:
    int maxSubArrayFinder(vector<int>& nums, int start, int end) {
        // Base case: when there's only one element, return it
        if (start == end) {
            return nums[start];
        }

        // Correct midpoint calculation
        int mid = start + (end - start) / 2;

        // Recursively find the maximum sum on the left and right halves
        int maxLeftSum = maxSubArrayFinder(nums, start, mid);
        int maxRightSum = maxSubArrayFinder(nums, mid + 1, end);

        // Calculate the maximum sum crossing the midpoint
        int leftBorderSum = INT_MIN, rightBorderSum = INT_MIN;
        int sum = 0;

        // Calculate max sum crossing to the left
        for (int i = mid; i >= start; i--) {
            sum += nums[i];
            leftBorderSum = max(leftBorderSum, sum);
        }

        sum = 0;
        // Calculate max sum crossing to the right
        for (int i = mid + 1; i <= end; i++) {
            sum += nums[i];
            rightBorderSum = max(rightBorderSum, sum);
        }

        int crossBorderSum = leftBorderSum + rightBorderSum;

        // Return the maximum of left, right, or cross-border sums
        return max(maxLeftSum, max(crossBorderSum, maxRightSum));
    }

    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0; // Handle empty input array edge case
        }
        return maxSubArrayFinder(nums, 0, nums.size() - 1);
    }
};
