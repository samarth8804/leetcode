class Solution {
private:
    void combination(vector<vector<int>> &result,vector<int> &sub,int k,int n,int num) {

        if(k == 0) {
            if(n == 0) {
                result.push_back(sub);
            }
            return;
        }

        if(num > n || num>9) {
            return;
        }

        sub.push_back(num);

        combination(result,sub,k-1,n-num,num+1);

        sub.pop_back();

        combination(result,sub,k,n,num+1);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>> result;
        vector<int> sub;

        combination(result,sub,k,n,1);

        return result;
    }
};