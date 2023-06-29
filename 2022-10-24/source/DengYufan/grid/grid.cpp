#include <iostream>
#define LL long long

using namespace std;

LL n, m, l, q, a[100001];
bool b[100001];
pair<LL, LL> d[100001];

LL P(LL x, LL y) {
  return (x - 1) * m + y;
}

void Pushdown(LL p, LL l, LL r) {
  LL mid = l + r >> 1;
  if (d[p].second) {
    d[p * 2].first += d[p].second;
    d[p * 2 + 1].first += d[p].second;
    d[p * 2].second += d[p].second;
    d[p * 2 + 1].second += d[p].second;
    d[p].second = 0;
  }
}

void Add(LL p, LL l, LL r, LL _l, LL _r, LL k) {
  if (l >= _l && r <= _r) {
    d[p].first += k, d[p].second += k;
    return;
  }
  LL mid = l + r >> 1;
  Pushdown(p, l, r);
  if (mid >= _l) {
    Add(p * 2, l, mid, _l, _r, k);
  }
  if (mid < _r) {
    Add(p * 2 + 1, mid + 1, r, _l, _r, k);
  }
  d[p].first = max(d[p * 2].first, d[p * 2 + 1].first);
}

LL Ask(LL p, LL l, LL r, LL _l, LL _r) {
  if (l >= _l && r <= _r) {
    return d[p].first;
  }
  LL mid = l + r >> 1, ans = 0;
  Pushdown(p, l, r);
  if (mid >= _l) {
    ans = max(ans, Ask(p * 2, l, mid, _l, _r));
  }
  if (mid < _r) {
    ans = max(ans, Ask(p * 2 + 1, mid + 1, r, _l, _r));
  }
  return ans;
}

int main() {
  freopen("grid.in", "r", stdin);
  freopen("grid.out", "w", stdout);
  cin >> n >> m >> l >> q;
  if (n == 1) {
    for (LL i = 1, o, x1, y1, x2, y2, k; i <= q; i++) {
      cin >> o >> x1 >> y1 >> x2 >> y2;
      if (o == 1) {
        cin >> k;
        Add(1, 1, m, y1, y2, k);
      } else {
        cout << (Ask(1, 1, m, y1, y2) < l ? "yes\n" : "no\n");
      }
    }
  } else {
    for (LL i = 1, o, x1, y1, x2, y2, k; i <= q; i++) {
      cin >> o >> x1 >> y1 >> x2 >> y2;
      if (o == 1) {
        cin >> k;
        for (LL x = x1; x <= x2; x++) {
          for (LL y = y1; y <= y2; y++) {
            a[P(x, y)] += k;
          }
        }
      } else if (o == 2) {
        for (LL x = x1; x <= x2; x++) {
          b[P(x, y1 - 1)] = 0;
        }
        for (LL y = y1; y <= y2; y++) {
          b[P(x1 - 1, y)] = 0;
        }
        for (LL x = x1; x <= x2; x++) {
          for (LL y = y1; y <= y2; y++) {
            b[P(x, y)] = (b[P(x - 1, y)] || b[P(x, y - 1)] || x == x1 && y == y1) && a[P(x, y)] < l;
          }
        }
        cout << (b[P(x2, y2)] ? "yes\n" : "no\n");
      }
    }
  }
  return 0;
}
