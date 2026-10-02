class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int i = 0, j = 0;
        vector<int> res;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] <= nums2[j]) {
                res.push_back(nums1[i]);
                i++;
            } else {
                res.push_back(nums2[j]);
                j++;
            }
        }

        while (i < nums1.size()) {
            res.push_back(nums1[i]);
            i++;
        }

        while (j < nums2.size()) {
            res.push_back(nums2[j]);
            j++;
        } 

        double size = res.size();

        if ((int)size % 2 == 0) {
            double ans = (res[(int)size / 2 - 1] + res[(int)size / 2]) / 2.0;
            return ans;
        } else {
            double ans = res[(int)size / 2];
            return ans;
        }
    }
};