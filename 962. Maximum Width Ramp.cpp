class Solution {
public:
  int maxWidthRamp(vector<int> &nums) {
    vector<pair<int, int>> most;
    most.push_back({nums[0], 0});
    int n = nums.size();
    int ramp = 0;
    for (int i = 1; i < n; ++i) {
      if (nums[i] < most.back().first) {
        most.push_back({nums[i], i});
      }
    }

    for (int i = n - 1; i >= 0; --i) {

      while (!most.empty() and most.back().second < i and
             most.back().first <= nums[i]) {

        ramp = max(ramp, i - most.back().second);
        most.pop_back();
      }
      if (!most.empty() and i <= most.back().second)
        most.pop_back();
    }
    return ramp;
  }
};
