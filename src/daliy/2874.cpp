#include <vector>
#include <climits>
using namespace std;

long long maximumTripletValue(vector<int>& nums) {
    int n = nums.size();
    if (n < 3) return 0;
    
    vector<int> max_i_until(n);
    int current_max = nums[0];
    for (int j = 1; j < n; ++j) {
        max_i_until[j] = current_max;
        current_max = max(current_max, nums[j]);
    }
    
    vector<int> max_i_minus_j(n, 0);
    for (int j = 1; j < n; ++j) {
        max_i_minus_j[j] = max_i_until[j] - nums[j];
    }
    
    vector<int> prefix_max(n, 0);
    prefix_max[0] = INT_MIN;
    for (int j = 1; j < n; ++j) {
        prefix_max[j] = max(prefix_max[j - 1], max_i_minus_j[j]);
    }
    
    long long res = 0;
    for (int k = 2; k < n; ++k) {
        if (prefix_max[k - 1] == INT_MIN) continue;
        long long current = (long long)prefix_max[k - 1] * nums[k];
        if (current > res) {
            res = current;
        }
    }
    
    return res > 0 ? res : 0;
}