#include <iostream>

using namespace std;

long long n, a, b, opt, ans_a, ans_b = 1, k;

long long gcd(long long a, long long b) {
  return (b > 0 ? gcd(b, a % b) : a);
}

int main() {
  cin >> n;
  while (n--) {
    cin >> a >> b >> opt;
    ans_a = ans_a * b + a * ans_b * (opt == 1 ? 1 : -1);
    ans_b *= b;
    k = gcd(abs(ans_a), abs(ans_b));
    ans_a /= k;
    ans_b /= k;
  }
  if(ans_b < 0) {
    ans_b *= -1;
    ans_a *= -1;
  }
  cout << ans_a;
  if (ans_b != 1) {
    cout << '/' << ans_b;
  }
  return 0;
}