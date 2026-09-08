using namespace std;

class Solution {
public:
  string removeDuplicateLetters(string s) {
    vector<int> dict(26);
    for (char c : s) {
      ++dict[c - 'a'];
    }

    vector<bool> yes(26);
    string most = "";

    for (char c : s) {
      while (!most.empty() and !yes[c - 'a'] and
             (most.back() > c and dict[most.back() - 'a'] > 0)) {
        yes[most.back() - 'a'] = false;
        most.pop_back();
      }
      if (!yes[c - 'a']) {
        most.push_back(c);
        yes[c - 'a'] = true;
      }
      --dict[c - 'a'];
    }
    return most;
  }
};
