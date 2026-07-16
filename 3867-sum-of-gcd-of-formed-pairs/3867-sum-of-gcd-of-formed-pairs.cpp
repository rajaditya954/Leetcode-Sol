class Solution {
public:
    long long gcdSum(vector<int>& nums) {

        int n = nums.size();

        vector<int> mx;
        vector<int> prefixGcd;

        int mxi = INT_MIN;

        for (int i = 0; i < n; i++) {
            mxi = max(mxi, nums[i]);
            mx.push_back(mxi);
        }

        for (int i = 0; i < n; i++) {
            prefixGcd.push_back(gcd(nums[i], mx[i]));
        }

        long long sum = 0;

        multiset<int> st(prefixGcd.begin(), prefixGcd.end());

        while (st.size() >= 2) {
            int mini = *st.begin();
            int maxi = *prev(st.end());

            sum += gcd(mini, maxi);

            st.erase(st.find(mini));
            st.erase(st.find(maxi));
        }

        return sum;
    }
};