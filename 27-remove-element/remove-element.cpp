class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int i = 0;
        int j = 0;
        int n = nums.size();
        while(i<=j && j<n) {
            if(i==j) {
                if(nums[i] == val) {
                    j++;
                }
                else{
                    i++;
                    j++;
                }
            }
            else if(nums[i] == val) {
                if(nums[j]!=val) {
                    swap(nums[i],nums[j]);
                    i++;
                    j++;
                }
                else{
                    j++;
                }
            }
        }

        return i;
    }
};