class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;

        vector<int> output;

        vector<int> greater;

        int n1  = nums1.size();

        int n2 = nums2.size();

        int i = n2-1;

        while(i>=0) {
            if(greater.empty()) {
                mp[nums2[i]] = -1;
                greater.push_back(nums2[i]);
                i--;
            }
            else if(greater.back() > nums2[i]) {
                mp[nums2[i]] = greater.back();
                greater.push_back(nums2[i]);
                i--;
            }
            else{
                greater.pop_back();
            }
        }

        for(int i = 0;i<n1;i++) {
            output.push_back(mp[nums1[i]]);
        }

        return output;
    }
};