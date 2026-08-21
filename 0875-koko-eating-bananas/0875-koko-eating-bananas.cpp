class Solution {
public:
    long long calculate(vector<int>& piles, int mid) {
        long long ans = 0;
        for (int i = 0; i < piles.size(); i++) {
            ans += (piles[i] + mid - 1) / mid; // take the ceil
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx = *max_element(piles.begin(), piles.end());
        int low = 1, high = mx;

        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (calculate(piles, mid) <= h) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }

        return ans;
    }
};