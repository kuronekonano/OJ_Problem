#include <iostream>
#include <map> ///一一映射
#include <stdio.h>
#include <string>
using namespace std;
int main() {
  int n, t, i;
  map<string, string> q; /// 字符串用string而不是char
  char stu[30], num[30];
  while (scanf("%d", &n) != EOF) {
    for (i = 1; i <= n; i++) {
      scanf("%s %s", stu, num);
      q[stu] = num; /// 像数组一样使用
    }
    scanf("%d", &t);
    while (t--) {
      scanf("%s", stu);
      cout << q[stu] << endl; /// 输出必须用C++的
    }
  }
  return 0;
}
