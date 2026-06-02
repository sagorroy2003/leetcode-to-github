class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        k%=arr.size();
        if(k == 0) return ;

        reverse(arr.begin(), arr.end());

        reverse(arr.begin(), arr.begin() + k);

        reverse(arr.begin() + k , arr.end());
    }
};