class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = INT_MAX;
        int mx = INT_MIN;
        vector <int> ans;
        unordered_set<int> st;

        for (int i = 0; i < nums.size(); i++) {
            mx = max(mx, nums[i]);
            mn = min(mn, nums[i]);
            st.insert(nums[i]);
        }

        for (int i = mn; i <= mx; i++) {
            if (st.find(i) == st.end()) {
                ans.push_back(i);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};