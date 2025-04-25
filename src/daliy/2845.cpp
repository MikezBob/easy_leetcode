#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, int> cnt; // 哈希表记录前缀和模数出现的次数
        cnt[0] = 1; // 初始前缀和为0的次数为1
        long long ans = 0;
        int s = 0; // 当前前缀和（满足条件的元素数量）
        for (int x : nums) {
            s += (x % modulo == k) ? 1 : 0; // 更新前缀和
            int target = ((s - k) % modulo + modulo) % modulo; // 计算目标值，处理负数
            ans += cnt[target]; // 累加符合条件的子数组数量
            int current_mod = s % modulo; // 当前前缀和的模数
            cnt[current_mod]++; // 更新哈希表
        }
        return ans;
    }
};