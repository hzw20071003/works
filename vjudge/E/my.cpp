/*
 * @Author: hzw20071003 365424368@qq.com
 * @Date: 2023-06-25 14:12:41
 * @LastEditors: hzw20071003 365424368@qq.com
 * @LastEditTime: 2023-06-25 17:05:39
 * @FilePath: \workspace\vjudge\E\my.cpp
 * Copyright (c) 2023 by hezewei, All Rights Reserved.
 */
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int kMaxN = 2e5 + 2;
int t, n, m, x, y, tmp;
int a[kMaxN], f[kMaxN], num[kMaxN];
priority_queue<pair<int, int>> q[kMaxN];
vector<int> ans;
bool b;

int F(int x) {
  return (x == f[x] ? x : F(f[x]));
}

void Reset() {
  b = 0;
  ans.clear();
  for (int i = 1; i <= n; i++) {
    f[i] = i, num[i] = 1;
    while (!q[i].empty()) {
      q[i].pop();
    }
  }
}

int main() {
  // freopen("1.in", "r", stdin);
  // freopen("2.out", "w", stdout);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    Reset();
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] == 0) {
        ans.push_back(i);
      }
    }
    while (m--) {
      cin >> x >> y;
      if (x != y) {
        q[x].push({-a[y], y});
        q[y].push({-a[x], x});
      }
    }
    for (int i = 0, Max = -1; i < ans.size(); i++, Max = -1) {
      if (f[ans[i]] == ans[i]) {
        while (!q[ans[i]].empty()) {
          if (q[ans[i]].top().first >= Max && F(q[ans[i]].top().second) != ans[i]) {
            int k = F(q[ans[i]].top().second);
            int tmp2 = q[ans[i]].top().second;
            q[ans[i]].pop();
            Max -= num[k];
            num[ans[i]] += num[k];
            while (!q[k].empty()) {
              if (F(q[k].top().second) != ans[i]) {
                q[ans[i]].push({q[k].top().first, q[k].top().second});
              }
              q[k].pop();
            }
            f[k] = ans[i];
          } else if (F(q[ans[i]].top().second) == ans[i]) {
            q[ans[i]].pop();
          } else {
            break;
          }
        }
      }
    }
    for (int i = 2; i <= n; i++) {
      b = (b ? 1 : F(i) != F(i - 1));
    }
    cout << (b ? "NO" : "YES") << endl;
  }
  return 0;
}