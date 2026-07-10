class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int maxB = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxB = max(maxB, piles[i]);
        }

        long long lo = 1;
        long long high = maxB;
        long long ans = maxB;

        while (lo <= high) {
            long long cntH = 0;
            long long speed = lo + (high - lo) / 2;

            for (int i = 0; i < n; i++) {
                cntH += piles[i] / speed;

                if (piles[i] % speed != 0)
                    cntH++;
            }

            if (cntH <= h) {
                ans = speed;
                high = speed - 1;
            } else {
                lo = speed + 1;
            }
        }

        return (int)ans;
    }
};