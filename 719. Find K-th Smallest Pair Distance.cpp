class Solution {
public:
  int smallestDistancePair(vector<int> &nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    auto sol = [&](int x) -> bool {
      long long cnt = 0;
      int l = 0;
      for (int r = 0; r < n; ++r) {
        while (nums[r] - nums[l] > x) {
          l++;
        }
        cnt += (r - l);
      };
      return cnt >= k;
    };

    int left, right;
    for (left = 0, right = nums[n - 1] - nums[0]; left < right;) {
      int mid = left + (right - left) / 2;
      if (sol(mid)) {
        right = mid;
      } else
        left = mid + 1;
    }
    return left;
  }
};
