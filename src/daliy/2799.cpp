
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int total_unique = unordered_set<int>(nums.begin(), nums.end()).size();
        if (total_unique == 0) return 0;
        return atMost(nums, total_unique) - atMost(nums, total_unique - 1);
    }
    
    int atMost(vector<int>& nums, int m) {
        int n = nums.size();
        int left = 0, res = 0, unique = 0;
        unordered_map<int, int> freq;
        
        for (int right = 0; right < n; ++right) {
            int num = nums[right];
            if (freq[num]++ == 0) {
                ++unique;
            }
            while (unique > m) {
                int left_num = nums[left];
                if (--freq[left_num] == 0) {
                    --unique;
                }
                ++left;
            }
            res += right - left + 1;
        }
        return res;
    }
};