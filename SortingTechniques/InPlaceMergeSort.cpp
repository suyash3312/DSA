class Solution {
public:
    void InPlaceMergeSort(vector<int>& nums, int start, int end){
        int size = nums.size();
        int gap = ((size / 2) + (size % 2));
        while(gap > 0){
            int i = start, j = start + gap;
            while(j <= end){
                if(nums[i] > nums[j]){
                    swap(nums[i], nums[j]);
                }
                i++, j++;
            }
            gap = (gap <=1)? 0 : ((gap/2) + (gap % 2));
        }
    }
    void mergeSort(vector<int>& nums, int start, int end){
        if(start >= end){
            return;
        }
        int mid = start + (end - start)/2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid+1, end);
        InPlaceMergeSort(nums, start, end);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};