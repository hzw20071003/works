#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> num[2000001];
std::vector<int> tmp[2001];
int num[2000001], n, Last;

int find(int x, int Last) {
  int l = 0, r = tmp[x].size() - 1;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (Last >= tmp[x][mid]) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  return tmp[x][l];
}

int Read() {
  int f(1), x(0);
  char ch(getchar());
  while (ch < '0' || ch > '9') {
    if (ch == '-') {
      f = -1;
    }
    ch = getchar();
  }
  while (ch > '/' && ch < ':') {
    x = (x << 3) + (x << 1) + (ch - '0');
    ch = getchar();
  }
  return f * x;
}

int main() {
  freopen("ikun.in", "r", stdin);
  freopen("ikun.out", "w", stdout);
  n = Read();
  for (int i = 0; i < n * (n + 1); i++) {
    num[i].first = Read();
    num[i].second = i;
  }
  sort(num, num + n * (n + 1));
  for (int i = 0; i < n * (n + 1); i++) {
    num[i].first = i;
  }
  return 0;
}