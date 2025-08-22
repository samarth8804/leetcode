class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map<int,int> mp;

        int n = nums.size();

        int ans;

        for(int i=0;i<n;i++) {

            if(!mp.count(nums[i])) {
                mp[nums[i]] = 1;
            }
            else {
                mp[nums[i]]++;
            }

            if(mp[nums[i]] > n/2) {
                ans =  nums[i];
                break;
            }
        }

        return ans;
    }
};