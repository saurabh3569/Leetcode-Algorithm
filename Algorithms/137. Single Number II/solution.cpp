class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        if (nums.size() < 3)
            return nums[0];

        for (int i = 0; i < nums.size() - 2; i += 3) {
            if (nums[i] != nums[i + 1] && nums[i] != nums[i + 2]) {
                return nums[i];
            }
        }

        return nums[nums.size() - 1];
    }
};