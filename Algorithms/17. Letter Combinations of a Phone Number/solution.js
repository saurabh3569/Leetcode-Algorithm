/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function (digits) {
  if (!digits.length) return [];

  const map = {
    2: "abc",
    3: "def",
    4: "ghi",
    5: "jkl",
    6: "mno",
    7: "pqrs",
    8: "tuv",
    9: "wxyz",
  };

  const ans = [];
  const n = digits.length;
  let idx = 0;

  function recursion(temp, idx) {
    if (idx === digits.length) {
      ans.push(temp.join(""));
      return;
    }

    const curr = map[digits[idx]];
    if (!curr) return;

    for (let i = 0; i < curr.length; i++) {
      temp.push(curr[i]);
      recursion(temp, idx + 1);
      temp.pop();
    }
  }

  recursion([], 0);

  return ans;
};
