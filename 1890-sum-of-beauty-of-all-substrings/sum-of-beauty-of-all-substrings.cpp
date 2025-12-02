class Solution {
private:
    int beauty(vector<int>& mp) {

        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(int i=0;i<26;i++) {

            if(mp[i] > 0) {
                if(mp[i] > maxi) {
                    maxi = mp[i];
                }
                if(mp[i] < mini) {
                    mini = mp[i];
                }
            }
        }

        return maxi-mini;
    }
public:
    int beautySum(string s) {
        
        int n = s.length();

        int result = 0;

        for(int i=0;i<n;i++) {
            vector<int> mp(26,0);
            for(int j=i;j<n;j++) {

                mp[s[j]-'a']++;

                result += beauty(mp);
            }
        }

        return result;
    }
};