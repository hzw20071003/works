#include <cstdio>
#include <iostream>

using namespace std;

short n, a, b;
short p[2001], c[2001], x[2001];
int dp[2001][2001];

int read() {
  int x(0);
  char ch(getchar());
  while ('0' <= ch && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch - '0');
    ch = getchar();
  }
  return x;
}

int main() {
  n = read(), a = read(), b = read();
  for (short i = 0; i < n; i++) {
    p[i] = read(), c[i] = read(), x[i] = read();
  }
  for (int i = 0; i < n; i++) {
    c[i]--;
    for (short j(a); j >= c[i]; j--) {
      for (short k(b); k >= x[i]; k--) {
        dp[j][k] = max(dp[j][k], p[i] + dp[j - c[i]][k]);
      }
    }
    c[i]++;
    for (short j(a); j >= c[i]; j--) {
      for (short k(x[i] - 1); k >= 0; k--) {
        dp[j][k] = max(dp[j][k], p[i] + dp[j - c[i]][k]);
      }
    }
  }
  printf("%d", dp[a][b]);
  return 0;
}