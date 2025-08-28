class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> subsets;

        int n = nums.size();
        int total = 1<<n;

        int mask = 0;

        for(int mask = 0;mask<total;mask++) {
            vector<int> subset;
            for(int i=0;i<n;i++) {
                if(mask & (1<<i)) {
                    subset.push_back(nums[i]);
                }
            }
            subsets.push_back(subset);
        }

        return subsets;
    }
};