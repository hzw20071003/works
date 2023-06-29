# include <stdio.h>

using namespace std;

int n, m, l, q, s[555][555], f[555][555];
int t, a, b, c, d, v;

int main() {
  freopen("grid.in", "r", stdin);
  freopen("grid.out", "w", stdout);
  scanf("%d%d%d%d", &n, &m, &l, &q);
  while (q--) {
    scanf("%d%d%d%d%d", &t, &a, &b, &c, &d);
    if (t == 1) {
      scanf("%d", &v);
      for (int i = a; i <= c; i++) {
        for (int j = b; j <= d; j++) {
          if(s[i][j] < l) {
            s[i][j] += v;
          }
        }
      }
    } else {
      for (int i = a; i <= c; i++) {
        for (int j = b; j <= d; j++) {
          if(s[i][j] < l) {
            if (i == a && j == b) {
              f[i][j] = 1;
            } else if (i == a) {
              f[i][j] = f[i][j - 1];
            } else if (j == b) {
              f[i][j] = f[i - 1][j];
            } else {
              f[i][j] = (f[i - 1][j] | f[i][j - 1]);
            }
          } else {
            f[i][j] = 0;
          }
        }
      }
      printf("%s\n", f[c][d] ? "yes" : "no");
    }
  }
}

/*

3 4 5 6
1 1 2 2 4 3
1 2 2 3 3 2
2 2 1 3 4
1 3 1 3 3 3
2 1 2 3 4
2 2 1 3 4

*/