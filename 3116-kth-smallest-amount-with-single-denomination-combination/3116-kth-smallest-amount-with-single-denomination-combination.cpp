class Solution {
public:

    long long findKthSmallest(vector<int>& coins, int k) {

        long long low = 1;
        long long high = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        int n = coins.size();

        // Function to count how many valid numbers <= x
        auto count = [&](long long x) {

            long long ans = 0;

            // Try every subset of coins
            for (int mask = 1; mask < (1 << n); mask++) {

                long long lcm = 1;
                int bits = 0;
                bool valid = true;

                for (int i = 0; i < n; i++) {

                    if (mask & (1 << i)) {

                        bits++;

                        long long g = gcd(lcm, (long long)coins[i]);

                        // Avoid overflow
                        __int128 newLcm =
                            (__int128)(lcm / g) * coins[i];

                        if (newLcm > x) {
                            valid = false;
                            break;
                        }

                        lcm = (long long)newLcm;
                    }
                }

                if (!valid)
                    continue;

                long long current = x / lcm;

                // Odd number of elements -> add
                // Even number -> subtract
                if (bits % 2 == 1)
                    ans += current;
                else
                    ans -= current;
            }

            return ans;
        };


        // Binary search
        while (low < high) {

            long long mid = low + (high - low) / 2;

            if (count(mid) >= k) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};