class Solution {
private:
    void combination(string& digits,string combos[],vector<string>& result, string current,
                     int index) {

                        if(index == digits.size()) {
                            result.push_back(current);
                            return;
                        }

                        int digit = digits[index] - '0';

                        for(int i=0;i<combos[digit].size();i++) {

                            combination(digits,combos,result,current+combos[digit][i],index+1);
                        }
                     }

public:
    vector<string> letterCombinations(string digits) {

        string combos[] = {"",    "",    "abc",  "def", "ghi",
                           "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> result;

        combination(digits, combos,result, "", 0);

        return result;
    }
};