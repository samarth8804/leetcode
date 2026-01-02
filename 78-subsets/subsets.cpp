class Solution {
private:
    void subset(vector<int> &nums,int mask,int i,vector<int> &sub) {
        if(mask & (1<<i)) {
            sub.push_back(nums[i]);
        }
    }
    void generateSubsets(vector<int> &nums,int total,int mask,vector<vector<int>> &result,int n) {
        if(mask == total) {
            return;
        }

        vector<int> sub;
        for(int i=0;i<n;i++) {
            subset(nums,mask,i,sub);
        }
        result.push_back(sub);

        generateSubsets(nums,total,mask+1,result,n);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> result;
        int n = nums.size();
        int total = 1<<n;
        int mask = 0;

        generateSubsets(nums,total,mask,result,n);

        return result;
    }
};