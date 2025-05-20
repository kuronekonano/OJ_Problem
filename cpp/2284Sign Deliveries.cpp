#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
struct boxs {
  int st, time;
  char company[355];
  char name[355];
  int fin;
} box[250];
bool cmp(boxs a, boxs b) {
  if (a.fin == b.fin) {
    if (strcmp(a.company, b.company) == 0) {
      return (strcmp(a.name, b.name) < 0);
    }
    return (strcmp(a.company, b.company) < 0);
  }
  return a.fin < b.fin;
}
int main() {
  int t, i;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
      scanf("%d%d", &box[i].st, &box[i].time);
      if (box[i].st <= 11) {
        box[i].fin = 30 + box[i].st + box[i].time; /// 算最后时间要加的是30
      } else {
        box[i].fin = box[i].time + box[i].st;
      }
      scanf("%s", box[i].company);
      scanf("%s", box[i].name);
    }

    sort(box, box + n, cmp);
    for (i = 0; i < n; i++) {
      printf("%s %s\n", box[i].company, box[i].name);
    }
  }
  return 0;
}
