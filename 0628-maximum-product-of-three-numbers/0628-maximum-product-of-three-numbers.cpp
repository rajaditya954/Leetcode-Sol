class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int first = INT_MIN, second = INT_MIN, third = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;

        for (int x : nums) {

            // Three largest numbers
            if (x >= first) {
                third = second;
                second = first;
                first = x;
            }
            else if (x >= second) {
                third = second;
                second = x;
            }
            else if (x > third) {
                third = x;
            }

            // Two smallest numbers
            if (x <= min1) {
                min2 = min1;
                min1 = x;
            }
            else if (x < min2) {
                min2 = x;
            }
        }

        return max(first * second * third,
                   first * min1 * min2);
    }
};