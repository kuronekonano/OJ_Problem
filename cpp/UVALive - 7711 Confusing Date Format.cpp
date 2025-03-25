#include <map>
#include <stdio.h>
using namespace std;
bool judge(int year) {
  return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ? true : false;
}
int main() {
  int cas = 0, a, b, c, m, d, y, t,
      md[14] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  scanf("%d", &t);
  while (t--) {
    cas++;
    map<int, bool> ma;
    ma.clear();
    int ans = 0;
    scanf("%d-%d-%d", &a, &b, &c);
    if (a == 4 && b == 5 && c == 1) {
      printf("Case #%d: 1\n", cas);
      continue;
    }
    y = 1900 + a;
    if (judge(y)) {
      m = b;
      d = c;
      md[2] = 29;
      if (m >= 1 && m <= 12 && d >= 1 && d <= md[m] &&
          !ma[y * 1000 + m * 100 + d * 10]) {
        ans++;
        ma[y * 1000 + m * 100 + d * 10] = true;
      }
      m = c, d = b;
      if (m >= 1 && m <= 12 && d >= 1 && d <= md[m] &&
          !ma[y * 1000 + m * 100 + d * 10]) {
        ans++;
        ma[y * 1000 + m * 100 + d * 10] = true;
      }
      md[2] = 28;
    } else {
      m = b;
      d = c;
      if (m >= 1 && m <= 12 && d >= 1 && d <= md[m] &&
          !ma[y * 1000 + m * 100 + d * 10]) {
        ans++;
        ma[y * 1000 + m * 100 + d * 10] = true;
      }
      m = c, d = b;
      if (m >= 1 && m <= 12 && d >= 1 && d <= md[m] &&
          !ma[y * 1000 + m * 100 + d * 10]) {
        ans++;
        ma[y * 1000 + m * 100 + d * 10] = true;
      }
    }
    y = 1900 + b;
    if (judge(y)) {
      m = a;
      d = c;
      md[2] = 29;
      if (m >= 1 && m <= 12 && d >= 1 && d <= md[m] &&
          !ma[y * 1000 + m * 100 + d * 10]) {
        ans++;
        ma[y * 1000 + m * 100 + d * 10] = true;
      }
      m = c, d = a;
      if (m >= 1 && m <= 12 && d >= 1 && d <= md[m] &&
          !ma[y * 1000 + m * 100 + d * 10]) {
        ans++;
        ma[y * 1000 + m * 100 + d * 10] = true;
      }
      md[2] = 28;
    } else {
      m = a;
      d = c;
      if (m >= 1 && m <= 12 && d >= 1 && d <= md[m] &&
          !ma[y * 1000 + m * 100 + d * 10]) {
        ans++;
        ma[y * 1000 + m * 100 + d * 10] = true;
      }
      m = c, d = a;
      if (m >= 1 && m <= 12 && d >= 1 && d <= md[m] &&
          !ma[y * 1000 + m * 100 + d * 10]) {
        ans++;
        ma[y * 1000 + m * 100 + d * 10] = true;
      }
    }
    y = 1900 + c;
    if (judge(y)) {
      m = b;
      d = a;
      md[2] = 29;
      if (m >= 1 && m <= 12 && d >= 1 && d <= md[m] &&
          !ma[y * 1000 + m * 100 + d * 10]) {
        ans++;
        ma[y * 1000 + m * 100 + d * 10] = true;
      }
      m = a, d = b;
      if (m >= 1 && m <= 12 && d >= 1 && d <= md[m] &&
          !ma[y * 1000 + m * 100 + d * 10]) {
        ans++;
        ma[y * 1000 + m * 100 + d * 10] = true;
      }
      md[2] = 28;
    } else {
      m = b;
      d = a;
      if (m >= 1 && m <= 12 && d >= 1 && d <= md[m] &&
          !ma[y * 1000 + m * 100 + d * 10]) {
        ans++;
        ma[y * 1000 + m * 100 + d * 10] = true;
      }
      m = a, d = b;
      if (m >= 1 && m <= 12 && d >= 1 && d <= md[m] &&
          !ma[y * 1000 + m * 100 + d * 10]) {
        ans++;
        ma[y * 1000 + m * 100 + d * 10] = true;
      }
    }
    printf("Case #%d: %d\n", cas, ans);
  }
}
