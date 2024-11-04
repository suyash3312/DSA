class Solution {
public:
    void permutationFinder(vector<int>& nums, vector<vector<int>>& Permutations, int start){
        if(start >= nums.size()){
            Permutations.push_back(nums);
            return;
        }
        for(int i = start; i < nums.size(); i++){
            swap(nums[start], nums[i]);
            permutationFinder(nums, Permutations, start + 1);
            swap(nums[start], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>Permutations;
        int i = 0;
        permutationFinder(nums, Permutations, 0);
        return Permutations;
    }
};