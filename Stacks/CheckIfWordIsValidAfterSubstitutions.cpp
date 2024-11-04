class Solution{
    public:
    bool isValid(string& s){
        stack<char> st;
        for(auto c:s){
            st.push(c);

            if(st.size() >= 3){
                char c1 = st.top();
                st.pop();
                char c2 = st.top();
                st.pop();
                char c3 = st.top();
                st.pop();

                if(c1 == 'c' && c2 == 'b' && c3 == 'a'){
                    continue;
                }else{
                    st.push(c3);
                    st.push(c2);
                    st.push(c1);
                }
            }
        }
        return st.empty();
    }
}