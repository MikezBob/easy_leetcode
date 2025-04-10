#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        unsigned long long s_num = stoull(s);
        if (s_num > finish) {
            return 0;
        }
        int k = s.size();
        unsigned long long base = pow(10, k);
        long long count = (s_num >= start && s_num <= finish) ? 1 : 0;
        
        unsigned long long upper_prefix = (finish - s_num) / base;
        unsigned long long lower_prefix = (start > s_num) ? ((start - s_num + base - 1) / base) : 1;
        lower_prefix = max(lower_prefix, 1ULL);
        
        if (lower_prefix > upper_prefix) {
            return count;
        }
        
        auto digitDP = [&](unsigned long long n) -> long long {
            if (n == 0) return 0;
            string digits = to_string(n);
            int m = digits.size();
            vector<unsigned long long> pow_lim(m + 2);
            pow_lim[0] = 1;
            for (int i = 1; i <= m + 1; ++i) {
                pow_lim[i] = pow_lim[i - 1] * (limit + 1);
            }
            
            vector<vector<vector<long long>>> memo(m, vector<vector<long long>>(2, vector<long long>(2, -1)));
            
            function<long long(int, bool, bool)> dfs = [&](int pos, bool is_limit, bool leading_zero) -> long long {
                if (pos == m) {
                    return leading_zero ? 0 : 1;
                }
                if (memo[pos][is_limit][leading_zero] != -1) {
                    return memo[pos][is_limit][leading_zero];
                }
                if (!is_limit) {
                    int remaining = m - pos;
                    long long res = leading_zero ? (pow_lim[remaining] - 1) : pow_lim[remaining];
                    memo[pos][is_limit][leading_zero] = res;
                    return res;
                }
                long long res = 0;
                int upper = min(limit, digits[pos] - '0');
                for (int d = 0; d <= upper; ++d) {
                    bool new_limit = is_limit && (d == (digits[pos] - '0'));
                    bool new_leading = leading_zero && (d == 0);
                    res += dfs(pos + 1, new_limit, new_leading);
                }
                memo[pos][is_limit][leading_zero] = res;
                return res;
            };
            
            return dfs(0, true, true);
        };
        
        long long case2 = digitDP(upper_prefix) - digitDP(lower_prefix - 1);
        return count + case2;
    }
};