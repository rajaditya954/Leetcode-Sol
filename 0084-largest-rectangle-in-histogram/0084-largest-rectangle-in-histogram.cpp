class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // optimal approach O(n)
        int ans = 0;
        stack<int> s;
        vector<int> left(heights.size(), 0);
        vector<int> right(heights.size(), 0);

        // right smaller number for every bar
        for (int i = heights.size() - 1; i >= 0; i--) {
            while (s.size() > 0 && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            if (s.empty()) {
                right[i] = heights.size();
            } else {
                right[i] = s.top();
            }
            s.push(i);
        }
        
        while(!s.empty()){
            s.pop();
        }

        // left smaller number for every bar
        for (int i = 0; i < heights.size(); i++) {
            while (s.size() > 0 && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            if (s.empty()) {
                left[i] = -1;
            } else {
                left[i] = s.top();
            }
            s.push(i);
        }
        // max area
        for (int i = 0; i < heights.size(); i++) {
            int currArea = heights[i] * (right[i] - left[i] - 1);
            ans = max(ans, currArea);
        }
        return ans;
    }
};