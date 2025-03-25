#include <stdio.h> ///暴力遍历，暴力出奇迹
#include <string.h>
int main() {
  int m, n, p, i, sumn, sump;
  char mm[56][33], nn[55][35], pp[54][36];
  while (scanf("%d%d%d", &m, &n, &p) != EOF) {
    sumn = 0;
    sump = 0;
    for (i = 0; i < m; i++) {
      scanf("%s", mm[i]);
    }
    for (i = 0; i < n; i++) {
      scanf("%s", nn[i]);
      for (int j = 0; j < m; j++) {
        if (strcmp(mm[j], nn[i]) == 0) {
          sumn++;
        }
      }
    }
    for (i = 0; i < p; i++) {
      scanf("%s", pp[i]);
      for (int j = 0; j < m; j++) {
        if (strcmp(mm[j], pp[i]) == 0) {
          sump++;
        }
      }
    }
    printf("%d %d\n", sumn, sump);
  }
}
