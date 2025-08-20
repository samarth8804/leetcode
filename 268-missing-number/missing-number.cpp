class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        int n_sum = (n*(n+1))/2;

        for(int i=0;i<n;i++) {
            sum += nums[i];
        }

        return n_sum - sum;
    }
};