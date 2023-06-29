/*
 * @Author: hzw20071003 365424368@qq.com
 * @Date: 2023-06-25 14:13:43
 * @LastEditors: hzw20071003 365424368@qq.com
 * @LastEditTime: 2023-06-25 14:13:48
 * @FilePath: \workspace\vjudge\E\hack.cpp
 * Copyright (c) 2023 by hezewei, All Rights Reserved.
 */
#include <iostream>
#include <queue>

using namespace std;

struct V {
  int d, b;
  bool _b;
  vector<int> e;
} v[200001];
int t, n, m;
priority_queue<pair<int, int>> q;

void Update(int t, int s) {
  if (v[t].b != s) {
    v[t].b = s, v[t]._b = 1;
    q.push({-v[t].d, t});
  }
}

bool S(int s) {
  int c = 0;
  while (!q.empty()) {
    q.pop();
  }
  for (Update(s, s); !q.empty();) {
    int t = q.top().second;
    if (v[t].d > c) {
      return 0;
    }
    q.pop(), c++;
    for (int i : v[t].e) {
      Update(i, s);
    }
  }
  return c == n;
}

bool C() {
  for (int i = 1; i <= n; i++) {
    if (!v[i].d && !v[i]._b && S(i)) {
      return 1;
    }
  }
  return 0;
}

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);
  cin >> t;
  while (t--) {
    fill(&v[1], &v[n] + 1, v[0]);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      cin >> v[i].d;
    }
    for (int i = 1, x, y; i <= m; i++) {
      cin >> x >> y;
      v[x].e.push_back(y), v[y].e.push_back(x);
    }
    cout << (C() ? "YES\n" : "NO\n");
  }
  return 0;
}
