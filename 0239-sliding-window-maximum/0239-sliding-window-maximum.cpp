class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        multiset<int> ms;

        // Insert first window
        for (int i = 0; i < k; i++) {
            ms.insert(nums[i]);
        }

        // Maximum of first window
        ans.push_back(*prev(ms.end()));

        int left = 0;
        int right = k;

        while (right < n) {

            // Remove outgoing element
            ms.erase(ms.find(nums[left]));

            // Insert incoming element
            ms.insert(nums[right]);

            // Maximum of current window
            ans.push_back(*prev(ms.end()));

            left++;
            right++;
        }

        return ans;
    }
};