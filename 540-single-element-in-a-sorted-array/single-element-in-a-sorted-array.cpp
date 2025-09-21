class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        int left = 0,right = n-1;

        while(left<=right) {
            int mid = left + ((right-left)/2);

            if(left == right) {
                return nums[mid];
            }
            
            if(mid%2 == 0) {
                if(mid+1 == n) {
                    return nums[mid];
                }
                else if(nums[mid] == nums[mid+1]) {
                    left = mid + 2;
                }
                else {
                    right = mid;
                }
            }
            else {
                if(nums[mid] == nums[mid-1]) {
                    left = mid+1;
                }
                else {
                    right = mid;
                }
            }
        }

        return 0;
    }
};