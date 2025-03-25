#include <algorithm>
#include <stdio.h>
using namespace std;
int main() {
  int n, i, p, pro[19];
  while (scanf("%d%d", &n, &p) != EOF) {
    int time = 0;
    for (i = 0; i < n; i++) {
      if (i != p)
        scanf("%d", &pro[i]);
      else {
        scanf("%d", &time);
        pro[i] = 0x3f3f3f3f;
      }
    }
    if (time >= 300) {
      printf("%d %d\n", time == 300 ? 1 : 0, time == 300 ? 300 : 0);
      continue;
    }
    sort(pro, pro + n);
    int num = 1, sum = time;
    for (i = 0; i < n; i++) {
      if (sum + pro[i] > 300)
        break;
      else {
        num++;
        sum += pro[i];
        time += sum;
      }
    }
    printf("%d %d\n", num, time);
  }
}
