var combine = function (n, k) {
  const ans = [];

  function backtrack(start, path) {
    if (path.length === k) {
      ans.push([...path]);
      return;
    }

    for (let i = start; i <= n; i++) {
      path.push(i);
      backtrack(i + 1, path);
      path.pop();
    }
  }

  backtrack(1, []);
  return ans;
};
