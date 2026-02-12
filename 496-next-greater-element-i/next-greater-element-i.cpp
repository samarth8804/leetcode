class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size();
        int n2 = nums2.size();

        stack<int> st;
        unordered_map<int,int> mp;

        vector<int> result;

        int i = n2-1;
        
        while(i>=0) {
            if(st.empty()) {
                mp[nums2[i]] = -1;
                st.push(nums2[i]);
                i--;
            }
            else if(st.top() > nums2[i]) {
                mp[nums2[i]] = st.top();
                st.push(nums2[i]);
                i--;
            }
            else{
                st.pop();
            }
        }

        i = 0;
        while(i<n1) {
            result.push_back(mp[nums1[i]]);
            i++;
        }

        return result;
    }
};