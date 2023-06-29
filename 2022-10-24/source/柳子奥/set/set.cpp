#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...) 1
#endif
#define file(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

using namespace std;

int n, ans;
int a[25];
bool vis[100];

int main() {
  file("set");
  cin >> n;
  for (int i = 1; i < (1 << (n + 1)); ++i) {
    int m = 0;
    for (int j = 0; j <= n; ++j) {
      vis[j] = 0;
      if (i >> j & 1) a[++m] = j, vis[j] = 1;
    }
    for (int j = 1; j <= m; ++j)
      for (int k = j; k <= m; ++k) 
        if ((a[j] ^ a[k]) > n || !vis[(a[j] ^ a[k])]) {
          goto FUCK;
        }
    ++ans;
    FUCK:;
  }
  cout << ans << endl;
  return 0;
}