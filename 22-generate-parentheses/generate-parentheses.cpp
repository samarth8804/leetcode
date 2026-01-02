class Solution {
private: 
    void generate(vector<string> &result,string curr,int open,int close,int n) {

        if(curr.length() == n*2) {
            result.push_back(curr);
            return;
        }

        if(open<n) {
            generate(result,curr+"(",open+1,close,n);
        }
        if(close<open) {
            generate(result,curr+")",open,close+1,n);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        
        int open = 0;
        int close = 0;
        vector<string> result;

        generate(result,"",open,close,n);

        return result;
    }
};

