#include <iostream>
#include <cmath>

using namespace std;

int t, a, b;

int main() {
  cin >> t;
  while(t--) {
    cin >> a >> b;
    a = abs(a), b= abs(b);
    cout << min(a, b) * 2 + (a == b ? 0 : 1 + (max(a, b) - 1 - min(a, b)) * 2) << endl;
  }
  return 0;
}