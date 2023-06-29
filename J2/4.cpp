#include <iostream>

using namespace std;

long long num[3001], ans[6001];
long long n, a, tmp1, tmp2;

int main() {
  cin >> n;
  while (n--) {
    cin >> a;
    num[a]++;
  }
  for (long long i = 1; i < 3001; i++) {
    for (long long j = i + 1; j < 3001; j++) {
      ans[i + j] += min(num[i], num[j]);
    }
  }
  for (long long i = 1; i < 3001; i++) {
      ans[i * 2] += num[i] / 2;
  }
  for (long long i = 1; i < 6001; i++) {
    if (ans[i] > tmp1) {
      tmp1 = ans[i];
      tmp2 = 0;
    }
    if (ans[i] == tmp1) {
      tmp2++;
    }
  }
  cout << tmp1 << ' ' << tmp2 << endl;
  return 0;
}