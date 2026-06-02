class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> lookup; 

        int x = 0;

        for(int i = 0; i < numbers.size(); i++){
            x = target - numbers[i];
            auto it = lookup.find(x);
            if(it != lookup.end()){
                return {it -> second+1 , i + 1};
            }

            lookup[numbers[i]] = i;
        }

        return {};
    }
};