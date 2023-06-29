#include <iostream>
#include <vector>

using namespace std;

const int kMaxN = 21;

int n, tmp, num[kMaxN], dp[kMaxN];
pair<int, int> ans;
bool Move[kMaxN][kMaxN], Turn[kMaxN][kMaxN];
vector<int> Memory;

bool Find(int x, int now) {
  Memory.push_back(x);
  now += num[x];
  if (now == ans.first) {
    return 1;
  }
  for (int i = 1; i <= x; i++) {
    if (Turn[x][i] && Find(i, now)) {
      return 1;
    }
  }
  Memory.pop_back();
  return 0;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
    dp[i] = num[i];
    if (ans.first < dp[i]) {
      ans = {dp[i], i};
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      cin >> tmp;
      Move[i][j] = Turn[j][i] = tmp;
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (Move[i][j]) {
        dp[j] = max(dp[i] + num[j], dp[j]);
        if (ans.first < dp[j]) {
          ans = {dp[j], j};
        }
      }
    }
  }
  Find(ans.second, 0);
  for (int i = Memory.size() - 1; i >= 0; i--) {
    cout << Memory[i] << ' ';
  }
  cout << endl;
  cout << ans.first;
  return 0;
}