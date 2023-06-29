#include <algorithm>
#include <iostream>

using namespace std;

pair<int, int> num[300001];
int n, k, tmp, Last;
long long ans;

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> num[i].first >> num[i].second;
  }
  sort(num + 1, num + n + 1);
  num[0] = {-1, -1};
  for (int i = 1; i <= n; i++) {
    if (num[i].first != num[i - 1].first) {
      tmp = k;
      ans += min(tmp, Last);
      tmp = max(tmp - Last, 0);
      Last = 0;
      if(num[i].first - num[i - 1].first > 1) {
        tmp = k;
      }
    }
    ans += min(tmp, num[i].second);
    Last += max(num[i].second - tmp, 0);
    tmp = max(tmp - num[i].second, 0);
  }
  cout << ans + min(k, Last) << endl;
  return 0;
}