class Solution {
public:
  int numSubmat(vector<vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size();
    vector<int> pmat(n + 1);
    int res = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (mat[i][j] == 0) {
          pmat[j] = 0;
        } else {
          pmat[j] += 1;
        }
      }

      /*
      for(int j = 0; j<=n;++j){
              cout<<pmat[j]<<" ";
      }
      cout<<endl;
      */

      vector<int> most;
      for (int j = 0; j <= n; ++j) { // j代表當前新元素位置
        while (!most.empty() and pmat[most.back()] >= pmat[j]) { // 嚴格遞增棧
          int x = most.back();
          most.pop_back();
          if (most.empty()) {
            res += pmat[x] * (x + 1) * (j - x);
          } else {
            res += pmat[x] * (j - x) * (x - most.back());
          }
        }
        most.push_back(j);
      }
      // cout<<"row res"<<res<<endl;
    }
    return res;
  }
};
