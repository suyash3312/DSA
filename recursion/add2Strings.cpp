class Solution {
public:
    // Recursive function to reverse the string
    void reverseString(string& s, int start, int end) {
        if (start >= end) {
            return;
        }
        swap(s[start], s[end]);
        reverseString(s, start + 1, end - 1);  // Recursive call
    }

    // Recursive function to add two strings digit by digit
    void addRecursively(string& ans, const string& num1, const string& num2, int i, int carry) {
        // Base case: If we've processed all digits
        if (i >= num1.size() && i >= num2.size()) {
            if (carry != 0) {
                ans += (carry + '0');  // Add the carry if it's non-zero
            }
            return;
        }

        // Get current digit from num1 or 0 if i exceeds its size
        int digit1 = (i < num1.size()) ? (num1[i] - '0') : 0;
        // Get current digit from num2 or 0 if i exceeds its size
        int digit2 = (i < num2.size()) ? (num2[i] - '0') : 0;

        // Add the two digits and the carry
        int addedNumber = digit1 + digit2 + carry;
        int digit = addedNumber % 10;
        carry = addedNumber / 10;

        // Append current digit to ans
        ans += (digit + '0');

        // Recursively call for the next digit
        addRecursively(ans, num1, num2, i + 1, carry);
    }

    // Main function to add strings
    string addStrings(string num1, string num2) {
        // Reverse both strings before performing digit-wise addition
        reverseString(num1, 0, num1.size() - 1);
        reverseString(num2, 0, num2.size() - 1);

        string ans = "";
        // Start recursive addition from the 0th index of both reversed strings
        addRecursively(ans, num1, num2, 0, 0);

        // Reverse the result to get the final answer
        reverseString(ans, 0, ans.size() - 1);
        return ans;
    }
};
// iterative approach
class Solution {
public:
    void reverseString(string& s) {
        int start = 0;
        int end = s.size() - 1;
        while (start <= end) {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
    string addStrings(string num1, string num2) {
        int i = 0;
        reverseString(num1);
        reverseString(num2);
        string ans="";
        int addedNumber = 0, carry = 0, digit = 0;
        while (i < num1.size() && i < num2.size()) {
            addedNumber = (num1[i] - 48) + (num2[i] - 48);
            if(carry != 0){
                addedNumber += carry;
            }
            digit = addedNumber % 10;
            carry = addedNumber / 10;
            ans += (digit + '0');
            i++;
        }
        while(i < num1.size()){
            addedNumber = (num1[i] - 48);
            if(carry!=0){
                addedNumber += carry;
            }
            digit = addedNumber % 10;
            carry = addedNumber / 10;
            ans += (digit + '0');
            i++;
        }
        while(i < num2.size()){
            addedNumber = (num2[i] - 48);
            if(carry!=0){
                addedNumber += carry;
            }
            digit = addedNumber % 10;
            carry = addedNumber / 10;
            ans += (digit + '0');
            i++;
        }
        if(carry != 0){
            ans += carry + '0';
        }
        reverseString(ans);
        return ans;
    }
};