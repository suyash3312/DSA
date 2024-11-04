int countRev (string s)
{
    // your code here
    if(s.size() & 1){
        return -1;
    }
    stack<char>st;
    int reversals=0;
    for(int i=0; i<s.size(); i++){
        char ch=s[i];
        if(ch=='{'){
            st.push(ch);
        }else{
            if(!st.empty() && st.top() == '{'){
                st.pop();
            }else{
                st.push(ch);
            }
        }
    }
    while(!st.empty()){
        char a=st.top();
        st.pop();
        char b=st.top();
        st.pop();
        if(a==b){
            reversals+=1;
        }else{
            reversals+=2;
        }
    }
    return reversals;
}