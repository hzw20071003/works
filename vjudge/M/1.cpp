// M
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int kMaxN = 2e5 + 5;
int t, len, num;
string s[kMaxN], tmp;
char ch[kMaxN], ans[kMaxN], k;

int main() {
  cin >> t;
  while (t--) {
    k = ' ', num = 0;
    cin >> s[t];
    len = s[t].length();
    tmp = s[t];
    for (int i = 0; i < len; i++) {
      ch[i] = tmp[i];
    }
    sort(ch, ch + len);
    for (int i = 0; i < len; i++) {
      if (i + 1 < len && ch[i] == ch[i + 1] && (ch[i] == ch[len - 1] || k == ' ')) {
        ans[num] = ans[len - num - 1] = ch[i];
        num++;
        i++;
      } else if (((i + 1 < len && ch[i] != ch[i + 1]) || i + 1 >= len) && k == ' ') {
        k = ch[i];
      } else if (i + 1 < len && ch[len - 1] != ch[i] && k != ' ') {
        for (; i < len; i++, num++) {
          ans[num] = ch[i];
        }
        ans[num] = k;
      } else if (i + 1 >= len && k != ' ') {
        ans[num] = ch[i], ans[len - num - 1] = k;
        num++;
        k = ' ';
      }
    }
    if (k != ' ') {
      ans[num] = k;
    }
    for (int i = 0; i < len; i++) {
      cout << ans[i];
    }
    cout << endl;
  }
  return 0;
}