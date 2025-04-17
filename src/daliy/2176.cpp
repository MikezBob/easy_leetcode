#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < nums.size(); ++i) {
            groups[nums[i]].push_back(i);
        }

        int res = 0;
        for (auto& entry : groups) {
            vector<int>& indices = entry.second;
            sort(indices.begin(), indices.end());
            int m = indices.size();
            for (int p = 0; p < m; ++p) {
                int i = indices[p];
                int g = gcd(i, k);
                int x = k / g;
                if (x == 1) {
                    res += (m - p - 1);
                } else {
                    for (int q = p + 1; q < m; ++q) {
                        int j = indices[q];
                        if (j % x == 0) {
                            res++;
                        }
                    }
                }
            }
        }
        return res;
    }
};