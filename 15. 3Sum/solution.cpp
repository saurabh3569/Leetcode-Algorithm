class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; ++i)
        {
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = n - 1;
            int target = -nums[i];

            while (left < right)
            {
                int sum = nums[left] + nums[right];

                if (sum == target)
                {
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicates for the second element
                    while (left < right && nums[left] == nums[left + 1])
                        ++left;

                    // Skip duplicates for the third element
                    while (left < right && nums[right] == nums[right - 1])
                        --right;

                    ++left;
                    --right;
                }
                else if (sum < target)
                {
                    ++left;
                }
                else
                {
                    --right;
                }
            }
        }

        return result;
    }
};