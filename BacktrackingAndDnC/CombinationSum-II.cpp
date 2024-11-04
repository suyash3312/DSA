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
            if(i > index && (candidates[i] == candidates[i - 1])){
                continue;
            }
            v.push_back(candidates[i]);
            CombinationSumFinder(candidates, target - candidates[i], i + 1, v, Combinations);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int>v;
        vector<vector<int>> Combinations;
        CombinationSumFinder(candidates, target, 0, v, Combinations);
        return Combinations;
    }
};