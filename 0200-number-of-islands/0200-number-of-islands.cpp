class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        int count = 0;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    q.push({i, j});
                    grid[i][j] = '0';   

                    while (!q.empty()) {
                        auto [r, c] = q.front();
                        q.pop();

                        for (int k = 0; k < 4; k++) {

                            int nr = r + dx[k];
                            int nc = c + dy[k];

                            if (nr >= 0 && nr < rows &&
                                nc >= 0 && nc < cols &&
                                grid[nr][nc] == '1') {

                                grid[nr][nc] = '0';   // Mark visited
                                q.push({nr, nc});
                            }
                        }
                    }
                }
            }
        }

        return count;
    }
};