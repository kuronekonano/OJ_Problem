#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;
int main() {
  char a[9];
  char b;
  queue<char> q;
  while (!q.empty()) {
    q.pop();
  }
  while (scanf("%s", a) != EOF) /// 使用cin 超时，使用string超时
  {
    getchar(); /// 接个回车
    if (strcmp(a, "In") == 0) {
      scanf("%c", &b);
      q.push(b);
    }
    if (strcmp(a, "Out") == 0) {
      b = q.front();
      printf("%c\n", b);
      q.pop();
    }
  }
  return 0;
}
