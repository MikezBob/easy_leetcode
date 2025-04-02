#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

long long maximumTripletValue(vector<int>& nums) {
    int n = nums.size();
    if (n < 3) return 0;

    vector<int> max_left(n, INT_MIN);
    int max_so_far = nums[0];
    for (int j = 1; j < n; ++j) {
        max_left[j] = max_so_far;
        if (nums[j] > max_so_far) {
            max_so_far = nums[j];
        }
    }

    vector<long long> a(n);
    for (int j = 0; j < n; ++j) {
        a[j] = (long long)max_left[j] - nums[j];
    }

    vector<long long> max_a_before(n, LLONG_MIN);
    max_a_before[0] = LLONG_MIN;
    for (int k = 1; k < n; ++k) {
        max_a_before[k] = max(max_a_before[k-1], a[k-1]);
    }

    long long res = LLONG_MIN;
    for (int k = 0; k < n; ++k) {
        if (max_a_before[k] == LLONG_MIN) continue;
        long long current = max_a_before[k] * nums[k];
        if (current > res) {
            res = current;
        }
    }

    return max(res, 0LL);
}