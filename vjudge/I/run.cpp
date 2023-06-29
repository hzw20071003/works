/*
 * @Author: hzw20071003 365424368@qq.com
 * @Date: 2023-06-25 14:11:55
 * @LastEditors: hzw20071003 365424368@qq.com
 * @LastEditTime: 2023-06-25 23:43:09
 * @FilePath: \workspace\vjudge\I\run.cpp
 * Copyright (c) 2023 by hezewei, All Rights Reserved.
 */
#include <windows.h>

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int kMaxN = 2e5 + 2;

int t, n, m, a[kMaxN], x, y, col[kMaxN], Max, tmp = 1;
vector<int> line[kMaxN], ans;
priority_queue<pair<int, int>> Find;
bool b;

int main() {
  while (1) {
    system("build.exe");
    cout << "数据更新完成" << endl;
    Sleep(500);
    system("hack.exe");
    cout << "hack完成" << endl;
    system("1.exe");
    cout << "运行完成" << endl;
    if (system("fc 1.out 2.out")) {
      break;
    }
  }
  return 0;
}
