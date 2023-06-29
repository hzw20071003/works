/*
 * @Author: hzw20071003 365424368@qq.com
 * @Date: 2023-04-05 23:09:32
 * @LastEditors: hzw20071003 365424368@qq.com
 * @LastEditTime: 2023-04-29 12:07:20
 * @FilePath: \workspace\2.cpp
 * Copyright (c) 2023 by hezewei, All Rights Reserved.
 */
#include <algorithm>
#include <cstdio>

long long ans = 7e18 + 1;
int n, num[20000001];
std::pair<int, int> a[400001];

int read() {
  int f(1), x(0);
  int ch(getchar());
  while (ch < 48 || ch > 57) {
    if (ch == 45) {
      f = -1;
    }
    ch = getchar();
  }
  while (ch > 47 && ch < 58) {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return f * x;
}

int main() {
  n = read();
  for (int i(1); i <= n; ++i) {
    a[i].first = read() + 1e7 + 1, a[i].second = read() + 1e7 + 1;
    ++num[a[i].second];
  }
  sort(a + 1, a + n + 1);
  for (int i(1); i <= n; ++i) {
    long long Max = 0, Min = 1e18 + 7;
    for (int j(i + 1); (long long)(a[i].first - a[j].first) * (a[i].first - a[j].first) < ans && j <= std::min(i + 1563, n); ++j) {
      if (a[j].second > a[i].second && Min > a[j].second) {
        ans = std::min(ans, (long long)(a[i].first - a[j].first) * (a[i].first - a[j].first) + (long long)(a[i].second - a[j].second) * (a[i].second - a[j].second));
        Min = a[j].second;
      } else if (a[j].second < a[i].second && Max < a[j].second) {
        ans = std::min(ans, (long long)(a[i].first - a[j].first) * (a[i].first - a[j].first) + (long long)(a[i].second - a[j].second) * (a[i].second - a[j].second));
        Max = a[j].second;
      }
    }
  }
  printf("%lld", ans);
  return 0;
}