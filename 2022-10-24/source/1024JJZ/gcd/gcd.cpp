/*
 * @Author: Lightwhite 
 * @Date: 2022-10-24 08:46:21
 * @Last Modified by: Lightwhite
 * @Last Modified time: 2022-10-24 11:49:53
 */
#include <fstream>
#include <numeric>

using namespace std;
const int kN = 1e5 + 5;

ifstream fin("gcd.in");
ofstream fout("gcd.out");
long long ans;
int n, m, a[kN], b[kN], f[kN];
int R(int x) {
  return f[x] == x ? x : f[x] = R(f[x]);
}
int main() {
  ios ::sync_with_stdio(false);
  fin.tie(0), fout.tie(0);

  fin >> n;
  for (int i = 1; i <= n; i++) {
    fin >> a[i];
    m = max (m, a[i]);
    if (!b[a[i]]) {
      b[a[i]] = i;
    } else {
      ans += a[i];
    }
  }
  iota(f + 1, f + n + 1, 1);
  for (int i = m, r = 0; i; i--, r = 0) {
    for (int j = 1; i * j <= m; j++) {
      if (!b[i * j]) {
        continue;
      }
      int fa = R(b[i * j]);
      if (!r) {
        r = fa;
      } else if (r != fa) {
        ans += i;
        f[fa] = r;
      }
    }
  }
  fout << ans << '\n';
  return 0;
}