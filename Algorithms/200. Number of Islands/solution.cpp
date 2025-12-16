class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.empty())
            return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        int ans = 0;

        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == '1')
                {
                    ans++;
                    q.push({i, j});
                    grid[i][j] = '0';

                    while (!q.empty())
                    {
                        auto [x, y] = q.front();
                        q.pop();

                        for (auto [dx, dy] : dirs)
                        {
                            int nx = x + dx;
                            int ny = y + dy;

                            if (nx >= 0 && ny >= 0 && nx < rows && ny < cols &&
                                grid[nx][ny] == '1')
                            {
                                q.push({nx, ny});
                                grid[nx][ny] = '0';
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
