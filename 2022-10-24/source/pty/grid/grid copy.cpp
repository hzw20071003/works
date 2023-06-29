#include <algorithm>
#include <fstream>
#include <queue>

using namespace std;
using Pii = pair<int, int>;

ifstream fin("grid.in");
ofstream fout("grid.out");

const int kMaxN = 301, kMaxL = 1e5 + 1;

struct T {
  int l, r, v, _v, b;
} t[kMaxL * 4];
bool f[kMaxN][kMaxL];
int n, m, limit, q, o, x[2], y[2], v, flip, tot, tr[kMaxN];

// ==========================================================================================
void C1() {
  int a[kMaxN][kMaxN], f[kMaxN][kMaxN];
  fill(a[0], a[kMaxN], 0);
  while (q--) {
    fin >> o >> x[0] >> y[0] >> x[1] >> y[1];
    if (o == 1) {
      fin >> v;
      for (int i = x[0]; i <= x[1]; i++) {
        for (int j = y[0]; j <= y[1]; j++) {
          a[i][j] = min(a[i][j] + v, limit);
        }
      }
    } else {
      for (int i = x[0]; i <= x[1]; i++) {
        for (int j = y[0]; j <= y[1]; j++) {
          f[i][j] = a[i][j] < limit && ((i == x[0] && j == y[0]) || (i > x[0] && f[i - 1][j]) || (j > y[0] && f[i][j - 1]));
        }
      }
      fout << (f[x[1]][y[1]] ? "yes\n" : "no\n");
    }
  }
}

// ==========================================================================================
void Add(Pii t[], int i, int l, int r, int tl, int tr) {
  if (l == tl && r == tr) {
    t[i].first = min(t[i].first + v, limit), t[i].second = min(t[i].second + v, limit);
    return;
  }
  int m = (tl + tr) / 2;
  if (tl <= m) {
    Add(t, i * 2, l, m, tl, min(tr, m));
  }
  if (tr > m) {
    Add(t, i * 2 + 1, m + 1, r, max(m + 1, tl), tr);
  }
}

int Max(Pii t[], int i, int l, int r, int tl, int tr) {
  if (l == tl && r == tr) {
    return t[i].second;
  }
  int m = (tl + tr) / 2, ans = 0;
  if (tl <= m) {
    ans = max(ans, Max(t, i * 2, l, m, tl, min(tr, m)));
  }
  if (tr > m) {
    ans = max(ans, Max(t, i * 2 + 1, m + 1, r, max(m + 1, tl), tr));
  }
  return min(ans + t[i].first, limit);
}

void C2() {
  Pii t[kMaxL * 4];
  fill(t, t + kMaxL * 4, make_pair(0, 0));
  while (q--) {
    fin >> o >> x[0] >> y[0] >> x[1] >> y[1];
    if (o == 1) {
      fin >> v;
      Add(t, 1, 1, m, y[0], y[1]);
    } else {
      fout << (Max(t, 1, 1, m, y[0], y[1]) < limit ? "yes\n" : "no\n");
    }
  }
}
// ==========================================================================================

void Build(int &i, int l, int r) {
  i = ++tot;
  if (l < r) {
    int m = (l + r) / 2;
    Build(t[i].l, l, m), Build(t[i].r, m + 1, r);
  }
}

void Dis(int x, int y) {
  if (x > n || y > m || !f[x][y]) {
    return;
  }
  f[x][y] = f[x - 1][y] || f[x][y - 1];
  if (!f[x][y]) {
    Dis(x + 1, y), Dis(x, y + 1);
  }
}

void A(int x, int i, int l, int r, int v) {
  t[i].v = min(t[i].v + v, limit), t[i]._v = min(t[i]._v + v, limit);
  if (t[i]._v >= limit && !t[i].b) {
    t[i].b = 1;
    for (int y = l; y <= r; y++) {
      f[x][y] = 0;
      Dis(x + 1, y), Dis(x, y + 1);
    }
  }
}

void Add(int x, int i, int l, int r, int tl, int tr) {
  if (l == tl && r == tr) {
    A(x, i, l, r, v);
    return;
  }
  int m = (l + r) / 2;
  if (t[i].v) {
    A(x, t[i].l, l, m, t[i].v), A(x, t[i].r, m + 1, r, t[i].v);
    t[i].v = 0;
  }
  if (tl <= m) {
    Add(x, t[i].l, l, m, tl, min(m, tr));
  }
  if (tr > m) {
    Add(x, t[i].r, m + 1, r, max(m + 1, tl), tr);
  }
}

int main() {
  ios::sync_with_stdio(0), fin.tie(0);
  fin >> n >> m >> limit >> q;
  if (n <= 300 && m <= 300 && q <= 500) {
    C1();
  } else if (n == 1) {
    C2();
  } else {
    if (n > m) {
      swap(n, m), flip = 1;
    }
    for (int i = 1; i <= n; i++) {
      Build(tr[i], 1, m);
      fill(f[i], f[i] + m + 1, 1);
    }
    while (q--) {
      fin >> o >> x[0] >> y[0] >> x[1] >> y[1];
      if (flip) {
        swap(x[0], y[0]), swap(x[1], y[1]);
      }
      if (o == 1) {
        fin >> v;
        for (int i = x[0]; i <= x[1]; i++) {
          Add(i, tr[i], 1, m, y[0], y[1]);
        }
      } else {
        fout << (f[x[1]][y[1]] ? "yes\n" : "no\n");
      }
    }
  }
  return 0;
}