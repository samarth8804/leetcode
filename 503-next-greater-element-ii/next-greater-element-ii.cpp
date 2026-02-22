class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> result(n);

        stack<int> st;

        int i = (2*n) - 1;

        while(i>=0) {

            int idx = i%n;

            if(i<n) {
                if(st.empty()) {
                    result[i] = -1;
                    st.push(nums[i]);
                    i--;
                }
                else if(st.top()>nums[i]) {
                    result[i] = st.top();
                    st.push(nums[i]);
                    i--;
                }
                else{
                    st.pop();
                }
            }
            else{
                if(st.empty()) {
                    st.push(nums[idx]);
                    i--;
                }
                else if(st.top()>nums[idx]) {
                    st.push(nums[idx]);
                    i--;
                }
                else {
                    st.pop();
                }
            }
        }

        return result;
    }
};