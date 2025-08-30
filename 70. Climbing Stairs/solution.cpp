class Solution
{
public:
    int rec(int n, vector<int> &dp)
    {
        if (n == 0 || n == 1)
            return 1;

        if (dp[n] != -1)
        {
            return dp[n];
        }

        dp[n] = rec(n - 1, dp) + rec(n - 2, dp);
        return dp[n];
    }
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        return rec(n, dp);
    }
};