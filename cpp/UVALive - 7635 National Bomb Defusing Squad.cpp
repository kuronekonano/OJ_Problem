#include <math.h> ///因为是每个人都要携带一次炸弹，因此以总杀死人数来计数，最后计数了所有杀死对方的人数后(小于爆炸半径的人)
#include <stdio.h> ///给出n个人的坐标，每个人都携带一次炸弹，给出爆炸半径，问若每个人都爆炸一次，杀死的人的平均值是多少
#include <string.h> ///统计出所有人两两之间的相对距离，将这个值计数到半径数组中，表示在这个半径内必死两人（我杀死对方对方杀死我）
struct man          /// 最后加上杀死的自己，也就是n个人，然后除总人数得到平均值
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
            2; /// 因为是小于等于某个半径的都会死，所以将距离向上取整就是某个半径下杀死的计数
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
