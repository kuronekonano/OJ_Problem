#include <math.h>
#include <stdio.h> ///�ж�Բ����
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int x1, y1, x2, y2, r1, r2;
    scanf("%d%d%d%d%d%d", &x1, &y1, &r1, &x2, &y2, &r2);
    int maxn = r1 >= r2 ? r1 : r2;
    int minn = r1 >= r2 ? r2 : r1;
    double dis = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    if (dis == 0 && r1 == r2) /// �غ�
    {
      printf("-1\n");
      continue;
    }
    if (dis == (maxn - minn)) /// ����
    {
      printf("1\n");
      continue;
    }
    if (dis < (maxn - minn)) /// �ں�
    {
      printf("0\n");
      continue;
    }
    if (dis == (maxn + minn)) /// ����
    {
      printf("3\n");
      continue;
    }
    if (dis < (maxn + minn) && dis > (maxn - minn)) /// �ཻ
    {
      printf("2\n");
      continue;
    }
    if (dis > (maxn + minn)) /// ����
    {
      printf("4\n");
      continue;
    }
  }
  return 0;
}
