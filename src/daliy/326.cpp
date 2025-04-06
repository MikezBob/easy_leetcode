vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size(), max_len = 1, max_idx = 0;
    vector<int> dp(n, 1), parent(n, -1);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }
        if (dp[i] > max_len) {
            max_len = dp[i];
            max_idx = i;
        }
    }

    vector<int> res;
    for (int i = max_idx; i != -1; i = parent[i]) {
        res.push_back(nums[i]);
    }
    reverse(res.begin(), res.end());
    return res;
}