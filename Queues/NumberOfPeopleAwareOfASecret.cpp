class Solution {
public:
    // This function calculates the number of people aware of a secret after 'n' days,
    // with a certain delay before they can share the secret and a forget time.
    int peopleAwareOfSecret(int n, int delay, int forget) {
        // Calculating array size to be sufficiently large
        int arraySize = (n << 1) + 10;
        int MOD = 1e9 + 7;
        vector<int> incrementArray(arraySize, 0); // Array to handle increments of people knowing the secret
        vector<int> peopleCountArray(arraySize, 0); // People knowing the secret by day i
      
        // Initially, one person knows the secret
        peopleCountArray[1] = 1;
      
        // Process each day
        for (int day = 1; day <= n; ++day) {
            // Skip days when no new people are aware of the secret
            if (!peopleCountArray[day]) continue;
          
            // Schedule an increase in the count for the current day
            incrementArray[day] = (incrementArray[day] + peopleCountArray[day]) % MOD;
            // Schedule a decrease (forgetting) in the count after the forgetting period
            incrementArray[day + forget] = (incrementArray[day + forget] - peopleCountArray[day] + MOD) % MOD;
          
            // Spread the secret to new people after the delay, every day until they forget
            int shareDay = day + delay;
            while (shareDay < day + forget) {
                peopleCountArray[shareDay] = (peopleCountArray[shareDay] + peopleCountArray[day]) % MOD;
                ++shareDay;
            }
        }
      
        // Calculate the final answer, the total number of people aware of the secret after 'n' days
        int totalAwarePeople = 0;
        for (int day = 1; day <= n; ++day) {
            totalAwarePeople = (totalAwarePeople + incrementArray[day]) % MOD;
        }
        return totalAwarePeople;
    }
};