class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        double ans = 0;
        double sum = 0;
        for (int i = 0; i < k; i++)
        {
            sum += nums[i];
        }
        ans = sum / k;
        int j = 0;
        for (int i = k; i < nums.size(); i++)
        {
            sum += nums[i] - nums[j];
            ans = max(ans, sum / k);
            j++;
        }

        return ans;
    }
};