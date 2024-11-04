class Solution {
public:
    void countArrangementHelper(int& n, vector<int>v, int& ans, int currNum){
        if(currNum == n + 1){
            ++ans;
            return;
        }
        for(int i = 1; i <= n; i++){
            if(v[i] == 0 && (currNum % i == 0 || i % currNum == 0)){
                v[i] = currNum;
                countArrangementHelper(n, v, ans, currNum + 1);
                v[i] = 0;
            }
        }
    }
    int countArrangement(int n) {
        vector<int>v(n+1);
        int ans = 0;
        countArrangementHelper(n, v, ans, 1);
        return ans;
    }
};