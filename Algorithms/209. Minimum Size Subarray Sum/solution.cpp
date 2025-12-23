class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int ans = INT_MAX;
        int currSum = 0;
        int j = 0;

        for (int i = 0; i < n; i++)
        {
            currSum += nums[i];

            while (currSum >= target)
            {
                ans = min(ans, i - j + 1);
                currSum -= nums[j];
                j++;
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};
