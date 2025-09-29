function backtrack(triangle, idx, currIdx, memo) {
  if (idx === triangle.length) return 0;

  if (memo[idx] && memo[idx][currIdx] !== undefined) {
    return memo[idx][currIdx];
  }

  let left = backtrack(triangle, idx + 1, currIdx, memo);
  let right = backtrack(triangle, idx + 1, currIdx + 1, memo);

  let minSum = triangle[idx][currIdx] + Math.min(left, right);

  if (!memo[idx]) memo[idx] = [];

  memo[idx][currIdx] = minSum;

  return memo[idx][currIdx];
}

var minimumTotal = function (triangle) {
  const memo = [];
  return backtrack(triangle, 0, 0, memo);
};
