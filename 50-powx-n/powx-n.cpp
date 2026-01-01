class Solution {
private:
    double power(double x,int n) {

        if(n == 0) {
            return 1.0;
        }

        double half = power(x,n/2);

        if(n%2 == 0) {
            return half*half;
        }
        else{
            return half*half*x;
        }
    }
public:
    double myPow(double x, int n) {
        
        long long num = 1LL*n;

        if(num<0) {
            num = -1 * num;
            x = 1/x;
        }

        return power(x,num);
    }
};