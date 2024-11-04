// Input: s = hello
// Output: h
// Explanation: In the given string, the first character which is non-repeating is h, as it appears first and there is no other 'h' in the string.
// Input: s = zxvczbtxyzvy
// Output: c
// Explanation: In the given string, 'c' is the character which is non-repeating

class Solution {
  public:
    // Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string s) {
        // Your code here
        int freq[26]={0};
        queue<char>q;
        
        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            freq[ch - 'a']++;
            q.push(ch);
            
            while(!q.empty()){
                char frontCharacter = q.front();
                if(freq[frontCharacter - 'a'] > 1){
                    q.pop();
                }
                else{
                    break;
                }
            }
        }
        if(!q.empty()){
            return q.front();
        }
        else{
            return '$';
        }
    }
};