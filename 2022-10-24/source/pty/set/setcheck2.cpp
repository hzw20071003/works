#include <algorithm>
#include <iostream>

using namespace std;

const int kL = 30, kM = 1e9 + 7;

int w[kL * kL] = {1}, a[kL + 1], n, ans;

void C(int t) {
  a[t] = -1;
  long long r = 1;
  for (int i = 1; i < t; i++) {
    r = r * w[(a[i] - a[i + 1] - 1) * i] % kM;
  }
  ans = (ans + r) % kM;
}

void S(int i, int v, int t) {
  if (v > n) {
    return;
  }
  if (i < 0) {
    C(t);
    return;
  }
  S(i - 1, v, t);
  if (t) {
    S(i - 1, v + (1 << i), t);
  }
  a[t] = i;
  S(i - 1, v + (1 << i), t + 1);
}

int main() {
  for (int i = 1; i < kL * kL; i++) {
    w[i] = w[i - 1] * 2 % kM;
  }
  cin >> n;
  S(kL - 1, 0, 0);
  cout << ans;
  return 0;
}