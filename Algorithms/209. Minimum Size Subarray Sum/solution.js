var minSubArrayLen = function (target, nums) {
  let sum = 0;
  let left = 0;
  let ans = Infinity;

  for (let right = 0; right < nums.length; right++) {
    sum += nums[right];

    while (sum >= target) {
      ans = Math.min(ans, right - left + 1);
      sum -= nums[left];
      left++;
    }
  }

  return ans === Infinity ? 0 : ans;
};
