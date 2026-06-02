class Solution {
public:
    int func(vector<int>& arr, int low, int high, int target) {
        if (low > high)
            return -1; // base case

        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            return func(arr, low, mid - 1, target); // search left side
        else
            return func(arr, mid + 1, high, target); // search right side
    }

    int search(vector<int>& nums, int target) {
        return func(nums, 0, nums.size() - 1, target);
    }
};