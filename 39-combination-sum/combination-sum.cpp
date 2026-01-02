class Solution {
private: void combination(vector<int>& candidates,vector<vector<int>>& result,vector<int> &sub,int target,int index) {
    if(index == candidates.size() || target<0) {
        if(target == 0) {
        result.push_back(sub);
    }
        return;
    }
    

    sub.push_back(candidates[index]);
    combination(candidates,result,sub,target - candidates[index],index);
    sub.pop_back();

    combination(candidates,result,sub,target,index+1);
}
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> result;
        vector<int> sub;

        combination(candidates,result,sub,target,0);

        return result;
    }
};