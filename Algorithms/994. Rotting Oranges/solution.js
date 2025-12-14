var orangesRotting = function (grid) {
  let rows = grid.length;
  let cols = grid[0].length;
  let queue = [];
  let fresh = 0;

  for (let i = 0; i < rows; i++) {
    for (let j = 0; j < cols; j++) {
      if (grid[i][j] === 2) queue.push([i, j]);
      if (grid[i][j] === 1) fresh++;
    }
  }

  let minutes = 0;
  let dirs = [
    [1, 0],
    [-1, 0],
    [0, 1],
    [0, -1],
  ];

  while (queue.length && fresh > 0) {
    let size = queue.length;

    for (let k = 0; k < size; k++) {
      let [x, y] = queue.shift();

      for (let [dx, dy] of dirs) {
        let nx = x + dx;
        let ny = y + dy;

        if (
          nx >= 0 &&
          ny >= 0 &&
          nx < rows &&
          ny < cols &&
          grid[nx][ny] === 1
        ) {
          grid[nx][ny] = 2;
          fresh--;
          queue.push([nx, ny]);
        }
      }
    }
    minutes++;
  }

  return fresh === 0 ? minutes : -1;
};
