class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(auto ast:asteroids){
            bool destroyed=false;
            
            while(!st.empty() && st.top() > 0 && ast < 0){
                if(st.top() < abs(ast)){
                    st.pop();
                }
                else if(st.top() > abs(ast)){
                    destroyed=true;
                    break;
                }
                else{
                    st.pop();
                    destroyed=true;
                    break;
                }
            }
            if(!destroyed){
                st.push(ast);
            }
        }
        vector<int> finalAns(st.size());
        for(int i=finalAns.size()-1; i>=0; i--){
            finalAns[i]=st.top();
            st.pop();
        }
        return finalAns;
    }
};