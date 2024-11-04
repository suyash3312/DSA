class Solution {
public:
    void reverseString(vector<char>& s) {
        int start= 0;
        int end= s.size()-1;
        while(start <= end){
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
};
//Recursive Approach
class Solution {
public:
    void reverse(vector<char>& s, int start, int end){
        if(start >= end){
            return;
        }
        else{
            swap(s[start], s[end]);
            reverse(s, start+1, end-1);
        }
    }

    
    void reverseString(vector<char>& s) {
        int start= 0;
        int end= s.size()-1;
        reverse(s, start, end);
    }
};