#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int> q;
vector<pair<int, int>> m[500001];

int dep[301];
int n, num[4];
struct P {
  int num[5];
} p[500001];

int Find(int x, int in, int f) {
  if (x == 0) {
    m[0].push_back({f, in});
    return 0;
  }
  int tmp = in;
  for (int i = 0; i < m[x].size() && tmp; i++) {
    if (m[x][i].second) {
      int k = Find(m[x][i].first, min(tmp, m[x][i].second), x);
      m[x][i].second -= k;
      tmp -= k;
    }
  }
  m[x].push_back({f, in - tmp});
  return tmp;
}

int main() {
  cin >> n;
  for (int i = 0; i < 3; i++) {
    cin >> num[i];
    m[n + 3 + i].push_back({n + 3, 0});
  }
  for (int i = 2; i <= n + 1; i++) {
    m[1].push_back({i, 1});
    for (int j = 0; j < 3; j++) {
      cin >> p[i].num[j];
      p[i].num[3] += p[i].num[j];
    }
  }
  return 0;
}