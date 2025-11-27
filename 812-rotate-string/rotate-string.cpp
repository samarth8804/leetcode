class Solution {
public:
    bool rotateString(string s, string goal) {
        
        int n = s.length();

        if(s == goal) {
            return true;
        }

        for(int i=1;i<n;i++) {

            if((s.substr(i,n-i) + s.substr(0,i)) == goal) {
                return true;
            }
        }

        return false;
    }
};