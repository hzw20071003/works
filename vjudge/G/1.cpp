#include <iostream>

using namespace std;

const int kMaxN = 1e6 + 1;
int t, T, n, k, d, w, Now, Last, ans;

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> k >> d >> w;
    for (int i = 0; i < n; i++) {
      cin >> T;
      if(Now == 0 || Last < T) {
        ans++;
        Last = T + w + d;
        Now = k - 1;
      } else {
        Now--;
      }
    }
    cout << ans << endl;
    ans = Now = Last = 0;
  }
  return 0;
}