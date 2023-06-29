#include <iostream>

using namespace std;

long long num[111], n;
string s, a = "0", b = "1";

void Find(int x, int Last, string s) {
  if (x == n) {
    if (num[0] == num[1] && num[1] == num[10] && num[10] == num[11]) {
      cout << s << endl;
      cout << num[0] << ' ' << num[1] << ' ' << num[10] << ' ' << num[11] << endl;
    }
    return;
  }
  num[Last * 10 + 1]++;
  Find(x + 1, 1, s + b);
  num[Last * 10 + 1]--;
  num[Last * 10]++;
  Find(x + 1, 0, s + a);
  num[Last * 10]--;
}

int main() {
  cin >> n;
  Find(1, 0, "0");
  Find(1, 1, "1");
  return 0;
}