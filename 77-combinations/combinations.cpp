class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        
        int start = 1;
        vector<vector<int>> result;
        vector<int> combination;

        Combination(start,combination,result,n,k);

        return result;
    }
private : 
    void Combination(int start,vector<int> &combination,vector<vector<int>> &result,int n,int k) {
        if(combination.size() == k) {
            result.push_back(combination);
            return;
        }

        for(int i=start;i<=n;i++) {
            combination.push_back(i);
            Combination(i+1,combination,result,n,k);
            combination.pop_back();
        }
    }
};