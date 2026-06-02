class Solution {
public:
    // Function to find the FIRST (leftmost) occurrence recursively
    int first_o(vector<int>& arr, int low, int high, int target) {
        // Base case: if range is invalid
        if (low > high)
            return -1;

        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            // Try to find an earlier occurrence on the left
            int left = first_o(arr, low, mid - 1, target);
            if (left == -1)
                return mid; // no earlier one found
            else
                return left; // earlier one exists
        } else if (arr[mid] > target) {
            // Search in the left half
            return first_o(arr, low, mid - 1, target);
        } else {
            // Search in the right half
            return first_o(arr, mid + 1, high, target);
        }
    }

    // Function to find the LAST (rightmost) occurrence recursively
    int last_o(vector<int>& arr, int low, int high, int target) {
        // Base case: if range is invalid
        if (low > high)
            return -1;

        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            // Try to find a later occurrence on the right
            int right = last_o(arr, mid + 1, high, target);
            if (right == -1)
                return mid; // no later one found
            else
                return right; // later one exists
        } else if (arr[mid] > target) {
            // Search in the left half
            return last_o(arr, low, mid - 1, target);
        } else {
            // Search in the right half
            return last_o(arr, mid + 1, high, target);
        }
    }

    // Main function to return first and last occurrence as a vector
    vector<int> searchRange(vector<int>& arr, int target) {
        vector<int> range(2, -1); // default [-1, -1]

        if (arr.empty())
            return range; // handle empty array case

        int low = 0, high = arr.size() - 1;
        range[0] = first_o(arr, low, high, target);
        range[1] = last_o(arr, low, high, target);

        return range;
    }
};