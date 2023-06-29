#include <iostream>
#include <vector>
#define LL long long

using namespace std;

const LL kMaxN = 1e5 + 1;
LL n, ans, f[kMaxN];
vector<LL> v[kMaxN];

LL GetRoot(LL x) {
  return f[x] == x ? x : f[x] = GetRoot(f[x]);
}

int main() {
  freopen("gcd.in", "r", stdin);
  freopen("gcd.out", "w", stdout);
  cin >> n;
  for (LL i = 1, x; i <= n; i++) {
    cin >> x;
    v[x].push_back(i), f[i] = i;
  }
  for (LL i = kMaxN - 1; i >= 1; i--) {
    for (LL j = i, p = 0; j < kMaxN; j += i) {
      for (LL k : v[j]) {
        if (p && GetRoot(p) != GetRoot(k)) {
          ans += i, f[GetRoot(p)] = GetRoot(k);
        }
        p = k;
      }
    }
  }
  cout << ans;
  return 0;
}
