class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> lookup;
        
        for(int i = 0; i<nums.size(); i++){
            int subtract = target - nums[i];

            if(lookup.find(subtract) != lookup.end()){
                // tar mane lookup er vitor asa 

                return {lookup[subtract],i};
            }

            // jodi na thake 
            lookup[nums[i]] = i; 
        }

        return {};
    }
};