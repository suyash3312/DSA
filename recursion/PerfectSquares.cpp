class Solution {
public:
    int numSquares(int n) {
        return helper(n);
    }
    
    int helper(int n) {
        if (n == 0) return 0;  // Base case: 0 squares to sum up to 0
        
        int minSquares = n;  // The maximum we need is `n` (1^2 + 1^2 + ... n times)
        
        for (int i = 1; i * i <= n; i++) {
            minSquares = min(minSquares, 1 + helper(n - i * i)); // Recursively subtract squares
        }
        
        return minSquares ;
    }
};