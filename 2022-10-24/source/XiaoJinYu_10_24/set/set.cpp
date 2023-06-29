#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 30, Mod = 1e9 + 7;

int n, ans;

bool f[MAXN];
int anss[MAXN];
int a[MAXN];

bool check() {
  int cnt = 0;
  for (int i = 0; i <= n; ++i) {
    if (f[i]) {
      a[cnt++] = i;
    }
  }
  for (int i = 0; i < cnt; ++i) {
    for (int j = i + 1; j < cnt; ++j) {
      if (!f[a[i] ^ a[j]]) {
        return 0;
      }
    }
  }
  return 1;
}

int ksm(int a, int b) {
  if (b == 0) return 1;
  int x = ksm(a, b >> 1);
  return (((1ll * x * x) % Mod) * ((b & 1) ? a : 1)) % Mod;
}

void dfs(int x) {
  if (x > n) {
    if (check()) {
      ++ans;
      // int cnt = 0;
      // for (int i = 0; i <= n; ++i) {
      //   if (f[i]) {
      //     cout << i << ' ';
      //     ++cnt;
      //   }
      // }
      // cout << '\n';
      // ++anss[cnt];
    }
    return;
  }
  f[x] = 1;
  dfs(x + 1);
  f[x] = 0;
  dfs(x + 1);
}

int main() {
  freopen("set.in", "r", stdin);
  freopen("set.out", "w", stdout);
  cin >> n;
  if (n < 31) {
    f[0] = 1;
    dfs(1);
  } else {
    int m = 0;
    for (; (1 << m) < n; ++m);
    for (int i = 0, s = 1, j = 1; i * 2 <= m; ++i) {
      int shit = (1ll * s * ksm((j - 1 + Mod) % Mod, Mod - 2)) % Mod;
      ans = (1ll * ans + shit) % Mod;
      if (i * 2 < m) ans = (1ll * ans + shit) % Mod;
      j = (2ll * j) % Mod;
      s = (1ll * s * ((ksm(2, m - i) - 1 + Mod) % Mod)) % Mod;
    }
    ans += 2;
  }
  cout << ans;
  // for (int i = 1; i <= n + 1; ++i) {
  //   if (anss[i]) {
  //     cout << i << ' ' << anss[i] << '\n';
  //   }
  // }
  // cout << '\n' << clock();
  return 0;
}