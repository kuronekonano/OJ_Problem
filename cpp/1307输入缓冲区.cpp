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
  while (scanf("%s", a) != EOF) /// ʹ��cin ��ʱ��ʹ��string��ʱ
  {
    getchar(); /// �Ӹ��س�
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
