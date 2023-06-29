# include <stdio.h>

using namespace std;

long long ans = 0;
int n, a[100100];
int f[100100];
int t[100100];

int fi(int x) {
  return f[x] == x ? x : f[x] = fi(f[x]);
}

void ji(int x, int y, int v) {
  int fx = fi(x);
  int fy = fi(y);
  if (fx != fy) {
    f[fx] = fy;
    ans += v;
  }
}

int main() {
  freopen("gcd.in", "r", stdin);
  freopen("gcd.out", "w", stdout);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    if (t[a[i]]++) {
      ans += a[i];
    }
  }
  for (int i = 1; i <= 100000; i++) {
    f[i] = i;
  }
  for (int i = 50000; i >= 1; i--) {
    for (int j = i + i, lt = i; j <= 100000; j += i) {
      if (t[j] == 0) {
        continue;
      }
      if (t[lt] == 0) {
        lt = j;
        continue;
      }
      ji(lt, j, i);
    }
  }
  printf("%lld", ans);
}