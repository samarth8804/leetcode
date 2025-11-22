class Solution {
public:
    string removeOuterParentheses(string s) {
        
        int len = s.length();

        int count = 0;

        string result = "";

        for(int i=0;i<len;i++) {

            if(s[i] == '(') {

                if(count>0) {
                    result = result + s[i];
                }

                count++;
            }
            else if(s[i] == ')') {
                if(count > 1) {
                    result = result + s[i];
                }

                count--;
            }
        }

        return result;
    }
};