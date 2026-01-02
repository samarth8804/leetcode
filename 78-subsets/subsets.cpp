class Solution {
private:
    void subsequence(vector<vector<int>> &result,vector<int> &nums,int index,int n,vector<int> &sub) {
        if(index == n) {
            result.push_back(sub);
            return;
        }

        subsequence(result,nums,index+1,n,sub);

        sub.push_back(nums[index]);

        subsequence(result,nums,index+1,n,sub);

        sub.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> result;
        vector<int> sub;
        int n = nums.size();

        subsequence(result,nums,0,n,sub);

        return result;
    }
};