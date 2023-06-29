# include <stdio.h>

using namespace std;

int s, n;
int ans;
int ck() {
  int mx = 0;
  for (int i = 0; i < n; i++) {
    if ((s >> i) & 1) {
      mx = i;
    }
    for (int j = 0; j < n; j++) {
      if (((s >> i) & 1) && ((s >> j) & 1) && !((s >> (i ^ j)) & 1)) {
        return -1;
      }
    }
  }
  // if (mx == 0) {
  //   printf("!!!%d\n", s);
  // }
  return mx;
}

int main() {
  freopen("set.in", "r", stdin);
  freopen("set.out", "w", stdout);
  scanf("%d", &n);
  n++;
  for (int i = 1; i < (1 << n); i++) {
    s = i;
    int mx = ck();
    if (mx >= 0) {
      ans++;
    }
  }
    printf("%d\n", ans);
}
/*


00000  1
00001  1
00010  1
00011  2
00100  1
00101  2
00110  3
00111  5
01000  1
01001  2
01010  3
01011  5
01100  5
01101  8
01110  11
01111  16
10000  1
10001  2
10010  3
10011  5


1
1
1
2
1
2
3
5
1
2
3
5
5
8
11
16
1
2
3
5
5
8
11
16
9
14
19
27
29
40


*/