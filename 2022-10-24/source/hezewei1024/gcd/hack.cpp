#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct hack {
  int x, y, num;
} tmp;

auto cmp = [](hack a, hack b) {
  return a.num < b.num;
};

int n, ans, a[100001], f[100001];
priority_queue<hack, vector<hack>, decltype(cmp)> q(cmp);

int gcd(int a, int b) {
  return a == 0 ? b : (gcd(b % a, a));
}

int FindF(int x) {
  return x == f[x] ? f[x] : (f[x] = FindF(f[x]));
}

void Find() {
  for (int i = 1; i < n; i++) {
    tmp = q.top();
    while (FindF(tmp.x) == FindF(tmp.y)) {
      q.pop();
      tmp = q.top();
    }
    ans += tmp.num;
    f[FindF(tmp.x)] = FindF(tmp.y);
  }
}

int main() {
  freopen("gcd.in", "r", stdin);
  freopen("1.out", "w", stdout);
  cin >> n;
  for (int i = 0; i < n; i++) {
    f[i] = i;
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      tmp.x = i;
      tmp.y = j;
      tmp.num = gcd(a[i], a[j]);
      q.push(tmp);
    }
  }
  Find();
  cout << ans << endl;
  return 0;
}