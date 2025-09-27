class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int n = nums.size();
        int left = 1,right = INT_MIN;
        int ans;

        for(auto x : nums) {
            right = max(right,x);
        }

        while(left<=right) {
            int mid = left + ((right-left)/2);

            int sum = 0;

            for(int i=0;i<n && sum<=threshold;i++) {
                sum = sum + ((nums[i]+mid-1)/mid);
            }

            if(sum<=threshold) {
                ans = mid;
                right = mid-1;
            }
            else {
                left = mid+1;
            }
        }

        return ans;
    }
};