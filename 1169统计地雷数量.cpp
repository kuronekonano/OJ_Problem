#include <stdio.h>
#include <string.h>
int walkx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}; /// ��ΧһȦ�˸������ж���û����
int walky[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int main() {
  char a[208][208];
  int i, j, x, y, m, flag = 0;
  while (scanf("%d %d %d", &x, &y, &m) != EOF) {
    getchar();  /// �������ֳԵ�һ�����з�
    if (flag++) /// Ϊɶ�����ﻻ�У�����û�����ꣿ
    {
      printf("\n");
    }
    memset(a, ' ', sizeof(a)); /// ���Ϊ�ո�
    for (i = 1; i <= x;
         i++) /// ��1��ʼ�������߽���ΧһȦ����ʱ����Ҫ�ж��Ƿ񳬳���Χ
    {
      for (j = 1; j <= y; j++) {
        scanf("%c", &a[i][j]);
      }
      getchar(); /// ������һ�гԵ�һ�����з�
    }
    for (i = 1; i <= x; i++) /// ͳ���������
    {
      for (j = 1; j <= y; j++) {
        char sum = '0';     /// ��Ϊ����ľ�������Ǻţ����Ի��ǵ��ַ�
        if (a[i][j] == '*') /// �����ײ��ù�
        {
          continue;
        } else /// û�����׾Ϳ���Χ�˸�������û����
        {
          for (int k = 0; k < 8; k++) /// ������:k���i
          {
            int xx = i + walkx[k];
            int yy = j + walky[k];
            if (a[xx][yy] == '*') {
              sum++;
            }
          }
          a[i][j] =
              sum; /// �������ֱ�Ӷ����ַ�'0'���ϼӣ�������int+'0'ת�����ַ��ͣ������ۼ���಻����8��������Ҳ���ᳬ��������ַ���
        }
      }
    }
    for (i = 1; i <= x; i++) /// �������
    {
      for (j = 1; j <= y; j++) {
        printf("%c", a[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}
