class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int currMax = nums[0],currMin = nums[0],ans = nums[0];
        int n = nums.size();

        for(int i=1;i<n;i++) {
            if(nums[i] == 0) {
                currMax = 0;
                currMin = 0;
            }
            else if(nums[i]<0) {
                swap(currMax,currMin);
            }
            currMax = max(currMax*nums[i],nums[i]);
            currMin = min(currMin*nums[i],nums[i]);
            ans = max(currMax,ans);
        }

        return ans; 
    }
};