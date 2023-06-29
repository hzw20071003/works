/*
 * @Author: Lightwhite 
 * @Date: 2022-10-24 09:25:04 
 * @Last Modified by: Lightwhite
 * @Last Modified time: 2022-10-24 10:07:03
 */
#include <algorithm>
#include <cstring>
#include <fstream>

using namespace std;
using ll = long long;
const int kN = 33, kM = 1e9 + 7;
ifstream fin("set.in");
ofstream fout("set.out");

int n;
ll f[kN][kN][2], ans;
int main() {
  ios ::sync_with_stdio(false);
  fin.tie(0), fout.tie(0);

  fin >> n;
  f[kN - 1][0][1] = 1;
  for (int i = kN - 1; i; i--) {
    for (int j = 0; j < kN - i; j++) {
      for (int p = 0, q; p < 2; p++) {
        if (f[i][j][p]) {
          q = p && ((n & (1 << i - 2)) == 0);
          (f[i - 1][j][q] += f[i][j][p] * max(1, (1 << j) >> 1) % kM) %= kM;
          if (p && ((n & (1 << i - 2)) == 0)) {
            continue;
          }
          q = p && ((n & (1 << i - 2)) != 0);
          (f[i - 1][j][q] += f[i][j][p] * ((1 << j) >> 1) % kM) %= kM;
          (f[i - 1][j + 1][q] += f[i][j][p]) %= kM;
        }
      }
    }
  }
  for (int i = 0; i < kN - 1; i++) {
    (ans += (f[1][i][0] + f[1][i][1]) % kM) %= kM;  
  }
  fout << ans << '\n';
  return 0;
}