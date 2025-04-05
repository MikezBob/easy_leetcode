class Solution {
    public:
        int subsetXORSum(vector<int>& nums) {
            int sum = 0;
            int n = nums.size();
            for (int k = 0; k < 32; ++k) {
                int cnt = 0;
                for (int num : nums) {
                    if ((num >> k) & 1) {
                        ++cnt;
                    }
                }
                if (cnt > 0) {
                    sum += (1 << k) * (1 << (n - 1));
                }
            }
            return sum;
        }
    };