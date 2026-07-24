class Solution {
public:
    void f(int st, vector<int>& comb, vector<vector<int>>& ans, int n, int k) {
        if (comb.size() == k) {
            ans.push_back(comb);
            return;
        }

        for (int i = st; i <= n; i++) {
            comb.push_back(i);
            f(i + 1, comb, ans, n, k);
            comb.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>> ans;
        vector<int> comb;

        f(1, comb, ans, n, k);
        return ans;
    }
};