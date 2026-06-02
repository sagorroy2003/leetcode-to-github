class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1;

        sort(arr.begin(), arr.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) {
                return true;
            } else if (arr[mid] > target) {
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return false;
    }
};