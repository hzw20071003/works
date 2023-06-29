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
bool b[11][11];

int main() {
  freopen("1.in", "w", stdout);
  srand(time(0));
  t = 1;
  cout << 1 << endl;
  for (int i = 0; i < t; i++) {
    n = rand() % 10 + 1;
    m = rand() % (n * (n - 1)) + 1;
    cout << n << ' ' << m << endl;
    for (int i = 0; i < n; i++) {
      cout << rand() % 10 << ' ';
    }
    cout << endl;
    for (int i = 0; i < m; i++) {
      cout << (rand() % n) + 1 << ' ' << (rand() % n) + 1 << endl;
    }
  }
  return 0;
}
