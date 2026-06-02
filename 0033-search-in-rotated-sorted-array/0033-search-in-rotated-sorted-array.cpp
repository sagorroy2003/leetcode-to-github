class Solution {
public:

    int binary_search(vector<pair<int,int>> &vp, int target) {
        int n = vp.size();
        int low = 0,high = n -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(vp[mid].first == target) {
                return vp[mid].second;
            }
            else if(vp[mid].first > target) {
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return -1;
    }

    int search(vector<int>& arr, int target) {
        vector<pair<int,int>> vp;

        for(int i=0; i<arr.size() ; i++){
            vp.push_back({arr[i],i});
        }

        sort(vp.begin(),vp.end());

        return binary_search(vp,target);

    }
};