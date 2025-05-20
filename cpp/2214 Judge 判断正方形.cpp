#include <algorithm>
#include <math.h> ///判断四个点坐标是否组成正方形，只需判断四边相等，并且对角线相等
#include <stdio.h>
using namespace std;
int main() {
  double x1, y1, x2, y2, x3, y3, x4, y4;
  while (scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4,
               &y4) != EOF) {
    if (x1 == x2 && x2 == x3 && x3 == x4 && y1 == y2 && y2 == y3 &&
        y3 ==
            y4) /// 坑：四个点在同一位置重合时，按这样的算法也会得yes，应特殊考虑
    {
      printf("No\n");
      continue;
    }
    double dis[6]; /// 采用数组存储六条距离长度，方便排序
    dis[0] = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    dis[1] =
        sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3)); /// 两点间距离公式
    dis[2] = sqrt((x4 - x2) * (x4 - x2) + (y4 - y2) * (y4 - y2));
    dis[3] = sqrt((x4 - x3) * (x4 - x3) + (y4 - y3) * (y4 - y3));
    dis[4] = sqrt((x1 - x4) * (x1 - x4) + (y1 - y4) * (y1 - y4));
    dis[5] = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    sort(
        dis,
        dis +
            6); /// 排序是因为无法判断给出的四个坐标是以何种顺序，因此要排序，较短的肯定为四边，较长的就是对角线
    if (dis[0] == dis[1] && dis[0] == dis[2] && dis[0] == dis[3] &&
        dis[4] == dis[5]) {
      printf(
          "Yes\n"); /// 证明为正方形的条件就是四边相等，且对角线相等，此处不能判断边与对角线呈
                    /// 根号二倍sqrt(2) 的关系！
    } else {
      printf("No\n");
    }
  }
  return 0;
}
