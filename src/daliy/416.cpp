#include <vector>
#include <numeric> // 用于求和

using namespace std;

bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) return false; // 总和为奇数，无法分割
    
    int target = sum / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true; // 初始状态：和为0的子集存在
    
    for (int num : nums) {
        // 反向遍历，避免重复使用元素
        for (int j = target; j >= num; j--) {
            dp[j] = dp[j] || dp[j - num];
        }
        // 提前终止优化：若已找到解，直接返回
        if (dp[target]) return true;
    }
    
    return dp[target];
}