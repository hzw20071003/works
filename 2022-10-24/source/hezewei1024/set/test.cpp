#include <iostream>
#include <vector>

using namespace std;

int ans, n;
short b[10001];
vector<int> v;

void Find(int x, short b[]) {
  if (x > n) {
    ans++;
    return;
  }
  if (b[x]) {
    v.push_back(x);
    for (auto i : v) {
      if (!b[i ^ x]) {
        if ((i ^ x) < x || (i ^ x) > n) {
          for (int i = v.size() - 1; v[i] >= x; i--) {
            b[v[i]]--;
            v.pop_back();
          }
          return;
        } else {
          b[i ^ x]++;
        }
      }
    }
  }
  Find(x + 1, b);
  if (!b[x]) {
    v.push_back(x);
    for (auto i: v) {
      if (!b[i ^ x]) {
        if ((i ^ x) < x || (i ^ x) > n) {
          for (int i = v.size() - 1; v[i] >= x; i--) {
            b[v[i]]--;
            v.pop_back();
          }
          return;
        } else {
          b[i ^ x]++;
        }
      }
    }
    Find(x + 1, b);
    for (int i = v.size() - 1; v[i] >= x; i--) {
      b[v[i]]--;
      v.pop_back();
    }
  }
}

int main() {
  freopen("set.in", "r", stdin);
  freopen("set.out", "w", stdout);
  cin >> n;
  v.push_back(0);
  b[0] = 1;
  Find(1, b);
  cout << ans << '\n';
  return 0;
}