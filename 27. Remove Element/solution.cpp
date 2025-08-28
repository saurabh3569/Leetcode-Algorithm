class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int k = 0;
        int idx = 0;
        for (int i : nums)
        {
            if (i == val)
                continue;

            k += 1;
            nums[idx] = i;
            idx++;
        }
        return k;
    }
};