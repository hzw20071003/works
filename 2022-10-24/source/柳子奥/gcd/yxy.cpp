#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...) 1
#endif
#define file(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

using namespace std;

const int kMaxN = 1e5 + 5;

int n;
int a[kMaxN], cnt[kMaxN], kk[kMaxN];

int main() {
//   file("");
  freopen("gcd.in", "r", stdin);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    for (int j = 1; j * j <= a[i]; ++j) {
      if (a[i] % j == 0) {
        ++cnt[j];
        if (j * j != a[i]) ++cnt[a[i] / j];
      }
    }
  }
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      kk[__gcd(a[i], a[j])] = 1;
    }
  }
  for (int i = 1; i <= 1e5; ++i) {
    res += kk[i];
  }
  cout << res << endl;
  return 0;
}