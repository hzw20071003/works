// easy version
#include <iostream>

using namespace std;

const int kMaxN = 1e5 + 1;
int t, n, k;
int a[kMaxN], hot[kMaxN], cold[kMaxN], dp[kMaxN][kMaxN];

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < k; i++) {
      cin >> cold[i];
    }
    for (int i = 0; i < k; i++) {
      cin >> hot[i];
    }
    
  }
  return 0;
}