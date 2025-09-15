class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0,right = n-1;
        int last = -1,first = -1;

        // For first Occurence 

        while(left<=right) {
            int mid = left + ((right-left)/2);
            if(nums[mid] == target) {
                first = mid;
                right = mid-1;
            }
            else if(nums[mid]>target) {
                right = mid-1;
            }
            else {
                left = left+1;
            }
        }

        left = 0,right = n-1;

        // For last Occurence 

        while(left<=right) {
            int mid = left + ((right-left)/2);
            if(nums[mid] == target) {
                last = mid;
                left = mid+1;
            }
            else if(nums[mid]>target) {
                right = mid-1;
            }
            else {
                left = left+1;
            }
        }

        return {first,last};
    }
};