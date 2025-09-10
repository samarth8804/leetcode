class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> result;
        int m = intervals.size();

        sort(intervals.begin(),intervals.end());

        result.push_back(intervals[0]);

        for(int i = 1;i<m;i++) {

            vector<int> &last = result.back();

            if(last[1] >= intervals[i][0]) {
                last[1] = max(last[1],intervals[i][1]);
            }
            else {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};