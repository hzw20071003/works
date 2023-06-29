#include <cmath>
#include <iostream>

using namespace std;

long long t, q, type, a, b, n, l, r, tmp_l, tmp_r;
bool B;

int main() {
  cin >> t;
  while (t--) {
    B = 0;
    cin >> q;
    while (q--) {
      cin >> type;
      if (type == 1) {
        cin >> a >> b >> n;
        if (!B) {
          B = 1;
          cout << 1 << ' ';
          if (n == 1) {
            l = 0;
            r = a;
          } else {
            l = a + (a - b) * (n - 2);
            r = a + (a - b) * (n - 1);
          }
        } else {
          if (n == 1) {
            tmp_l = 0;
            tmp_r = a;
          } else {
            tmp_l = a + (a - b) * (n - 2);
            tmp_r = a + (a - b) * (n - 1);
          }
          if (l < tmp_r && tmp_l < r) {
            cout << 1 << ' ';
            l = max(tmp_l, l);
            r = min(tmp_r, r);
          } else {
            cout << 0 << ' ';
          }
        }
      } else {
        cin >> a >> b;
        if (a >= r || ceil((float)(l + 1 - a) / (a - b)) == ceil((float)(r - a) / (a - b))) {
          cout << max((long long)ceil((float)(r - a) / (a - b)) + 1, (long long)1) << ' ';
        } else {
          cout << -1 << ' ';
        }
      }
    }
    cout << endl;
  }
  return 0;
}