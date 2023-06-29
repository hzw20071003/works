#include <bits/stdc++.h>
#define ll long long
#define N 500005
using namespace std;
int read() {
  int x = 0, f = 1, ch = getchar();
  for (; !isdigit(ch); ch = getchar()) f = (ch == '-') ? -1 : 1;
  for (; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + (ch ^ 48);
  return x * f;
}
string s[N];
int n, m, ans1, ans2;
bool vis[N];
int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);
  n = read(), m = read();
  int cnt1 = m / 2, cnt2 = m / 4;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
    s[i] = " " + s[i];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) vis[j] = 0;
    int now1 = 0, now2 = 0;
    for (int j = 1; j <= m;) {
      if (s[i][j] == '1') {
        ++ans1;
        if (j < m && s[i][j] == s[i][j + 1] && now1 < cnt2) {
          j += 2, ++now1;
          continue;
        }
      }
      ++j;
    }
    for (int j = 1; j <= m;) {
      if (j < m && s[i][j] == s[i][j + 1] && s[i][j] == '0' && now2 < cnt2) {
        ++now2;
        vis[j] = vis[j + 1] = true;
        j += 2;
        continue;
      } else if (j < m && s[i][j] != s[i][j + 1] && now2 < cnt2) {
        ++now2, ++ans2;
        vis[j] = vis[j + 1] = true;
        j += 2;
        continue;
      }
      ++j;
    }
    for (int j = 1; j <= m;) {
      if (j < m && s[i][j] == s[i][j + 1] && s[i][j] == '1' && now2 < cnt2 && !vis[j] && !vis[j + 1]) {
        vis[j] = vis[j + 1] = true;
        j += 2, ++now2, ++ans2;
        continue;
      } else if (s[i][j] == '1' && !vis[j]) {
        vis[j] = true;
        ++j, ++ans2;
        continue;
      }
      ++j;
    }
  }
  printf("%d %d", ans1, ans2);
  return 0;
}
