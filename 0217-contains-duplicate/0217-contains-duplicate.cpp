class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> sett(nums.begin(), nums.end());  // O(n) - space complexity

        if (nums.size() == sett.size()) // O(n) time complexity
            return false;

        return true;
    }
};