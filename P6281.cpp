#include <algorithm>
#include <iostream>

using namespace std;

const int kMaxN = 1e5 + 1;
const long long kMax = 1e18 + 1;

int n, m;
long long l = 1, r = kMax, mid;
pair<int, int> p[kMaxN];

bool Check(long long x) {
  long long Start = -x, num = n;
  for (int i = 0; i < m; i++) {
    if (Start + x <= p[i].first) {
      Start = p[i].first;
      num--;
    }
    while (Start + x <= p[i].second && num) {
      Start += x;
      num--;
    }
  }
  return num <= 0;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> p[i].first >> p[i].second;
  }
  sort(p, p + m);
  while (l < r) {
    mid = ((l + r) >> 1) + 1;
    Check(mid) ? l = mid : r = mid - 1;
  }
  cout << l;
  return 0;
}