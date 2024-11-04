//Iterative approach
class Solution {
public:
    string removeOccurrences(string s, string part) {
        int pos = s.find(part);
        while(pos != string::npos){
            s.erase(pos, part.length());
            pos = s.find(part);
        }
        return s;
    }
};
//Recursive approach
class Solution {
public:
    void removeSubstring(string& s, string& part) {
        int pos = s.find(part);
        if(pos != string::npos){
            s.erase(pos, part.length());
            removeSubstring(s, part);
        }
        else{
            return;
        }
    }
    string removeOccurrences(string s, string part) {
        removeSubstring(s, part);
        return s;
    }
};