// Not an optimal approach, solve it using iterative approach
class Solution{
    public:
    int i=0;
    int lastOccurenceOfChar=-1;
    int LastIndex(string s, char p){
        //complete the function here
        if(i == s.size()){
            return lastOccurenceOfChar;
        }
        if(s[i] == p){
            lastOccurenceOfChar = i;
        }
        i++;
        return LastIndex(s, p);
    }
};
