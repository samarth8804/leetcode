class Solution {
private:
    int lessThanEqualKDistinct(vector<int>& nums,int k) {

        int n = nums.size();
        int left = 0,right = 0;
        int count = 0;
        unordered_map<int,int> mp;

        while(right < n) {

            mp[nums[right]]++;

            while(mp.size() > k) {

                mp[nums[left]]--;

                if(mp[nums[left]] == 0) {
                    mp.erase(nums[left]);
                }

                left++;
            }

            count = count + (right - left + 1);
            right++;
        }

        return count;

        return count;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        int lessThanEqualToK = lessThanEqualKDistinct(nums,k);
        int reducedLessThanEqualToK = lessThanEqualKDistinct(nums,k-1);

        return lessThanEqualToK - reducedLessThanEqualToK;
    }
};