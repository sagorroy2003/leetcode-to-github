#include <vector>
#include <algorithm>

class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        int n = cost.size();
        
        // 1. Create a DP array of size n + 1. 
        // dp[i] will store the absolute minimum cost to reach step 'i'.
        std::vector<int> dp(n + 1, 0);
        
        // 2. Base Cases: We can start at step 0 or step 1 for free.
        // (Since we initialized the vector with 0s, these are technically already set, 
        // but it is good practice to explicitly state them for readability).
        dp[0] = 0;
        dp[1] = 0;
        
        // 3. Build the array from the bottom up
        for (int i = 2; i <= n; i++) {
            // The minimum cost to reach THIS step is the minimum of:
            // - The cost to reach 1 step below + the cost of that step
            // - The cost to reach 2 steps below + the cost of that step
            dp[i] = std::min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        
        // 4. Return the calculated cost to reach the "top floor" (index n)
        return dp[n];
    }
};