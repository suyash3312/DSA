class Solution{
    public:
    string decodeString(string s){
        stack<int> numStack;
        stack<string> strStack;
        string currentStr="";
        int num=0;
        for(auto c:s){
            if(isdigit(c)){
                num=num*10 + (c-'0');
            }
            else if(c == '['){
                numStack.push(num);
                strStack.push(currentStr);

                num=0;
                currentStr="";
            }
            else if(c == ']'){
                int repeatTimes=numStack.top();
                numStack.pop();
                string temp= strStack.top();
                strStack.pop();

                for(int i=0; i<repeatTimes; i++){
                    temp=temp+currentStr;
                }
                currentStr = temp;
            }else{
                currentStr+=c;
            }
        }
        return currentStr;
    }
};