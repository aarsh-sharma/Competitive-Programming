class Solution {
public:
    int maxUncrossedLines(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        vector<vector<int>> dp(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            int flag = 0;
            for (int j = 0; j < m; j++) {
                flag = flag or (a[i] == b[j]);
                if (i == 0) {
                    dp[i][j] = flag;
                } else if (j == 0) {
                    dp[i][j] = (a[i] == b[j]) or dp[i-1][j];
                } else {
                    if (a[i] == b[j]) {
                        dp[i][j] = max(dp[i-1][j-1] + 1, dp[i-1][j]);
                    } else {
                        dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                    }
                }
            }
        }
        return dp[n-1][m-1];
    }
};