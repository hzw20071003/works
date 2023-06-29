#include <algorithm>
#include <iostream>
#include <vector>
#define LL long long

using namespace std;

struct E {
  LL x, y, z;
};
LL n, ans, a[1001], f[1001];
vector<E> e;

LL Gcd(LL x, LL y) {
  return y ? Gcd(y, x % y) : x;
}

LL GetRoot(LL x) {
  return f[x] == x ? x : f[x] = GetRoot(f[x]);
}

int main() {
  freopen("gcd.in", "r", stdin);
  freopen("gcd.ans", "w", stdout);
  cin >> n;
  for (LL i = 1; i <= n; i++) {
    cin >> a[i];
    f[i] = i;
  }
  for (LL i = 1; i <= n; i++) {
    for (LL j = i + 1; j <= n; j++) {
      e.push_back({i, j, Gcd(a[i], a[j])});
    }
  }
  sort(e.begin(), e.end(), [](E i, E j) { return i.z > j.z; });
  for (E i : e) {
    if (GetRoot(i.x) != GetRoot(i.y)) {
      f[GetRoot(i.x)] = GetRoot(i.y);
      ans += i.z;
    }
  }
  cout << ans;
  return 0;
}
