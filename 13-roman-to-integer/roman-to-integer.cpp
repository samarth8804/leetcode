class Solution {
public:
    int romanToInt(string s) {

        int n = s.length();
        int i = 0;
        int value = 0;

        while (i < n) {

            if (s[i] == 'I') {
                if (i != n - 1 && s[i + 1] == 'V') {
                    value += 4;
                    i += 2;
                } else if (i != n - 1 && s[i + 1] == 'X') {
                    value += 9;
                    i += 2;
                } else {
                    value += 1;
                    i++;
                }
            } else if (s[i] == 'V') {
                value += 5;
                i++;
            } else if (s[i] == 'X') {
                if (i != n - 1 && s[i + 1] == 'L') {
                    value += 40;
                    i += 2;
                } else if (i != n - 1 && s[i + 1] == 'C') {
                    value += 90;
                    i += 2;
                } else {
                    value += 10;
                    i++;
                }
            } else if (s[i] == 'L') {
                value += 50;
                i++;
            } else if (s[i] == 'C') {
                if (i != n - 1 && s[i + 1] == 'D') {
                    value += 400;
                    i += 2;
                } else if (i != n - 1 && s[i + 1] == 'M') {
                    value += 900;
                    i += 2;
                } else {
                    value += 100;
                    i++;
                }
            } else if (s[i] == 'D') {
                value += 500;
                i++;
            } else if (s[i] == 'M') {
                value += 1000;
                i++;
            }
        }

        return value;
    }
};