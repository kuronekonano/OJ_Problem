#include <math.h> ///��Ϊ��ÿ���˶�ҪЯ��һ��ը�����������ɱ��������������������������ɱ���Է���������(С�ڱ�ը�뾶����)
#include <stdio.h> ///����n���˵����꣬ÿ���˶�Я��һ��ը����������ը�뾶������ÿ���˶���ըһ�Σ�ɱ�����˵�ƽ��ֵ�Ƕ���
#include <string.h> ///ͳ�Ƴ�����������֮�����Ծ��룬�����ֵ�������뾶�����У���ʾ������뾶�ڱ������ˣ���ɱ���Է��Է�ɱ���ң�
struct man          /// ������ɱ�����Լ���Ҳ����n���ˣ�Ȼ����������õ�ƽ��ֵ
{
  int x, y;
} a[3008];
int dis[40008];
int main() {
  int n, q;
  while (scanf("%d%d", &n, &q) != EOF) {
    if (n == 0 && q == 0)
      return 0;
    memset(dis, 0, sizeof(dis));
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &a[i].x, &a[i].y);
      for (int j = 0; j < i; j++) {
        double dist = sqrt((a[i].x - a[j].x) * (a[i].x - a[j].x) +
                           (a[i].y - a[j].y) * (a[i].y - a[j].y));
        dis[(int)ceil(dist)] +=
            2; /// ��Ϊ��С�ڵ���ĳ���뾶�Ķ����������Խ���������ȡ������ĳ���뾶��ɱ���ļ���
      }
    }
    for (int i = 2; i <= 40000; i++)
      dis[i] += dis[i - 1];
    while (q--) {
      int r;
      scanf("%d", &r);
      double ans = dis[r] + n;
      ans /= n;
      printf("%.2f\n", ans);
    }
    printf("\n");
  }
}
