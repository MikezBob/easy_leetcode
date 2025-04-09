#include <vector>
#include <unordered_set>

using namespace std;

int minOperations(vector<int>& nums, int k) {
    unordered_set<int> higher_vals; // 存储严格大于k的不同元素
    bool all_valid = true;

    for (int num : nums) {
        if (num < k) {
            all_valid = false; // 存在非法元素（无法操作到k）
        } else if (num > k) {
            higher_vals.insert(num); // 统计严格大于k的不同值
        }
    }

    return all_valid ? higher_vals.size() : -1;
}