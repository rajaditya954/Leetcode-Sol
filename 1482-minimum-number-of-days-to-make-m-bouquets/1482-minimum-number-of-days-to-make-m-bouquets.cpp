class Solution {
public:

    bool canMake(vector<int>& bloomDay, int day, int m, int k) {

        int flowers = 0;
        int bouquets = 0;

        for (int i = 0; i < bloomDay.size(); i++) {

            if (bloomDay[i] <= day) {
                flowers++;

                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            }
            else {
                flowers = 0;
            }
        }

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        long long totalFlowers = 1LL * m * k;

        if (bloomDay.size() < totalFlowers)
            return -1;

        int low = 1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (canMake(bloomDay, mid, m, k)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};