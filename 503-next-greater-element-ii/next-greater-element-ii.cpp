class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        vector<int> result;

        int n = nums.size();

        int i = 0;

        while(i<n) {

            int j = (i+1)%n;

            while(i!=j) {
                if(nums[i]<nums[j]) {
                    result.push_back(nums[j]);
                    break;
                }
                else{
                    j = (j+1)%n;
                }
            }

            if(i==j) {
                result.push_back(-1);
            }

            i++;

        }

        
            return result;
        
    }
};