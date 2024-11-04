//Using Map
class Solution {
public:
    void permutationFinder(vector<int>& nums, vector<vector<int>>& Permutations, int start){
        if(start >= nums.size()){
            Permutations.push_back(nums); 
            return;
        }
        unordered_map<int, bool>visited;
        for(int i = start; i < nums.size(); i++){
            if(visited.find(nums[i]) != visited.end()){
                continue;
            }
            visited[nums[i]] = true;
            swap(nums[start], nums[i]);
            permutationFinder(nums, Permutations, start + 1);
            swap(nums[start], nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>Permutations;
        int i = 0;
        permutationFinder(nums, Permutations, 0);
        return Permutations;
    }
};

//Using Set
class Solution {
public:
    void permutationFinder(vector<int>& nums, set<vector<int>>& outerSet, int start){
        if(start >= nums.size()){
            outerSet.insert(nums); 
            return;
        }
        for(int i = start; i < nums.size(); i++){
            swap(nums[start], nums[i]);
            permutationFinder(nums, outerSet, start + 1);
            swap(nums[start], nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>Permutations;
        int i = 0;
        set<vector<int>> outerSet;
        permutationFinder(nums, outerSet, 0);
        for(auto innerSet : outerSet){
            Permutations.push_back(innerSet);
        }
        return Permutations;
    }
};