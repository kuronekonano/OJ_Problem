#include <stdio.h>
int main() {
  int a, b, t;
  scanf("%d", &t); /// ������ˣ�ȡ����λ
  while (t--) {
    scanf("%d %d", &a, &b);
    int key = a * b;
    printf("%d%d%d%d\n", key / 1000 % 10, key / 100 % 10, key / 10 % 10,
           key % 10);
  }
  return 0;
}
