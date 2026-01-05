class Solution {
private:
    void combination(vector<vector<int>> &result,vector<int> &sub,vector<int> &candidates,int target,int index) {

            if(target == 0) {
                result.push_back(sub);
                return;
            }
        
        for(int i=index;i<candidates.size();i++) {

            if(i>index && (candidates[i] == candidates[i-1])) {
                continue;
            }

            if(candidates[i] > target) {
                break;
            }

            sub.push_back(candidates[i]);

            combination(result,sub,candidates,target - candidates[i],i+1);

            sub.pop_back();
        }


    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> sub;

        sort(candidates.begin(),candidates.end());

        combination(result,sub,candidates,target,0);

        return result;
    }
};