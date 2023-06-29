/*
 * @Author: hzw20071003 365424368@qq.com
 * @Date: 2022-10-24 19:11:12
 * @LastEditors: hzw20071003 365424368@qq.com
 * @LastEditTime: 2022-10-24 19:12:10
 * @FilePath: \workspace\2022-10-24\source\hezewei1024\gcd\gcd.cpp
 * Copyright (c) 2022 by hzw20071003, All Rights Reserved.
 */
#include <iostream>
#include <vector>

using namespace std;

long long n, a, ans, Max, f[100001];
vector<long long> v[100001];

long long FindF(long long x) {
  return f[x] == x ? f[x] : (f[x] = FindF(f[x]));
}

long long read() {
  long long x(0);
  char ch(getchar());
  while (ch < '0' || '9' < ch) {
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch - '0');
    ch = getchar();
  }
  return x;
}

int main() {
  freopen("gcd.in", "r", stdin);
  freopen("gcd.out", "w", stdout);
  n = read();
  for (long long i(0); i < n; f[i] = i, i++) {
    a = read();
    for (long long j(1); j * j <= a; j++) {
      if (a % j == 0) {
        v[j].push_back(i);
        v[a / j].push_back(i);
        Max = max(Max, a / j);
      }
    }
  }
  for (long long i(Max), num(0); i >= 1 && num < n - 1; i--) {
    if (v[i].size() > 1) {
      long long F = FindF(v[i][0]);
      for (auto &j : v[i]) {
        if (FindF(j) != F) {
          f[FindF(j)] = F;
          ans += i;
          num++;
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}