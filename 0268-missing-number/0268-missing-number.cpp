class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sz=nums.size();
        int sum1=0;
        int sum2=0;

        for(int i=1; i<=sz; i++){
            sum1+=i;
        }
        for(int i=0; i<sz; i++){
            sum2+=nums[i];
        }

        return sum1-sum2;
    }
};