class Solution {
    public:
        int countGoodNumbers(long long n) {
            const int MOD = 1e9 + 7;
            long long evenCount = (n + 1) / 2; // 偶数位置的个数
            long long oddCount = n / 2;         // 奇数位置的个数
            long long part1 = modularPow(5, evenCount, MOD);
            long long part2 = modularPow(4, oddCount, MOD);
            return (part1 * part2) % MOD;
        }
    
    private:
        long long modularPow(long long base, long long exponent, int mod) {
            long long result = 1;
            base %= mod;
            while (exponent > 0) {
                if (exponent % 2 == 1) {
                    result = (result * base) % mod;
                }
                base = (base * base) % mod;
                exponent /= 2;
            }
            return result;
        }
    };