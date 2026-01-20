class Solution {
public:
    int dfs(vector<vector<int>>& dp, int i, int j, int m, int n) {
        if (i >= m || j >= n)
            return 0;

        if (i == m - 1 && j == n - 1)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        dp[i][j] = dfs(dp, i + 1, j, m, n) + dfs(dp, i, j + 1, m, n);

        return dp[i][j];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return dfs(dp, 0, 0, m, n);
    }
};