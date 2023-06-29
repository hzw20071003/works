#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("O2")
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

vector<int> a[MAXN];

inline void rd(int& s) {
  s = 0;
  int c(getchar());
  while (c < 48 || c > 57) c = getchar();
  while (c > 47 && c < 58) s = (s << 1) + (s << 3) + (c ^ 48), c = getchar();
}

int f[MAXN];

int fa(int x) {
  if (f[x] == x) return x;
  return f[x] = fa(f[x]);
}

int fl[MAXN], s[MAXN];

int main() {
  freopen("gcd.in", "r", stdin);
  freopen("gcd.out", "w", stdout);
  int n, m = -114514;
  long long ans = 0;
  rd(n);
  for (int i = 0, x; i < n; ++i) {
    rd(x);
    a[x].push_back(i);
    f[i] = i;
    if (x > m) m = x;
  }
  int cnt;
  for (int i = m; i > 1; --i) {
    cnt = 0;
    for (int j = 1; i * j <= m; ++j) {
      int f1 = -1;
      for (int k : a[i * j]) {
        int fk = fa(k);
        if (fl[fk] != i) {
          fl[fk] = i;
          s[cnt++] = fk;
        }
        if (f1 == -1) {
          f1 = fk;
        } else if (f1 > 0 && f1 != fk) {
          f1 = -2;
        }
      }
      if (f1 > 0) {
        a[i * j].clear();
        a[i * j].push_back(f1);
      }
    }
    for (int j = 1; j < cnt; ++j) {
      f[s[j]] = s[0];
      ans += i;
    }
  }
  cout << ans;
  return 0;
}