class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int len1 = s.length();
        int len2 = t.length();

        if(len1 != len2) {
            return false;
        }

        unordered_map<char,int> mp;

        for(int i=0;i<len1;i++) {

            mp[s[i]]++;
        }

        for(int i=0;i<len2;i++) {

            if(--mp[t[i]] < 0) {
                return false;
            }
        }

        return true;
    }
};