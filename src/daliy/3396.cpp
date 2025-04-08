#include <vector>
#include <unordered_set>

using namespace std;

int minimumOperations(vector<int>& nums) {
    int n = nums.size();
    unordered_set<int> seen;
    int max_len = 0;
    
    // 从后往前遍历，寻找最长无重复后缀
    for (int i = n - 1; i >= 0; --i) {
        if (seen.count(nums[i])) {
            break;
        }
        seen.insert(nums[i]);
        max_len++;
    }
    
    // 需要移除的元素数目
    int remove = n - max_len;
    // 计算操作次数：(remove + 2) / 3 等价于向上取整
    return (remove + 2) / 3;
}