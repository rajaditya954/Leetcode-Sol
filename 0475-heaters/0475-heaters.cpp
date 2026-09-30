class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {

        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int j = 0;
        int ans = 0;

        for (int i = 0; i < houses.size(); i++) {

            while (j + 1 < heaters.size() &&
                   abs(heaters[j + 1] - houses[i]) <=
                   abs(heaters[j] - houses[i])) {
                j++;
            }

            ans = max(ans, abs(heaters[j] - houses[i]));
        }

        return ans;
    }
};