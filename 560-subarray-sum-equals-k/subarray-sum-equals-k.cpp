class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        map<int,int> prefixSum;
        int currSum = 0;
        int n = nums.size();
        prefixSum[0] = 1;
        int count = 0;

        for(int i=0;i<n;i++) {
            currSum = currSum + nums[i];

            if(prefixSum.count(currSum - k)) {
                count = count + prefixSum[currSum-k];
            }

            prefixSum[currSum]++;
        }

        return count;
    }
};