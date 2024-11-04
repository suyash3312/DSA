class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        stack<int>st;
        int i=0;
        for(i=0; i<mat.size(); i++){
            st.push(i);
        }
        while(st.size()!=1){
            int A=st.top();
            st.pop();
            int B=st.top();
            st.pop();
            if(mat[A][B] == 1){
                st.push(B);
            }else{
                st.push(A);
            }
        }
        int mightBeCelebrity = st.top();
        st.pop();
        
        for(i=0; i < mat.size(); i++){
            if(i!=mightBeCelebrity){
            if((mat[mightBeCelebrity][i] != 0 || mat[i][mightBeCelebrity] != 1)){
                return -1;
            }
            }
        }
        return mightBeCelebrity;
    }
};