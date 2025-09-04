class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        int total = m*n;
        vector<int> ans;

        int top = 0,bottom = m-1,left = 0,right = n-1;

        while(total>0) {

            for(int j=left;j<=right && total>0;j++) {
                ans.push_back(matrix[top][j]);
                total--;
            }
            top++;
            for(int i=top;i<=bottom && total>0;i++) {
                ans.push_back(matrix[i][right]);
                total--;
            }
            right--;
            for(int j=right;j>=left && total>0;j--) {
                ans.push_back(matrix[bottom][j]);
                total--;
            }
            bottom--;
            for(int i=bottom;i>=top && total>0;i--) {
                ans.push_back(matrix[i][left]);
                total--;
            }
            left++;
        }

        return ans;
    }
};