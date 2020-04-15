class Solution {
public:
    int minDistance(string a, string b) {
        if (a == "" or b == "") return max(a.size(), b.size());
        int n = a.size(), m = b.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0) {
                    // dp[i][j] = max(j, flag);
                    dp[i][j] = j;
                } else if (j == 0) {
                    // dp[i][j] = (a[i] != b[j]) + dp[i-1][j];
                    dp[i][j] = i;
                } else {
                    if (a[i-1] == b[j-1]) {
                        dp[i][j] = dp[i - 1][j - 1];
                    } else {
                        dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j-1]));
                    }
                }
            }
        }
        return dp[n][m];
    }
};