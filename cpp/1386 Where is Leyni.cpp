#include <stdio.h>
int main() {
  int t, a, b, n, i;
  scanf("%d", &t);
  while (t--) {
    int flag = 0;
    scanf("%d%d%d", &n, &a, &b);
    for (i = 0; i < n; i++) {
      if (i >= a &&
          (n - i - 1) <=
              b) // ��ס�����䱾���������iΪǰ���������n-i-1Ϊ���������
      {
        flag++;
      }
    }
    printf("%d\n", flag);
  }
  return 0;
}
