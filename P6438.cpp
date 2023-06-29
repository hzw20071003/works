/*
 * @Author: hzw20071003 365424368@qq.com
 * @Date: 2022-10-15 16:47:49
 * @LastEditors: hzw20071003 365424368@qq.com
 * @LastEditTime: 2023-04-05 23:26:25
 * @FilePath: \workspace\1.cpp
 * Copyright (c) 2023 by ${git_name}, All Rights Reserved.
 */
#include <iostream>

using namespace std;

char ch[702][702];
int n, m, ans[11];

int main() {
  // freopen("P6438_1.in", "r", stdin);
  // freopen("1.out", "w", stdout);
  cin >> n >> m;
  getchar();
  getchar();
  for (int i = 1; i <= 5 * n + 1; i++) {
    for (int j = 1; j <= 5 * m + 1; j++) {
      ch[i][j] = getchar();
    }
    getchar();
    getchar();
  }
  for (int i = 1; i <= 5 * n + 1; i++) {
    for (int j = 1; j <= 5 * m + 1; j++) {
      if (ch[i][j] != '#') {
        ans[0] += (ch[i][j] == '.' && ch[i][j + 1] == '.' && ch[i][j + 2] == '.' && ch[i][j + 3] == '.' &&
                   ch[i + 1][j] == '.' && ch[i + 1][j + 1] == '.' && ch[i + 1][j + 2] == '.' && ch[i + 1][j + 3] == '.' &&
                   ch[i + 2][j] == '.' && ch[i + 2][j + 1] == '.' && ch[i + 2][j + 2] == '.' && ch[i + 2][j + 3] == '.' &&
                   ch[i + 3][j] == '.' && ch[i + 3][j + 1] == '.' && ch[i + 3][j + 2] == '.' && ch[i + 3][j + 3] == '.');
        ans[1] += (ch[i][j] == '*' && ch[i][j + 1] == '*' && ch[i][j + 2] == '*' && ch[i][j + 3] == '*' &&
                   ch[i + 1][j] == '.' && ch[i + 1][j + 1] == '.' && ch[i + 1][j + 2] == '.' && ch[i + 1][j + 3] == '.' &&
                   ch[i + 2][j] == '.' && ch[i + 2][j + 1] == '.' && ch[i + 2][j + 2] == '.' && ch[i + 2][j + 3] == '.' &&
                   ch[i + 3][j] == '.' && ch[i + 3][j + 1] == '.' && ch[i + 3][j + 2] == '.' && ch[i + 3][j + 3] == '.');
        ans[2] += (ch[i][j] == '*' && ch[i][j + 1] == '*' && ch[i][j + 2] == '*' && ch[i][j + 3] == '*' &&
                   ch[i + 1][j] == '*' && ch[i + 1][j + 1] == '*' && ch[i + 1][j + 2] == '*' && ch[i + 1][j + 3] == '*' &&
                   ch[i + 2][j] == '.' && ch[i + 2][j + 1] == '.' && ch[i + 2][j + 2] == '.' && ch[i + 2][j + 3] == '.' &&
                   ch[i + 3][j] == '.' && ch[i + 3][j + 1] == '.' && ch[i + 3][j + 2] == '.' && ch[i + 3][j + 3] == '.');
        ans[3] += (ch[i][j] == '*' && ch[i][j + 1] == '*' && ch[i][j + 2] == '*' && ch[i][j + 3] == '*' &&
                   ch[i + 1][j] == '*' && ch[i + 1][j + 1] == '*' && ch[i + 1][j + 2] == '*' && ch[i + 1][j + 3] == '*' &&
                   ch[i + 2][j] == '*' && ch[i + 2][j + 1] == '*' && ch[i + 2][j + 2] == '*' && ch[i + 2][j + 3] == '*' &&
                   ch[i + 3][j] == '.' && ch[i + 3][j + 1] == '.' && ch[i + 3][j + 2] == '.' && ch[i + 3][j + 3] == '.');
        ans[4] += (ch[i][j] == '*' && ch[i][j + 1] == '*' && ch[i][j + 2] == '*' && ch[i][j + 3] == '*' &&
                   ch[i + 1][j] == '*' && ch[i + 1][j + 1] == '*' && ch[i + 1][j + 2] == '*' && ch[i + 1][j + 3] == '*' &&
                   ch[i + 2][j] == '*' && ch[i + 2][j + 1] == '*' && ch[i + 2][j + 2] == '*' && ch[i + 2][j + 3] == '*' &&
                   ch[i + 3][j] == '*' && ch[i + 3][j + 1] == '*' && ch[i + 3][j + 2] == '*' && ch[i + 3][j + 3] == '*');
      }
    }
  }
  cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << ' ' << ans[3] << ' ' << ans[4] << endl;
  return 0;
}