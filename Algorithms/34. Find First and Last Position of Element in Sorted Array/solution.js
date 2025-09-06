var searchRange = function (nums, target) {
  let left = -1;
  let right = -1;
  function bsLeft(left, right) {
    if (left > right) {
      return -1;
    }

    let mid = Math.floor((right + left) / 2);

    if (nums[mid] === target) {
      if (mid == 0 || nums[mid - 1] !== target) return mid;
      return bsLeft(left, mid - 1);
    }

    if (nums[mid] > target) return bsLeft(left, mid - 1);
    else return bsLeft(mid + 1, right);
  }

  function bsRight(left, right) {
    if (left > right) {
      return -1;
    }

    let mid = Math.floor((right + left) / 2);

    if (nums[mid] === target) {
      if (mid === nums.length - 1 || nums[mid + 1] !== target) return mid;
      return bsRight(mid + 1, right);
    }

    if (nums[mid] > target) return bsRight(left, mid - 1);
    else return bsRight(mid + 1, right);
  }

  const idx1 = bsLeft(0, nums.length - 1);
  const idx2 = bsRight(0, nums.length - 1);

  return [idx1, idx2];
};
