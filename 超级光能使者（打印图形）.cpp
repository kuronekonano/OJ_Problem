#include <math.h>
#include <stdio.h>
#include <string.h>
char a[5000][5000];
int digui(int n, int x, int y, int h, int w) {
  if (n == 2) {
    a[x][y] = a[x - 1][y - 1] = a[x][y - 2] = '*';
    return 0;
  }
  int nh = pow(2, n - 2) / 2,
      nw = (pow(2, n - 1) - 1) / 2; /// ��һ�����������꣬��������
  digui(n - 1, x, y, nh, nw);       /// ���½ǣ������������½�Ϊ��׼�㣬��֧��չ
  digui(n - 1, x, y - w - 1, nh, nw); /// ���½�
  digui(
      n - 1, x - h, y - w / 2 - 1, nh,
      nw); /// �Ϸ�///�����½�����
           /// һֻ����������Ͷ����һ��ͼ�δ�ӡ�ĺ����д���ֱ���ҵ�ÿһ��n=2ʱ������
} /*                      /  |  \      */
int main() /*��ߴ�ͼ�� �м�  �ұߴ�ͼ��*/
{
  /*   / | \   /|\     / | \     */
  int n, x, y, stop, i, j, t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    n++;
    memset(a, ' ', sizeof(a));
    x = pow(2, n - 1);
    y = (pow(2, n)) - 1;
    int h = x / 2; /*Сͼ�εĸ߿�*/
    int w = y / 2;
    digui(n, x, y, h, w);    /*��������*/
    for (i = 1; i <= x; i++) /*�������*/
    {
      for (j = 1; j <= pow(2, n) - 1; j++) // �������
      {
        if (a[i][j] == '*')
          stop = j; // ��ֹ����Ŀո����
      }
      for (j = 1; j <= stop; j++) // �ڿո���ִ�ֹͣ���
      {
        printf("%c", a[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}
