#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
unsigned
    a[5005]; // 为毛要用无符号整型？输出因为不知道怎么写所以只能用cout和cin了
unsigned fei(unsigned n) {
  int i;
  a[1] = 0;
  a[2] = 1;
  for (i = 3; i <= n; i++) {
    a[i] = a[i - 1] + a[i - 2];
  }
  return a[i - 1];
}
int main() {
  unsigned p, k;
  while (cin >> p >> k) {
    if (p == 0 && k == 0)
      return 0;
    p = fei(p);
    k = pow(2, k);
    if (p == 1 || p == 2) {
      cout << a[p] << endl;
    } else {
      cout << p % k << endl;
    }
  }
  return 0;
}
