class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        int low = 0, high = n - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // Ensure mid is even, because pairs start at even indices
            if (mid % 2 == 1) mid--;

            // Compare current pair
            if (arr[mid] == arr[mid + 1]) {
                // Left half is okay; single is on the right
                low = mid + 2;
            } else {
                // Single is on the left (including mid)
                high = mid;
            }
        }

        return arr[low];
    }
};
