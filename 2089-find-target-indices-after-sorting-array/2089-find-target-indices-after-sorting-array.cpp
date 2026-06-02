class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());

        int f = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        int l = upper_bound(nums.begin(), nums.end(),target) - nums.begin();

        vector<int> ans(l  - f );

        iota(ans.begin(),ans.end(),f);

        return ans;
        
    }
};