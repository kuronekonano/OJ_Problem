#include <algorithm>
#include <stdio.h>
using namespace std;
struct box {
  int x;
  int y;
  int h;
} boxs[1005];
bool cmp(box a, box b) {
  if (a.x == b.x) {
    return a.h < b.h;
  }
  return a.x < b.x;
}
int main() {
  int i, n, j;
  while (scanf("%d", &n) != EOF) {
    for (i = 0; i < n; i++) {
      scanf("%d%d%d", &boxs[i].x, &boxs[i].y, &boxs[i].h);
    }
    sort(boxs, boxs + n, cmp);
    int a[1005], j = 0, sumh = 0;
    for (i = 0; i < n; i++) {
      if (boxs[i].x != boxs[i + 1].x && i != n - 1) {
        sumh = sumh + boxs[i].h;
      }
    }
    sumh = sumh + boxs[n - 1].h;
    printf("%d\n", sumh);
    //        for(i=0;i<n;i++)
    //        {
    //            printf("%d %d %d\n",boxs[i].x,boxs[i].y,boxs[i].h);
    //        }
  }
  return 0;
}
