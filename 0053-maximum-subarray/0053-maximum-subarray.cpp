class Solution {
private:

    // HELPER FUNCTION 1:
    // Finds the best subarray that MUST include elements from BOTH halves
    // (i.e., it crosses the middle point)
    //
    // Example: [-2, 1, -3, | 4, -1, 2, 1, -5, 4]
    //                      ^-- mid is here
    // We stretch LEFT from mid, and RIGHT from mid+1, then combine the best of both
    int bestCrossingSubarray(const vector<int>& nums, int left, int mid, int right) {

        // --- Left side: start at 'mid' and walk LEFT ---
        int bestLeftSum = INT_MIN;  // Worst possible starting value
        int runningSum  = 0;

        for (int i = mid; i >= left; --i) {
            runningSum += nums[i];
            bestLeftSum = max(bestLeftSum, runningSum); // Keep track of best so far
        }

        // --- Right side: start at 'mid+1' and walk RIGHT ---
        int bestRightSum = INT_MIN;
        runningSum = 0;

        for (int i = mid + 1; i <= right; ++i) {
            runningSum += nums[i];
            bestRightSum = max(bestRightSum, runningSum);
        }

        // Combine: the crossing subarray is left-best + right-best joined at mid
        return bestLeftSum + bestRightSum;
    }


    // HELPER FUNCTION 2 (the main engine):
    // Finds the best subarray inside nums[left ... right]
    //
    // KEY IDEA — the answer MUST be in one of three places:
    //   1. Entirely in the LEFT  half  --> solve smaller problem recursively
    //   2. Entirely in the RIGHT half  --> solve smaller problem recursively
    //   3. Crossing the MIDDLE point   --> use bestCrossingSubarray() above
    //
    // We try all three and return the biggest.
    int solve(const vector<int>& nums, int left, int right) {

        // BASE CASE: only one number → that number IS the subarray
        if (left == right) {
            return nums[left];
        }

        // Find the midpoint safely (avoids integer overflow vs (left+right)/2)
        int mid = left + (right - left) / 2;

        int leftAnswer    = solve(nums, left, mid);        // Best in left half
        int rightAnswer   = solve(nums, mid + 1, right);   // Best in right half
        int crossAnswer   = bestCrossingSubarray(nums, left, mid, right); // Best crossing

        // Winner of the three is our answer for this chunk
        return max({leftAnswer, rightAnswer, crossAnswer});
    }

public:
    // MAIN FUNCTION: called with the full array
    int maxSubArray(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1);
    }
};