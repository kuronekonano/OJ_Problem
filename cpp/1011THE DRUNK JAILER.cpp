#include <stdio.h> ///��������
#include <string.h>
int main() {
  bool cell[105];
  int t, n, i, j;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    memset(cell, true, sizeof(cell));
    for (i = 1; i <= n; i++) /// ִ��n�Σ�n�����ˣ�n������
    {
      for (j = i; j <= n; j += i) /// ����û�������ǵڼ��ξ��Ǽ��ı����ķ��俪��
      {
        cell[j] = cell[j] ? false : true;
      }
    }
    int flag = 0;
    for (i = 1; i <= n; i++) /// ��������
    {
      if (cell[i] == false) {
        flag++;
      }
    }
    printf("%d\n", flag);
  }
  return 0;
}
