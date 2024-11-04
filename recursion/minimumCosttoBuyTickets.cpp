#include <vector>
#include <algorithm>

class Solution {
public:
    int minCost(int i, const std::vector<int>& days, const std::vector<int>& costs) {
        // Base case: if we've gone through all the days
        if (i >= days.size()) {
            return 0;
        }
        
        // Option 1: Buy a 1-day pass
        int cost1 = costs[0] + minCost(i + 1, days, costs);
        
        // Option 2: Buy a 7-day pass
        int j = i;
        while (j < days.size() && days[j] < days[i] + 7) {
            j++;
        }
        int cost2 = costs[1] + minCost(j, days, costs);
        
        // Option 3: Buy a 30-day pass
        j = i;
        while (j < days.size() && days[j] < days[i] + 30) {
            j++;
        }
        int cost3 = costs[2] + minCost(j, days, costs);
        
        // Return the minimum of the three options
        return std::min({cost1, cost2, cost3});
    }
    
    int mincostTickets(std::vector<int>& days, std::vector<int>& costs) {
        return minCost(0, days, costs);
    }
};