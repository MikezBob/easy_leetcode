#include <vector>
using namespace std;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        long long res = 0;
        for (int i = 0; i < n; ++i) {
            int left = i;
            int right = n - 1;
            int best = -1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                long long sum = prefix[mid + 1] - prefix[i];
                int len = mid - i + 1;
                long long product = sum * len;
                if (product < k) {
                    best = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            if (best >= i) {
                res += best - i + 1;
            }
        }
        return res;
    }
};