#include <algorithm>
#include <fstream>

using namespace std;

ifstream fin("set.in");
ofstream fout("set.out");

const int kL = 30, kM = 1e9 + 7;

int f[kL][2][kL + 1], n, ans;

int S(int i, bool top, int c) {
  if (i < 0) {
    return 1;
  }
  if (f[i][top][c]) {
    return f[i][top][c];
  }
  f[i][top][c] = (1LL << max(c - 1, 0)) * S(i - 1, top && !(n >> i & 1), c) % kM;
  if (!top || (n >> i & 1)) {
    if (c) {
      f[i][top][c] = (f[i][top][c] + (1LL << c - 1) * S(i - 1, top, c)) % kM;
    }
    f[i][top][c] = (f[i][top][c] + S(i - 1, top, c + 1)) % kM;
  }
  return f[i][top][c];
}

int main() {
  fin >> n;
  fout << S(kL - 1, 1, 0);
  return 0;
}