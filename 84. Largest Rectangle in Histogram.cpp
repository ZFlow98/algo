#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    heights.push_back(0);
    int n = heights.size();
    vector<int> st;
    int res = 0;
    for (int i = 0; i < n; i++) {
      while (!st.empty() && heights[st.back()] >= heights[i]) {
        int h = heights[st.back()];
        st.pop_back();
        int w = st.empty() ? i : i - st.back() - 1;
        res = max(res, h * w);
      }
      st.push_back(i);
    }
    return res;
  }
};
