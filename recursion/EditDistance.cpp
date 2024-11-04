class Solution {
public:
    int solve(string& word1, string& word2, int i, int j){
        if(i >= word1.length()){
            return word2.length() - j;
        }
        if(j >= word2.length()){
            return word1.length() - i;
        }
        int ans = 0;
        if(word1[i] == word2[j]){
            return solve(word1, word2, i+1, j+1);
        }
        else{
            int option1 = 1 + solve(word1, word2, i, j+1);
            int option2 = 1 + solve(word1, word2, i+1, j);
            int option3 = 1 + solve(word1, word2, i+1, j+1);
            ans = min(option1, min(option2, option3));
        }
        return ans;
    }
    int minDistance(string word1, string word2) {
        return solve(word1, word2, 0, 0);
    }
};