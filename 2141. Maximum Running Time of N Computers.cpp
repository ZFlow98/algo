class Solution {
public:
  long long maxRunTime(int n, vector<int> &batt) {

    const int cnt = batt.size();
    sort(batt.begin(), batt.end());
    vector<long long> pfix_batt(cnt + 1);
    for (int i = 1; i < cnt + 1; ++i) {
      pfix_batt[i] = pfix_batt[i - 1] + batt[i - 1];
    }

    auto verify = [&](long long x) -> bool {
      auto it = lower_bound(batt.begin(), batt.end(), x);
      int total = it - batt.begin(); // 前total個數小於x
      int yes = cnt - total;         // 後yes個數大於等於x
      return pfix_batt[total] >= (long long)(n - yes) * x;
    };

    long long left, right;
    for (left = 0, right = pfix_batt[cnt] / n; left < right;) {
      long long mid = left + (right - left + 1) / 2;
      if (verify(mid)) {
        left = mid;
      } else {
        right = mid - 1;
      }
    }

    return left;
  }
};
