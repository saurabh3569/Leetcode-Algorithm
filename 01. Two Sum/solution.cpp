class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            int key = target - nums[i];
            if (m.find(key) != m.end())
            {
                return {m[key], i};
            }
            m[nums[i]] = i;
        }
        return {-1};
    }
};