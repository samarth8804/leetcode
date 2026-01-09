class Solution {
private:
    string convertToBinary(int n) {

        string res = "";

        while(n!=0) {

            if(n%2 == 1) {
                res = res + "1";
            }
            else{
                res = res + "0";
            }

            n = n/2;
        }

        reverse(res.begin(),res.end());

        return res;
    }

    void complement(string &binary) {

        int len = binary.length();

        int i=0;

        while(i<len) {

            if(binary[i] == '1') {
                binary[i] = '0';
            }
            else{
                binary[i] = '1';
            }
            i++;
        }

    }

    int convertToDecimal(string binary) {

        long long p2 = 1;
        long long num = 0;
        int len = binary.length()-1;

        while(len>=0) {

            if(binary[len]=='1') {
                num = num + p2;
            }
            p2 = p2*2;
            len--;
        }

        return (int)num;

    }
public:
    int findComplement(int num) {
        
        string binary = convertToBinary(num);

        complement(binary);

        return convertToDecimal(binary);
    }
};