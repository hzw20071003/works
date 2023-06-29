#pragma GCC optimize(2)
#pragma GCC optimize("inline")
#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...) 1
#endif
#define file(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

using namespace std;

int n;
int a[100005];

namespace Sol1 {

const int kMaxN = 405;

struct Edge {
  int u, v, w;
} ed[kMaxN * kMaxN];

int m, fa[kMaxN];

int find(int x) {
  return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void unionn(int x, int y) {
  int fx = find(x), fy = find(y);
  if (fx != fy) fa[fx] = fy;
}

void sol() {
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      ed[++m] = {i, j, __gcd(a[i], a[j])};
    }
  }
  sort(ed + 1, ed + 1 + m, [](Edge a, Edge b) { return a.w > b.w; });
  for (int i = 1; i <= n; ++i) fa[i] = i;
  long long res = 0, cnt = 0;
  for (int i = 1; i <= m; ++i) {
    int u = ed[i].u, v = ed[i].v, w = ed[i].w;
    if (find(u) != find(v)) {
      unionn(u, v);
      res += w;
      if (++cnt == n - 1) break ;
    }
  }
  cout << res << endl;
}

} // namespace Sol1

namespace Sol2 {

const int kMaxN = 1e5 + 5;

int cnt1[kMaxN], cnt2[kMaxN];
multiset<int> s, idx[kMaxN];

void sol() {
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j * j <= a[i]; ++j) {
      if (a[i] % j == 0) {
        idx[j].emplace(a[i]), ++cnt2[j];
        if (j * j != a[i]) idx[a[i] / j].emplace(a[i]), ++cnt2[a[i] / j];
      }
    }
  }
  for (int i = 1; i * i <= a[1]; ++i) {
    if (a[1] % i == 0) {
      ++cnt1[i];
      if (i * i != a[1]) ++cnt1[a[1] / i];
    }
  }
  for (int i = 1; i <= 1e5; ++i) {
    if (cnt1[i] && cnt2[i]) s.emplace(-i);
  }
  long long res = 0;
  for (int i = 2; i <= n; ++i) {
    int d = -(*s.begin()), x = *idx[d].begin();
    res += d;
    // assert(idx[d].size());
    // cerr << d << ' ' << x << endl;
    for (int j = 1; j * j <= x; ++j) {
      if (x % j == 0) {
        idx[j].erase(idx[j].lower_bound(x));
        if (!--cnt2[j] && cnt1[j]) s.erase(-j);
        if (j * j != x) {
          idx[x / j].erase(idx[x / j].lower_bound(x));
          if (!--cnt2[x / j] && cnt1[x / j]) s.erase(-x / j);
        }
//=======================
        if (!(cnt1[j]++) && cnt2[j]) s.emplace(-j);
        if (j * j != x && !(cnt1[x / j]++) && cnt2[x / j]) s.emplace(-x / j);
      }
    }
    // for (int j = 1; j <= 5; ++j) cerr << cnt1[j] << ' ';
    // cerr << endl;
    // for (int j = 1; j <= 5; ++j) cerr << cnt2[j] << ' ';
    // cerr << endl;
  }
  cout << res << endl;
  cerr << 1.0 * clock() / CLOCKS_PER_SEC << 's' << endl;
}

} // namespace Sol2

int main() {
  file("gcd");
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  if (n <= 400) Sol1::sol();
  else Sol2::sol();
  return 0;
}