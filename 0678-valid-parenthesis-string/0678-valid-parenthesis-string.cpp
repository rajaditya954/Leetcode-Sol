class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;   // minimum possible open brackets
        int high = 0;  // maximum possible open brackets

        for (char ch : s) {
            if (ch == '(') {
                low++;
                high++;
            }
            else if (ch == ')') {
                low--;
                high--;
            }
            else { // '*'
                low--;   // '*' can be ')'
                high++;  // '*' can be '('
            }

            // Too many closing brackets
            if (high < 0)
                return false;

            // We can't have fewer than 0 open brackets
            low = max(low, 0);
        }

        return low == 0;
    }
};
