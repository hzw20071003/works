/*
 * @Author: Lightwhite
 * @Date: 2022-10-24 10:56:26
 * @Last Modified by: Lightwhite
 * @Last Modified time: 2022-10-24 12:06:05
 */
#include <algorithm>
#include <cstring>
#include <fstream>

using namespace std;
using ll = long long;
const int kN = 2e5 + 5;
ifstream fin("grid.in");
ofstream fout("grid.out");

ll tr[kN];
int N, M, L, Q, t1, t2, t[kN], ans[kN], f[kN], g[kN], q[kN];
struct Node {
  int x, l, r, w, i;
} a[kN << 1], b[kN << 1], p[kN << 1], k[kN];
int E(int x, int y) {
  return (x - 1) * M + y;
}
void Up(int x, int w) {
  for (int i = x; i <= M; tr[i] += w, i += i & -i) {
  }
}
ll Que(int x) {
  ll r = 0;
  for (int i = x; i; r += tr[i], i -= i & -i) {
  }
  return r;
}
void _D(int l, int r, int L, int R) {
  if (L > R) {
    return;
  }
  if (l == r) {
    for (int i = L; i <= R; i++) {
      if (!p[i].i) {
        t[E(p[i].x, p[i].l)] = l;
      }
    }
    return;
  }
  int mid = l + r >> 1, t1 = 0, t2 = 0;
  sort(p + L, p + R + 1, [&](Node& p1, Node& p2) {
    return p1.x == p2.x ? p1.i > p2.i : p1.x < p2.x;
  });
  for (int i = L; i <= R; i++) {
    if (p[i].i) {
      if (p[i].i <= mid) {
        Up(p[i].l, p[i].w);
        Up(p[i].r + 1, -p[i].w);
        a[++t1] = p[i];
      } else {
        b[++t2] = p[i];
      }
    } else {
      if (Que(p[i].l) + p[i].w >= ::L) {
        a[++t1] = p[i];
      } else {
        p[i].w += Que(p[i].l);
        b[++t2] = p[i];
      }
    }
  }
  for (int i = L; i <= L + t1 - 1; i++) {
    p[i] = a[i - L + 1];
  }
  for (int i = R; i >= R - t2 + 1; i--) {
    p[i] = b[R - i + 1];
  }
  _D(l, mid, L, L + t1 - 1);
  _D(mid + 1, r, R - t2 + 1, R);
}
void F(int l, int r, int L, int R, int o) {
  if (o == 1) {
    for (int i = L; i >= l; i--) {
      for (int j = R; j >= r; j--) {
        f[E(i, j)] = f[E(i + 1, j)];
        if (j + 1 <= R) {
          f[E(i, j)] = max(f[E(i, j)], f[E(i, j + 1)]);
        }
        f[E(i, j)] = min(f[E(i, j)], t[E(i, j)]);
      }
    }
  } else if (o == 2) {
    for (int i = l; i <= L; i++) {
      for (int j = r; j <= R; j++) {
        f[E(i, j)] = f[E(i - 1, j)];
        if (j - 1 >= r) {
          f[E(i, j)] = max(f[E(i, j)], f[E(i, j - 1)]);
        }
        f[E(i, j)] = min(f[E(i, j)], t[E(i, j)]);
      }
    }
  } else if (o == 3) {
    for (int j = R; j >= r; j--) {
      for (int i = L; i >= l; i--) {
        f[E(i, j)] = f[E(i, j + 1)];
        if (i + 1 <= L) {
          f[E(i, j)] = max(f[E(i, j)], f[E(i + 1, j)]);
        }
        f[E(i, j)] = min(f[E(i, j)], t[E(i, j)]);
      }
    }
  } else if (o == 4) {
    for (int j = r; j <= R; j++) {
      for (int i = l; i <= L; i++) {
        f[E(i, j)] = f[E(i, j - 1)];
        if (i - 1 >= l) {
          f[E(i, j)] = max(f[E(i, j)], f[E(i - 1, j)]);
        }
        f[E(i, j)] = min(f[E(i, j)], t[E(i, j)]);
      }
    }
  }
}
void D(int l, int r, int L, int R, int _l, int _r) {
  if (l > L || r > R || _l > _r) {
    return;
  }
  if (L - l > R - r) {
    int mid = L + l >> 1, t1 = 0, t2 = 0;
    for (int i = _l; i <= _r; i++) {
      if (k[i].x < mid && k[i].r < mid) {
        a[++t1] = k[i];
      } else if (k[i].x > mid && k[i].r > mid) {
        b[++t2] = k[i];
      }
    }
    for (int i = r; i <= R; i++) {
      f[E(mid, i)] = t[E(mid, i)];
      for (int j = i - 1; j >= r; j--) {
        f[E(mid, j)] = min(t[E(mid, j)], f[E(mid, j + 1)]);
      }
      for (int j = i + 1; j <= R; j++) {
        f[E(mid, j)] = 0;
      }
      F(l, r, mid - 1, R, 1);
      for (int j = i - 1; j >= r; j--) {
        g[j] = f[E(mid, j)];
        f[E(mid, j)] = 0;
      }
      for (int j = i + 1; j <= R; j++) {
        f[E(mid, j)] = min(t[E(mid, j)], f[E(mid, j - 1)]);
      }
      F(mid + 1, r, L, R, 2);
      for (int j = i - 1; j >= r; j--) {
        f[E(mid, j)] = g[j];
      }
      for (int j = _l; j <= _r; j++) {
        if (k[j].x <= mid && k[j].r >= mid) {
          ans[k[j].i] = max(ans[k[j].i], min(f[E(k[j].x, k[j].l)], f[E(k[j].r, k[j].w)]));
        }
      }
    }
    for (int i = _l; i <= _l + t1 - 1; i++) {
      k[i] = a[i - _l + 1];
    }
    for (int i = _r; i >= _r - t2 + 1; i--) {
      k[i] = b[_r - i + 1];
    }
    D(l, r, mid - 1, R, _l, _l + t1 - 1);
    D(mid + 1, r, L, R, _r - t2 + 1, _r);
  } else {
    int mid = R + r >> 1, t1 = 0, t2 = 0;
    for (int i = _l; i <= _r; i++) {
      if (k[i].l < mid && k[i].w < mid) {
        a[++t1] = k[i];
      } else if (k[i].l > mid && k[i].w > mid) {
        b[++t2] = k[i];
      }
    }
    for (int i = l; i <= L; i++) {
      f[E(i, mid)] = t[E(i, mid)];
      for (int j = i - 1; j >= l; j--) {
        f[E(j, mid)] = min(t[E(j, mid)], f[E(j + 1, mid)]);
      }
      for (int j = i + 1; j <= L; j++) {
        f[E(j, mid)] = 0;
      }
      F(l, r, L, mid - 1, 3);
      for (int j = i - 1; j >= l; j--) {
        g[j] = f[E(j, mid)];
        f[E(j, mid)] = 0;
      }
      for (int j = i + 1; j <= L; j++) {
        f[E(j, mid)] = min(t[E(j, mid)], f[E(j - 1, mid)]);
      }
      F(l, mid + 1, L, R, 4);
      for (int j = i - 1; j >= l; j--) {
        f[E(j, mid)] = g[j];
      }
      for (int j = _l; j <= _r; j++) {
        if (k[j].l <= mid && k[j].w >= mid) {
          ans[k[j].i] = max(ans[k[j].i], min(f[E(k[j].x, k[j].l)], f[E(k[j].r, k[j].w)]));
        }
      }
    }
    for (int i = _l; i <= _l + t1 - 1; i++) {
      k[i] = a[i - _l + 1];
    }
    for (int i = _r; i >= _r - t2 + 1; i--) {
      k[i] = b[_r - i + 1];
    }
    D(l, r, L, mid - 1, _l, _l + t1 - 1);
    D(l, mid + 1, L, R, _r - t2 + 1, _r);
  }
}
int main() {
  ios ::sync_with_stdio(false);
  fin.tie(0), fout.tie(0);

  fin >> N >> M >> L >> Q;
  for (int i = 1, o; i <= Q; i++) {
    fin >> o;
    if (o == 1) {
      int a, b, c, d, w;
      fin >> a >> b >> c >> d >> w;
      p[++t1].x = a;
      p[t1].l = p[t1 + 1].l = b;
      p[++t1].x = c + 1;
      p[t1].r = p[t1 - 1].r = d;
      p[t1 - 1].w = w;
      p[t1].w = -p[t1 - 1].w;
      p[t1].i = p[t1 - 1].i = i;
    } else {
      int a, b, c, d;
      fin >> a >> b >> c >> d;
      k[++t2].x = a;
      k[t2].l = b;
      k[t2].r = c;
      k[t2].w = d;
      k[t2].i = t2;
      q[t2] = i;
    }
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      p[++t1] = {i, j, 0, 0, 0};
    }
  }
  _D(1, Q, 1, t1);
  D(1, 1, N, M, 1, t2);
  for (int i = 1; i <= t2; i++) {
    fout << (ans[i] < q[i] ? "no" : "yes") << '\n';
  }
  return 0;
}