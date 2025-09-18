class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int mini = INT_MAX;
        int n = nums.size();
        int left = 0,right = n-1;

        while(left<=right) {
            int mid = left + ((right-left)/2);

            if(nums[left]<=nums[mid]) {
                mini = min(mini,nums[left]);
                left = mid + 1;
            }
            else {
                mini = min(mini,nums[mid]);
                right = mid - 1;
            }
        }

        return mini;
    }
};