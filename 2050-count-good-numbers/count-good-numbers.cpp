class Solution {
    static const long long MOD = 1000000007;
private:
    long long power(long long base,long long exp) {
        long long res = 1;
        while(exp>0) {
            if(exp & 1) {
                res = (res * base) % MOD;
            }
            
                base = (base * base) % MOD;
            
            exp = exp>>1;
        }

        return res;
    }
public:
    int countGoodNumbers(long long n) {
        
        long long even = (n+1)/2;
        long long odd = n/2;

        long long ans = (power(5,even) * power(4,odd)) % MOD;

        return (int)ans;
    }
};