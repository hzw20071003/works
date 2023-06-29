/*
 * @Author: hzw20071003 365424368@qq.com
 * @Date: 2023-06-25 14:12:16
 * @LastEditors: hzw20071003 365424368@qq.com
 * @LastEditTime: 2023-06-25 14:12:22
 * @FilePath: \workspace\vjudge\E\build.cpp
 * Copyright (c) 2023 by hezewei, All Rights Reserved.
 */
#include <ctime>
#include <iostream>

using namespace std;

int t, n, m, x, y;

int main() {
  freopen("1.in", "w", stdout);
  srand(time(0));
  n = rand() % 10 + 1;
  m = rand() % 10 + 1;
  cout << n << ' ' << m << endl;
  for (int i = 0; i < n; i++) {
    for (int i = 0; i < m; i++) {
      cout << (rand() % n)% 2;
    }
    cout << endl;
  }
  return 0;
}
