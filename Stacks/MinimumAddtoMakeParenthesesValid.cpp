class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(auto ch:s){
            if(ch == '('){
                st.push(ch);
            }
            else{
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }else{
                    st.push(ch);
                }
            }
        }
        int C=0;
        while(!st.empty()){
            C++;
            st.pop();
        }
        return C;
    }
};