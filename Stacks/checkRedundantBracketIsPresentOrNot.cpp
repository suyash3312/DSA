class Solution {
  public:
    int checkRedundancy(string s) {
        // code here
        stack<char>st;
        int operatorCount = 0;
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            if(ch=='(' || ch=='+' || ch=='-'|| ch=='*' || ch=='/'){
                st.push(ch);
            }
            else if(ch == ')'){
                int operatorCount = 0;
                while(!st.empty() && st.top() != '('){
                    char temp = st.top();
                    if(temp == '+' || temp =='-'|| temp =='*' || temp =='/'){
                        operatorCount++;
                    }
                    st.pop();
                }
                st.pop();
                if(operatorCount == 0){
                    return 1;
                }
            }
        }
        return 0;
    }
};