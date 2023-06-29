/*
 * @Author: hzw20071003 365424368@qq.com
 * @Date: 2023-06-25 23:37:02
 * @LastEditors: hzw20071003 365424368@qq.com
 * @LastEditTime: 2023-06-25 23:42:29
 * @FilePath: \workspace\vjudge\I\2.cpp
 * Copyright (c) 2023 by hezewei, All Rights Reserved.
 */
// LUOGU_RID: 113323805
#include <iostream>

using namespace std;

const long long kMaxN = 5e5 + 5;
long long n, m, Min, Max;
string s;
struct line {
  long long num, col, front, next;
} l_max[kMaxN], l_min[kMaxN];

void Start(line *l, string s, long long m) {
  l[0].next = 1;
  for (long long i = 1; i <= m; i++) {
    l[i].col = (long long)s[i - 1] - 48;
    l[i].num = i;
    l[i].next = i + 1;
    l[i].front = i - 1;
  }
  l[m + 1].col = 2;
  l[m + 1].num = m + 1;
  l[m + 1].next = m + 2;
  l[m + 1].front = m;
}

long long Find_Min(line *l) {
  long long num = 0;
  for (long long i = l[0].next; i < m; i = l[i].next) {
    if (l[i].col == l[l[i].next].col && l[i].col == 1 && l[i].num == l[l[i].next].num - 1) {
      l[l[i].front].next = l[l[i].next].next;
      l[l[l[i].next].next].front = l[i].front;
      num++;
      i = l[i].next;
    }
  }
  return num;
}

long long Find_Max(line *l) {
  long long num = 0;
  for (long long i = l[0].next; i < m; i = l[i].next) {
    if (((l[i].col != l[l[i].next].col && l[l[i].next].col != 2) || (l[i].col == l[l[i].next].col && l[i].col == 0)) && l[i].num == l[l[i].next].num - 1) {
      l[l[i].front].next = l[l[i].next].next;
      l[l[l[i].next].next].front = l[i].front;
      num++;
      i = l[i].next;
    }
  }
  return num;
}

int main() {
  // freopen("1.in", "r", stdin);
  // freopen("3.out", "w", stdout);
  cin >> n >> m;
  for (long long i = 0; i < n; i++) {
    cin >> s;
    Start(l_min, s, m);
    Start(l_max, s, m);
    int num = 0;
    for (long long i = 0; i < m; i++) {
      Max += (s[i] == '1');
      Min += (s[i] == '1');
    }
    // int tmp2 = Find_Max(l_max);
    // cout << num << ' ' << tmp1 << ' ' << tmp2 << endl;
    Max -= max(m / 4 - Find_Max(l_max), (long long)0);
    Min -= min(Find_Min(l_min), m / 4);
    // cout << Max << endl;
  }
  cout << Min << ' ' << Max << endl;
  return 0;
}