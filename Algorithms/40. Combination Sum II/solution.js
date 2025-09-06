var combinationSum2 = function (candidates, target) {
  const ans = [];
  const used = new Array(candidates.length).fill(false);

  candidates = candidates.sort((a, b) => a - b);

  function backtrack(temp, count, start) {
    if (count > target) return;

    if (count === target) {
      ans.push([...temp]);
    }

    for (let i = start; i < candidates.length; i++) {
      if (used[i]) continue;
      if (i > 0 && candidates[i] === candidates[i - 1] && !used[i - 1])
        continue;

      temp.push(candidates[i]);
      count += candidates[i];
      used[i] = true;

      backtrack(temp, count, i + 1);

      temp.pop();
      count -= candidates[i];
      used[i] = false;
    }
  }

  backtrack([], 0, 0);

  return ans;
};
