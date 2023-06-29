#include <iostream>

using namespace std;

const int kMod = 1e9 + 7;
int n, ans;
bool b[100001];

bool Chick() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (b[i] && b[j] && !b[i ^ j]) {
        return 0;
      }
    }
  }
  return 1;
}

void S(int x) {
  if (x > n) {
    ans = (ans + Chick()) % kMod;
    return;
  }
  b[x] = 1;
  S(x + 1);
  b[x] = 0;
  S(x + 1);
}

int main() {
  freopen("set.in", "r", stdin);
  freopen("set.out", "w", stdout);
  cin >> n;
  S(0);
  cout << (ans + kMod - 1) % kMod;
  return 0;
}
