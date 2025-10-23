function rec(grid, i, j, sum, dp) {
    let m = grid.length;
    let n = grid[0].length;

    if (i === m - 1 && j === n - 1) {
        return sum;
    }

    if (dp[i][j] !== -1) return dp[i][j] + sum - grid[i][j];

    let down = Infinity, right = Infinity;

    if (i + 1 < m) {
        down = rec(grid, i + 1, j, sum + grid[i + 1][j], dp);
    }

    if (j + 1 < n) {
        right = rec(grid, i, j + 1, sum + grid[i][j + 1], dp);
    }

    dp[i][j] = Math.min(down, right) - sum + grid[i][j];

    return Math.min(down, right);
}

var minPathSum = function (grid) {
    const dp = Array.from({ length: grid.length }, () => Array(grid[0].length).fill(-1));
    return rec(grid, 0, 0, grid[0][0], dp);
};
