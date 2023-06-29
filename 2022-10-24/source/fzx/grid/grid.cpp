#define fastcall __attribute__((optimize("-O3")))
#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
#define RF(s) freopen(s ".in", "r", stdin), freopen(s ".out", "w", stdout)

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

int n, m, l, q;
namespace eq1 {  // n = 1
const int kN = 1e5 + 1;

struct E {
  LL m, t;
} e[kN << 2];

void A(int x, LL v) { e[x].m += v, e[x].t = v; }
LL Do(int x, int l, int r, int tl, int tr, LL v) {
  if (l == tl && r == tr) {
    A(x, v);
    return e[x].m;
  }
  A(x * 2, e[x].t), A(x * 2 + 1, e[x].t), e[x].t = 0;
  int m = l + r >> 1;
  LL s = 0;
  if (tl <= m) {
    s = max(s, Do(x * 2, l, m, tl, min(m, tr), v));
  }
  if (m < tr) {
    s = max(s, Do(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, v));
  }
  return s;
}
void S() {
  for (int o, x0, y0, x1, y1, v; q--;) {
    cin >> o >> x0 >> y0 >> x1 >> y1;
    if (o == 1) {
      cin >> v;
      Do(1, 1, m, y0, y1, v);
    } else {
      cout << (Do(1, 1, m, y0, y1, 0) < l ? "yes" : "no") << '\n';
    }
  }
}
}  // namespace eq1
namespace brute {
void S() {
  LL a[n + 1][m + 1];
  fill(a[1] + 1, a[n + 1], 0);
  bool f[n + 1][m + 1];
  for (int o, x0, y0, x1, y1, v; q--;) {
    cin >> o >> x0 >> y0 >> x1 >> y1;
    if (o == 1) {
      cin >> v, ++x1, ++y1;
      for (int x = x1; x <= n; x += x & -x) {
        for (int y = y1; y <= m; y += y & -y) {
          a[x][y] += v;
        }
      }
      for (int x = x0; x <= n; x += x & -x) {
        for (int y = y0; y <= m; y += y & -y) {
          a[x][y] += v;
        }
      }
      for (int x = x0; x <= n; x += x & -x) {
        for (int y = y1; y <= m; y += y & -y) {
          a[x][y] -= v;
        }
      }
      for (int x = x1; x <= n; x += x & -x) {
        for (int y = y0; y <= m; y += y & -y) {
          a[x][y] -= v;
        }
      }
    } else {
      for (int i = x0; i <= x1; ++i) {
        for (int j = y0; j <= y1; ++j) {
          LL s = 0;
          for (int x = i; x; x -= x & -x) {
            for (int y = j; y; y -= y & -y) {
              s += a[x][y];
            }
          }
          if (i == x0 && j == y0) {
            f[i][j] = s < l;
          } else {
            f[i][j] = s < l && (i > x0 && f[i - 1][j] || j > y0 && f[i][j - 1]);
          }
        }
      }
      cout << (f[x1][y1] ? "yes" : "no") << '\n';
    }
    // for (int i = 1; i <= n; ++i) {
    //   for (int j = 1; j <= m; ++j) {
    //     LL s = 0;
    //     for (int x = i; x; x -= x & -x) {
    //       for (int y = j; y; y -= y & -y) {
    //         s += a[x][y];
    //       }
    //     }
    //     cerr << s << ' ';
    //   }
    //   cerr << '\n';
    // }
  }
}
}  // namespace brute

int main() {
  RF("grid");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> l >> q;
  if (n == 1) {
    eq1::S();
    return 0;
  }
  brute::S();
  return 0;
}