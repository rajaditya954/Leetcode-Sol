class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        set<int> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                for (int k = 0; k < n; k++) {
                    if (i == k || j == k) continue;

                    if (digits[i] == 0) continue;   // no leading zero
                    if (digits[k] % 2 != 0) continue; // last digit must be even

                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    ans.insert(num);
                }
            }
        }

        return vector<int>(ans.begin(), ans.end());
    }
};