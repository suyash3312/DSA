class Solution {
public:
    bool canDistributeHelper(vector<int>& count, vector<int>& quantity, int ithCustomer){
        if(ithCustomer >= quantity.size()){
            return true;
        }
        for(int i=0; i < count.size(); i++){
            if(count[i] >= quantity[ithCustomer]){
                count[i] -= quantity[ithCustomer];
                if(canDistributeHelper(count, quantity, ithCustomer + 1)){
                    return true;
                }
                count[i] += quantity[ithCustomer];
            }
        }
        return false;
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int>map;
        for(auto num : nums){
            map[num]++;
        }
        vector<int>count;
        for(auto it : map){
            count.push_back(it.second);
        }
        sort(quantity.rbegin(), quantity.rend());
        return canDistributeHelper(count, quantity, 0);
    }
};