class Solution {
public:
    unordered_set<string> ans;

    void dfs(string &s, int idx, int leftRemove, int rightRemove, int balance,
             string cur) {

        if (idx == s.size()) {
            if (leftRemove == 0 && rightRemove == 0 && balance == 0) {
                ans.insert(cur);
            }
            return;
        }

        char c = s[idx];

        // Option 1: remove this parenthesis
        if (c == '(' && leftRemove > 0) {
            dfs(s, idx + 1, leftRemove - 1, rightRemove,
                balance, cur);
        }

        if (c == ')' && rightRemove > 0) {
            dfs(s, idx + 1, leftRemove, rightRemove - 1,
                balance, cur);
        }

        // Option 2: keep this character
        if (c != '(' && c != ')') {
            dfs(s, idx + 1, leftRemove, rightRemove,
                balance, cur + c);
        }
        else if (c == '(') {
            dfs(s, idx + 1, leftRemove, rightRemove,
                balance + 1, cur + c);
        }
        else if (balance > 0) {
            dfs(s, idx + 1, leftRemove, rightRemove,
                balance - 1, cur + c);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int leftRemove = 0;
        int rightRemove = 0;

        // Find the minimum number of removals needed.
        for (char c : s) {
            if (c == '(') {
                leftRemove++;
            } else if (c == ')') {
                if (leftRemove > 0)
                    leftRemove--;
                else
                    rightRemove++;
            }
        }

        dfs(s, 0, leftRemove, rightRemove, 0, "");

        return vector<string>(ans.begin(), ans.end());
    }
};
