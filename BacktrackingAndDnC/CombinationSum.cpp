class Solution {
public:
    void CombinationSumFinder(vector<int>& candidates, int target, int index, vector<int>& v, vector<vector<int>>& Combinations){
        if(target == 0){
            Combinations.push_back(v);
            return;
        }
        if(target < 0){
            return;
        }
        for(int i = index; i < candidates.size(); i++){
            v.push_back(candidates[i]);
            CombinationSumFinder(candidates, target - candidates[i], i, v, Combinations);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>v;
        vector<vector<int>> Combinations;
        CombinationSumFinder(candidates, target, 0, v, Combinations);
        return Combinations;
    }
};