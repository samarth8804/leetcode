class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int> prefixSum;
        int currSum = 0;
        int n = nums.size();
        prefixSum[0] = 1;
        int count = 0;

        for(auto num : nums) {
            currSum = currSum + num;

            unordered_map<int,int>::iterator it = prefixSum.find(currSum - k);
            if(it != prefixSum.end()) {
                count = count + it->second;
            }

            prefixSum[currSum]++;
        }

        return count;
    }
};