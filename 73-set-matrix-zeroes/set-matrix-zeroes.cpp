class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        unordered_set<int> rows,cols;
        int row = matrix.size();
        int col = matrix[0].size();

        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(matrix[i][j]==0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {

                if(rows.count(i) || cols.count(j)) {
                    matrix[i][j]=0;
                }
            }
        }
    }
};