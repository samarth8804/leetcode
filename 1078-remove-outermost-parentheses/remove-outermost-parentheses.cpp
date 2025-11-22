class Solution {
public:
    string removeOuterParentheses(string s) {
        
        int len = s.length();

        int count = 0;

        int start = 0;

        string ans = "";

        for(int i=0;i<len;i++) {

            if(s[i] == '(') {
                count++;
            }
            else if(s[i] == ')') {
                count--;
                if(count==0) {
                    for(int j = start+1;j<i;j++) {
                        ans = ans + s[j];
                    }
                    start = i+1;
                }
            }
        }

        return ans;

    }
};