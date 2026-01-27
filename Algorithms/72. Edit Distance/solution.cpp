class Solution {
public:
    int rec(string word1, string word2, int i, int j, vector<vector<int>>& dp) {
        if (i == word1.length() && j == word2.length()) {
            return 0;
        }

        if (i == word1.length())
            return word2.length() - j;

        if (j == word2.length())
            return word1.length() - i;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (word1[i] == word2[j]) {
            return rec(word1, word2, i + 1, j + 1, dp);
        }

        int insertOp = 1 + rec(word1, word2, i, j + 1, dp);
        int deleteOp = 1 + rec(word1, word2, i + 1, j, dp);
        int replaceOp = 1 + rec(word1, word2, i + 1, j + 1, dp);

        return dp[i][j] = min({insertOp, deleteOp, replaceOp});
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));
        return rec(word1, word2, 0, 0, dp);
    }
};