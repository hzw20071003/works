#include <iostream>

using namespace std;

int t, n, x, p;
bool b;

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> x >> p;
    for (int i = 0; i < n * 2; i++) {
      x += i;
      x %= n;
      if (n == 0) {
        b = 1;
        break;
      }
    }
    cout << (b ? "YES" : "NO") << endl;
  }
  return 0;
}