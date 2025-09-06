class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        vector<int> ans;

        if (nums.empty())
        {
            return 0;
        }
        int pre = nums[0];
        int cnt = 1;
        ans.push_back(pre);

        for (int i = 1; i < nums.size(); i++)
        {
            if (pre != nums[i])
            {
                ans.push_back(nums[i]);
                cnt++;
                pre = nums[i];
            }
        }

        int k = 0;
        for (int j : ans)
        {
            nums[k] = j;
            k++;
        }

        return cnt;
    }
};