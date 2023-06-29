#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, ans;

bool C(int s) {
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if ((s >> i & 1) && (s >> j & 1)) {
        if ((i ^ j) >= n || !(s >> (i ^ j) & 1)) {
          return 0;
        }
      }
    }
  }
  return 1;
}

void P(int s) {
  vector<int> a;
  cout << s << '\n';
  while (1) {
    int i;
    for (i = n - 1; i >= 0 && !(s >> i & 1); i--) {
    }
    if (i < 0) {
      break;
    }
    a.push_back(s);
    for (int j = 10; j >= 0; j--) {
      cout << (i >> j & 1);
    }
    cout << '\n';
    s ^= 1 << i;
    for (int j = 0; j < n - 1; j ++) {
      if ((s >> j & 1) && ((i ^ j) < j)) {
        s = (s ^ (1 << j)) | (1 << (i ^ j));
      }
    }
  }
  cout << "---------\n";
  for (int i = 1; i < a.size(); i++) {
    if ((a[i] & a[i - 1]) != a[i]) {
      cout << "shit";
    }
  }
}

int main() {
  // freopen("output.txt", "w", stdout);
  cin >> n, n++;
  for (int i = 1; i < 1 << n; i++) {
    if (C(i)) {
      ans++;
      // P(i);
    }
  }
  cout << ans;
  return 0;
}