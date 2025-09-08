class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        vector<int> ans;
        int n = nums.size();
        int count = 0;

        for(int i=0;i<n;i++) {
            if(mp.count(nums[i]) && mp[nums[i]] == -1) {
                continue;
            }
            mp[nums[i]]++;

            if(mp[nums[i]] > (n/3)) {
                ans.push_back(nums[i]);
                mp[nums[i]] = -1;
                count++;
            }
            if(count==2) {
                break;
            }
        }

        

        return ans;
    }
};