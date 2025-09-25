class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int n = nums.size();

        if(n == 1) {
            return 0;
        }
        else if(nums[0]>nums[1]) {
            return 0;
        }
        else if(nums[n-1]>nums[n-2]) {
            return n-1;
        }
        
        int left = 1,right = n-2;

        while(left<right) {
            int mid = left + ((right-left)/2);

            if(nums[mid]>nums[mid+1]) {
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        

        return left;
    }
};