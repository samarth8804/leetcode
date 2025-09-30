class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        
        int n = nums.size();

        int left = INT_MIN;
        int right = 0;

        int ans;

        for(auto x : nums) {
            left = max(left,x);
            right = right + x;
        }

        while(left<=right) {
            int mid = left + ((right-left)/2);

            int sub_array = 0;
            int sum = 0;

            for(int i=0;i<n;i++) {
                sum = sum + nums[i];
                if(sum>mid) {
                    sub_array++;
                    sum = nums[i];
                }
            }

            sub_array++;

            if(sub_array>k) {
                left = mid+1;
            }
            else {
                ans = mid;
                right = mid-1;
            }
        }

        return ans;
    }
};