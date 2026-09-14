class Solution {
public:
    long long power(long long base, long long exp) {
        long long ans = 1;
        long long mod = 1000000007;

        while (exp > 0) {
            if (exp % 2 == 1) {
                ans = (ans * base) % mod;
            }

            base = (base * base) % mod;
            exp /= 2;
        }

        return ans;
    }
    int countGoodNumbers(long long n) {
        long long mod = 1000000007;
        long long evenPosition = (n+1)/2;
        long long oddPosition = n/2;

        long long ans = power(5, evenPosition) *
                        power(4, oddPosition) % mod;

        return ans;
    }
};