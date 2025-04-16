#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        long long ans = 0;
        unordered_map<int, int> count; // 记录窗口内各元素的出现次数
        int total_pairs = 0; // 当前窗口内的总对数
        
        for (int right = 0; right < n; ++right) {
            int num = nums[right];
            // 添加右指针元素到窗口，并更新总对数
            total_pairs += count[num];
            count[num]++;
            
            // 当总对数 >=k 时，尝试缩小窗口左边界
            while (total_pairs >= k) {
                int left_num = nums[left];
                int current_count = count[left_num];
                // 移除左指针元素，并更新总对数
                total_pairs -= (current_count - 1); // 贡献减少量为 current_count - 1
                count[left_num]--;
                left++;
            }
            
            // 此时，所有以 right 结尾的子数组，左端点从 0 到 left-1 均满足条件
            ans += left;
        }
        
        return ans;
    }
};