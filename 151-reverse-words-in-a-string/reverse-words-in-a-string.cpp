class Solution {
public:
    string reverseWords(string s) {
        
        reverse(s.begin(),s.end());

        string result = "";

        int n = s.length();

        int i=0;

        while(i<n) {

            string word = "";

            while(i<n && s[i] != ' ') {
                word = word + s[i];
                i++;
            }

            if(word.length() > 0) {
                
            reverse(word.begin(),word.end());

            result = result + " " + word;
            }

            i++;
        }

        return result.substr(1);
    }
};