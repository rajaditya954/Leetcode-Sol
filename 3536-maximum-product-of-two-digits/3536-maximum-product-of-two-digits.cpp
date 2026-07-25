class Solution {
public:
    int maxProduct(int n) {
        int fmx = INT_MIN;
        int smx = INT_MIN;

        for (char digit : to_string(n)) {
            int d = digit - '0';

            if (d > fmx) {
                smx = fmx;
                fmx = d;
            }
            else if (d > smx) {
                smx = d;
            }
        }

        return(long) fmx * smx;
    }
};