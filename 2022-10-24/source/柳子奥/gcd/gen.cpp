#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...) 1
#endif
#define file(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

using namespace std;

mt19937 rnd(time(0));

int main() {
  srand(time(0));
  freopen("gcd.in", "w", stdout);
  int n = 100000;
  cout << n << endl;
  for (int i = 1; i <= n; ++i) {
    cout << 44100 << ' ';
    // cout << llabs(rand() * rand()) % n + 1 << ' ';
    // cout << 44100 << ' ';
    // cout << rnd() % 100000 + 1 << ' ';
  }
  return 0;
}