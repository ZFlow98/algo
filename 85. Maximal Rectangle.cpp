class Solution {
public:
  int maximalRectangle(vector<vector<char>> &mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> pmat(m + 1, vector<int>(n + 1));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int x = mat[i][j] - 48;
        if (x == 0) {
          pmat[i + 1][j] = 0;
        } else {
          pmat[i + 1][j] = pmat[i][j] + (mat[i][j] - 48);
        }
      }
    }

    int res = 0;
    for (int i = 1; i <= m; ++i) {
      vector<pair<int, int>> most; // monotonic non-strictly increasing stack
      for (int j = 0; j <= n; ++j) {
        while (!most.empty() and pmat[i][j] < most.back().first) {
          auto [x1, x2] = most.back();
          most.pop_back();
          res = max(
              res, (most.empty() ? j * x1 : (j - most.back().second - 1) * x1));
        }
        most.push_back({pmat[i][j], j});
      }
    }
    return res;
  }
};
