class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int>  ans(deck.size());
        queue<int> indexQueue;

        for(int i=0; i<deck.size(); i++){
            indexQueue.push(i);
        }

        sort(deck.begin(), deck.end());

        for(int i=0; i<deck.size(); i++){
            ans[indexQueue.front()] = deck[i];
            indexQueue.pop();

            if(!indexQueue.empty()){
                indexQueue.push(indexQueue.front());
                indexQueue.pop();
            }
        }
        return ans;
    }
};