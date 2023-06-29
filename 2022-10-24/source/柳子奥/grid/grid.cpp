#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...) 1
#endif
#define file(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

using namespace std;

int n, m, l, q;
vector<vector<int>> k;

namespace Sol1 {

vector<vector<int>> vis;

void bfs(int sx, int sy, int tx, int ty) {
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= m; ++j)
      vis[i][j] = 0;
  vis[sx][sy] = (k[sx][sy] < l);
  for (int i = sx; i <= tx; ++i) {
    for (int j = sy; j <= ty; ++j) {
      if (i == sx && j == sy || k[i][j] >= l) continue ;
      vis[i][j] = (vis[i - 1][j] | vis[i][j - 1]);
    }
  }
  puts(vis[tx][ty] ? "yes" : "no");
}

void sol() {
  vis.resize(n + 1);
  for (int i = 0; i <= n; ++i) vis[i].resize(m + 1);
  for (int cas = 1; cas <= q; ++cas) {
    int op, a, b, c, d, v; cin >> op >> a >> b >> c >> d;
    if (op == 1) {
      cin >> v;
      for (int i = a; i <= c; ++i)
        for (int j = b; j <= d; ++j)
          k[i][j] += v;
    } else {
      bfs(a, b, c, d);
    }
  }
}

} // namespace Sol1

namespace Sol2 {

const int kMaxN = 1e5 + 5;

int mx[kMaxN << 2], tag[kMaxN << 2];

void pushup(int x) {
  mx[x] = max(mx[x << 1], mx[x << 1 | 1]);
}

void addtag(int x, int v) {
  mx[x] += v, tag[x] += v;
}

void pushdown(int x) {
  if (!tag[x]) return ;
  addtag(x << 1, tag[x]), addtag(x << 1 | 1, tag[x]);
  tag[x] = 0;
}

void update(int x, int l, int r, int ql, int qr, int v) {
  if (l > qr || r < ql) {
    return ;
  } else if (l >= ql && r <= qr) {
    return addtag(x, v);
  }
  pushdown(x);
  int mid = (l + r) >> 1;
  update(x << 1, l, mid, ql, qr, v), update(x << 1 | 1, mid + 1, r, ql, qr, v);
  pushup(x);
}

int query(int x, int l, int r, int ql, int qr) {
  if (l > qr || r < ql) {
    return 0;
  } else if (l >= ql && r <= qr) {
    return mx[x];
  }
  pushdown(x);
  int mid = (l + r) >> 1;
  return max(query(x << 1, l, mid, ql, qr), query(x << 1 | 1, mid + 1, r, ql, qr));
}

void sol() {
  for (int cas = 1; cas <= q; ++cas) {
    int op, a, b, c, d, v; cin >> op >> a >> b >> c >> d;
    if (op == 1) {
      cin >> v;
      update(1, 1, m, b, d, v);
    } else {
      puts(query(1, 1, m, b, d) < l ? "yes" : "no");
    }
  }
}

} // namespace Sol2

int main() {
  file("grid");
  cin >> n >> m >> l >> q;
  k.resize(n + 1);
  for (int i = 0; i <= n; ++i) k[i].resize(m + 1);
  if (n <= 300 && m <= 300 && q <= 500) Sol1::sol();
  else if (n == 1) Sol2::sol();
  else Sol1::sol();
  return 0;
}