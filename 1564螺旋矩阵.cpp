#include <stdio.h>
#include <string.h>

int xxx(int b) /// ����λ��
{
  int flag = 0;
  while (b != 0) {
    b = b / 10;
    flag++;
  }
  return flag;
}
int main() {
  int n, i, j, a[40][40], x, y;
  bool check = false;
  while (scanf("%d", &n) != EOF) {
    int flag = 1;
    memset(a, 0, sizeof(a));
    x = 1;
    y = 1;
    a[x][y] = flag++;
    int t = n;
    while (flag <= n * n) /// ��������
    {
      for (y++; y <= t; y++) /// ������
      {
        a[x][y] = flag++;
      }
      y--;
      for (x++; x <= t; x++) /// ���ϵ���
      {
        a[x][y] = flag++;
      }
      x--;
      for (y--; y >= n - x + 1; y--) /// ���ҵ���
      {
        a[x][y] = flag++;
      }
      y++;
      for (x--; a[x][y] == 0; x--) /// ������
      {
        a[x][y] = flag++;
      }
      x++;
      t--; /// �����Ǵ����Ͻǿ�ʼ��˳ʱ������
    }
    if (check) /// ����whileѭ���е����ݼ����
    {
      printf("\n");
    } else {
      check = true;
    }
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++) {
        printf("%*d", xxx(n * n) + 1, a[i][j]); /// ��̬�����ַ���ȣ���������
      }
      printf("\n");
    }
  }
  return 0;
}
