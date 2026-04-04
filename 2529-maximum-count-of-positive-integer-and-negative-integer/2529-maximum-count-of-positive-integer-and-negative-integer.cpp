class Solution {
public:
    int maximumCount(vector<int>& nums) {

        // O(n) time

        // int pos = 0, neg = 0 ;
        // for(int i=0; i<nums.size(); i++){
        //     if (nums[i] > 0)pos++;
        //     if(nums[i] < 0)neg++;
        // }

        // return max(pos,neg);


        // O(log n)

        int n = nums.size();

        int pos = n;
        int neg = -1;

        int low = 0 , high = n - 1; 

        while(low <= high ){
            // finding the first negative
            int mid = (low + high ) / 2;
            if(nums[mid] < 0){
                neg = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1; 
            }
        }

        low = 0 , high = n - 1; 

        // finding the first positive
        while (low <= high ){
            int mid = (low + high )/2;
            if(nums[mid] > 0){
                pos = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }



        return max(neg+1, (n-pos));


    }
};