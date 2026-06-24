class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
// We initialize both to 0 because we can start at step 0 or step 1 with 0 initial cost.
        int one_step_back = 0;
        int two_step_back = 0;

        for (int i = 2; i <= cost.size(); i++) {
            int curr = std::min(one_step_back + cost[i - 1] , two_step_back + cost[i-2]);

            two_step_back = one_step_back;
            one_step_back = curr;
        }

        return one_step_back;
    }
};