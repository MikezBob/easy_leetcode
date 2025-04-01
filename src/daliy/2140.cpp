#include <vector>
#include <algorithm>

using namespace std;

long long mostPoints(vector<vector<int>>& questions) {
    int n = questions.size();
    vector<long long> dp(n + 1, 0); // dp数组，dp[i]表示从第i个问题开始的最大得分
    
    for (int i = n - 1; i >= 0; --i) {
        int brainpower = questions[i][1];
        int next = i + brainpower + 1;
        long long solve = questions[i][0];
        if (next < n) {
            solve += dp[next];
        }
        long long skip = dp[i + 1];
        dp[i] = max(solve, skip);
    }
    
    return dp[0];
}