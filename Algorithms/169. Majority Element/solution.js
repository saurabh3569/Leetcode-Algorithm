var majorityElement = function (nums) {
  const map = {};
  let ans = nums[0];

  for (const n of nums) {
    if (map[n]) {
      map[n]++;
      if (map[n] > Math.floor(nums.length / 2)) {
        ans = n;
        break;
      }
    } else {
      map[n] = 1;
    }
  }

  return ans;
};
