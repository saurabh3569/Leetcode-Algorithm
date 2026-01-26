class Solution {
public:
    bool binarySearch(vector<int>& nums, int target, int s, int e) {

        if (s > e) {
            return false;
        }

        int i = (s + e) / 2;

        if (nums[i] == target) {
            return true;
        }

        if (nums[s] == nums[i] && nums[i] == nums[e]) {
            return binarySearch(nums, target, s + 1, e - 1);
        }

        if (nums[s] <= nums[i]) {
            if (nums[s] <= target && target < nums[i])
                return binarySearch(nums, target, s, i - 1);
            else
                return binarySearch(nums, target, i + 1, e);
        } else {
            if (nums[i] < target && target <= nums[e])
                return binarySearch(nums, target, i + 1, e);
            else
                return binarySearch(nums, target, s, i - 1);
        }
    }
    bool search(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }
};