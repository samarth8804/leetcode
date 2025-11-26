class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        unordered_map<char,char> mapping;

        set<char> ch;

        int n = s.length();

        for(int i=0;i<n;i++) {

            if(mapping.count(s[i]) > 0) {

                if(mapping[s[i]] != t[i]) {
                    return false;
                }
            }
            else if(ch.count(t[i]) > 0){
                return false;
            }
            else {
                mapping[s[i]] = t[i];
                ch.insert(t[i]);
            }
        }

        return true;
    }
};