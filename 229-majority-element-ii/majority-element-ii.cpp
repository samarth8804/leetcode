class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int candidate1 = INT_MIN,candidate2 = INT_MIN,count1 = 0,count2 = 0;

        for(auto num : nums) {
            if(candidate1 == num) {
                count1++;
            }
            else if(candidate2 == num) {
                count2++;
            }
            else if(count1 == 0) {
                candidate1 = num;
                count1++;
            }
            else if(count2 == 0){
                candidate2 = num;
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;

        for(auto num : nums) {
            if(candidate1 == num) count1++;
            if(candidate2 == num) count2++;
        }

        vector<int> ans;
        int n = nums.size();
        if(count1 > (n/3)) ans.push_back(candidate1);
        if(count2 > (n/3)) ans.push_back(candidate2);

        return ans;
    }
};