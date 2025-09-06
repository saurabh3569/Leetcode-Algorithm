var isValidSudoku = function (board) {
  // check row
  for (let i = 0; i < board.length; i++) {
    const nums = [];
    for (let j = 0; j < board[i].length; j++) {
      const key = board[i][j];
      if (isNaN(key)) {
        continue;
      }
      if (nums.includes(key)) {
        return false;
      }
      nums.push(key);
    }
  }
  // check col
  for (let i = 0; i < board.length; i++) {
    const nums = [];
    for (let j = 0; j < board[i].length; j++) {
      const key = board[j][i];
      if (isNaN(key)) {
        continue;
      }
      if (nums.includes(key)) {
        return false;
      }
      nums.push(key);
    }
  }
  // check grid
  for (let i = 0; i < board.length; i += 3) {
    const nums1 = [];
    const nums2 = [];
    const nums3 = [];
    for (let j = 0; j < 3; j++) {
      const key1 = board[i][j];
      const key2 = board[i + 1][j];
      const key3 = board[i + 2][j];
      if (
        nums1.includes(key1) ||
        nums1.includes(key2) ||
        nums1.includes(key3)
      ) {
        return false;
      }
      if (!isNaN(key1)) {
        nums1.push(key1);
      }
      if (!isNaN(key2)) {
        nums1.push(key2);
      }
      if (!isNaN(key3)) {
        nums1.push(key3);
      }
    }
    for (let j = 3; j < 6; j++) {
      const key1 = board[i][j];
      const key2 = board[i + 1][j];
      const key3 = board[i + 2][j];
      if (
        nums2.includes(key1) ||
        nums2.includes(key2) ||
        nums2.includes(key3)
      ) {
        return false;
      }
      if (!isNaN(key1)) {
        nums2.push(key1);
      }
      if (!isNaN(key2)) {
        nums2.push(key2);
      }
      if (!isNaN(key3)) {
        nums2.push(key3);
      }
    }
    for (let j = 6; j < 9; j++) {
      const key1 = board[i][j];
      const key2 = board[i + 1][j];
      const key3 = board[i + 2][j];
      if (
        nums3.includes(key1) ||
        nums3.includes(key2) ||
        nums3.includes(key3)
      ) {
        return false;
      }
      if (!isNaN(key1)) {
        nums3.push(key1);
      }
      if (!isNaN(key2)) {
        nums3.push(key2);
      }
      if (!isNaN(key3)) {
        nums3.push(key3);
      }
    }
  }

  return true;
};
