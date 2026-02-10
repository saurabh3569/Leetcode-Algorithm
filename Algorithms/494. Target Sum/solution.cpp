class Solution {
public:
    int solve(vector<int>& nums, int target, int i, int curr,
              vector<vector<int>>& dp, int offset) {
        if (curr == target && i == nums.size()) {
            return 1;
        }

        if (i == nums.size()) {
            return 0;
        }

        if (dp[i][curr + offset] != -1) {
            return dp[i][curr + offset];
        }

        int plus = solve(nums, target, i + 1, curr + nums[i], dp, offset);
        int minus = solve(nums, target, i + 1, curr - nums[i], dp, offset);

        return dp[i][curr + offset] = plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int x : nums)
            sum += x;

        int offset = sum;
        vector<vector<int>> dp(nums.size(), vector<int>(2 * sum + 1, -1));

        return solve(nums, target, 0, 0, dp, offset);
    }
};