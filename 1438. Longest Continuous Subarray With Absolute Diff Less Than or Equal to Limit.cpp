class Solution {
public:
  int longestSubarray(vector<int> &nums, int limit) {
    int n = nums.size();
    deque<int> maxq = {0}, minq = {0}; // maxq 嚴格遞減隊列,  minq 嚴格遞增
    int res = 1;
    int l = 0, r = 1;
    while (r < n) {
      // r 加入 maxq 和minq
      while (!maxq.empty() and nums[maxq.back()] <= nums[r]) {
        maxq.pop_back();
      }
      maxq.push_back(r);
      while (!minq.empty() and nums[minq.back()] >= nums[r]) {
        minq.pop_back();
      }
      minq.push_back(r);

      ++r;
      if (nums[maxq[0]] - nums[minq[0]] <= limit) {
        res = max(res, r - l);
        continue;
      }

      while (nums[maxq[0]] - nums[minq[0]] > limit) {
        if (maxq.front() == l) {
          maxq.pop_front();
        }
        if (minq.front() == l) {
          minq.pop_front();
        }
        ++l;
      }
      res = max(res, r - l);
    }
    res = max(res, r - l);

    return res;
  }
};
