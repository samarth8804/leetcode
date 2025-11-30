class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char,int> mp;

        int n = s.length();

        for(int i=0;i<n;i++) {
            mp[s[i]]++;
        }

        multimap<int,char,greater<int>> sortedMp;

        for(auto &p : mp) {

            sortedMp.insert({p.second,p.first});
        }

        string result = "";

        for(auto &p : sortedMp) {

            for(int i=0;i<p.first;i++) {
                result += p.second;
            }
        }

        return result;
    }
};