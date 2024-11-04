class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        for(int i = 0; i < piles.size(); i++){
            pq.push(piles[i]);
        }
        while(k != 0){
            int totalStones = pq.top();
            pq.pop();
            int updatedStones = totalStones - floor(totalStones / 2);
            pq.push(updatedStones);
            k--;
        }
        int sum = 0;
        while(!pq.empty()){
            int stones = pq.top();
            pq.pop();
            sum += stones;
        }
        return sum;
    }
};