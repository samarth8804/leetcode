class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        sort(strs.begin(),strs.end());

        int n = strs.size();

        int len1 = strs[0].length();

        int len2 = strs[n-1].length();

        int i=0;

        while(i<len1 && i<len2) {

            if(strs[0][i] == strs[n-1][i]) {
                i++;
            }
            else {
                return strs[0].substr(0,i);
            }
        }

        return strs[0].substr(0,i);
    }
};