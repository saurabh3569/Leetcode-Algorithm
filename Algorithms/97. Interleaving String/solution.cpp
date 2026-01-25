class Solution {
public:
    bool solve(int i, int j, string& s1, string& s2, string& s3,
               vector<vector<int>>& dp) {

        if (i + j == s3.length())
            return true;

        if (dp[i][j] != -1)
            return dp[i][j];

        bool ans = false;

        if (i < s1.length() && s1[i] == s3[i + j]) {
            ans = solve(i + 1, j, s1, s2, s3, dp);
        }

        if (!ans && j < s2.length() && s2[j] == s3[i + j]) {
            ans = solve(i, j + 1, s1, s2, s3, dp);
        }

        return dp[i][j] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length(), m = s2.length();
        if (n + m != s3.length())
            return false;

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(0, 0, s1, s2, s3, dp);
    }
};
