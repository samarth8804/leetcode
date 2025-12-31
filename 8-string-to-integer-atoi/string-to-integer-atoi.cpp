class Solution {
private:
    int convert(string &s,int n,int i,long long result,int sign) {

        if(i>=n || !isdigit(s[i])) {
            return (int)(result*sign);
        }

        result = result*10 + (s[i]-'0');
        
        if(result*sign >= INT_MAX) {
            return INT_MAX;
        }
        else if(result*sign <= INT_MIN){
            return INT_MIN;
        }

        return convert(s,n,i+1,result,sign);

    }
public:
    int myAtoi(string s) {
        
        int n = s.length();

        int i=0;

        long long result = 0;

        while(i<n && s[i]==' ') {
            i++;
        }

        int sign = 1;

        if(s[i] == '-' || s[i] == '+') {
            if(s[i] == '-') {
                sign = -1;
            }
            i++;
        }

        return convert(s,n,i,result,sign);
    }
};