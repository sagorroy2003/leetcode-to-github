class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1; // pointing to the nums1 last element
        int p2 = n - 1; // pointing to the nums2 last element
        int p = n + m - 1;

        while (p1 >=0 && p2 >= 0) {
            if (nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p--;
                p1--;
            } else {
                nums1[p] = nums2[p2];
                p--;
                p2--;
            }
        }

        while(p2 >= 0){
            nums1[p] = nums2[p2];
            p--;
            p2--;
        }

    }
};