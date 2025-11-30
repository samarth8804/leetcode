class Solution {
public:
    int myAtoi(string s) {

        int n = s.length();

        int i = 0;

        while (i < n && s[i] == ' ') {
            i++;
        }

        char sign = '+';

        if (i < n) {
            if (s[i] == '+') {
                sign = '+';
                i++;
            } else if (s[i] == '-') {
                sign = '-';
                i++;
            }
        }

        while (i < n && s[i] == '0') {
            i++;
        }

        int start = i;

        while (i < n && isdigit(s[i])) {
            i++;
        }

        int end = i - 1;

        if (start<=end) {
            string atoi;

            if ((end - start + 1) > 10) {

                atoi = s.substr(start, 11);
            } else {
                atoi = s.substr(start, end - start + 1);
            }

            long long num;

            if (atoi.length() > 0) {
                num = stoll(atoi);
            }

            if (sign == '-') {
                num = 0 - num;
            }

            if (num >= INT_MAX) {
                return INT_MAX;
            } else if (num <= INT_MIN) {
                return INT_MIN;
            } else {
                return int(num);
            }
        }
        else {
            return 0;
        }
    }
};