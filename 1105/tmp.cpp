/*
 * @Author: hzw20071003 365424368@qq.com
 * @Date: 2022-11-05 08:20:33
 * @LastEditors: hzw20071003 365424368@qq.com
 * @LastEditTime: 2022-11-05 10:06:39
 * @FilePath: \workspace\1105\tmp.cpp
 * Copyright (c) 2022 by hzw20071003, All Rights Reserved.
 */
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("inline")
#include <cstdio>
#include <vector>

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
    num[i] = Read();
  }
  tmp[0].push_back(1e9 + 7);
  for (int i = n * (n + 1) - 1; i >= 0 && tmp[n * 2].empty(); i--) {
    for (int j(std::min(n * 2, Last + 1)); j && tmp[n * 2].empty(); j--) {
      if (tmp[j - 1].back() > num[i] && (tmp[j].empty() || tmp[j].back() < num[i])) {
        tmp[j].push_back(num[i]);
        Last = std::max(Last, j);
        break;
      }
    }
  }
  Last = 1e9 + 7;
  for (int i(n * 2); i; i--) {
    Last = find(i, Last);
    printf("%d ", Last);
  }
  return 0;
}