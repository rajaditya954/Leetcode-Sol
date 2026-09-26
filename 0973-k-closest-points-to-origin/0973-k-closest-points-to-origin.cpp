class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        vector<pair<int, vector<int>>> mv;

        for (auto it : points) {
            int x = it[0];
            int y = it[1];

            int dist = (x * x) + (y * y);

            mv.push_back({dist, it});
        }

        sort(mv.begin(), mv.end());

        vector<vector<int>> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(mv[i].second);
        }

        return ans;
    }
};