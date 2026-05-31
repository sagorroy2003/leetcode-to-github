class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        // 1. Guard against empty arrays to prevent crashes
        if (arr.empty()) return arr;

        // 2. The rightmost element is always replaced by -1
        int max_so_far = -1;

        // 3. Start from the VERY end, not the second-to-last
        for (int i = arr.size() - 1; i >= 0; --i) {
            int current_val = arr[i]; // Remember the current house
            
            arr[i] = max_so_far;      // Replace it with the biggest house to the right
            
            // Update our max tracker for the next step to the left
            max_so_far = std::max(max_so_far, current_val); 
        }

        return arr;
    }
};