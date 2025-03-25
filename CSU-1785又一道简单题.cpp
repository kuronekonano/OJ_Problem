#include <stdio.h>
#include <string.h>
bool vis[9999];
void inti() {
  for (int i = 32; i < 100; i++) {
    vis[i * i] = true;
  }
}
int main() {
  memset(vis, false, sizeof(vis));
  inti();
  char a[6];
  int b[5], i, t, j, cas = 1;
  scanf("%d", &t);
  while (t--) {
    int sum = 0;
    scanf("%s", a);
    int nums = (a[0] - '0') * 1000 + (a[1] - '0') * 100 + (a[2] - '0') * 10 +
               (a[3] - '0');
    for (j = 1; j <= 9; j++) {
      int num = j * 1000 + (a[1] - '0') * 100 + (a[2] - '0') * 10 + a[3] - '0';
      if (vis[num]) {
        sum++;
      }
    }
    for (j = 0; j <= 9; j++) {
      int num = (a[0] - '0') * 1000 + j * 100 + (a[2] - '0') * 10 + a[3] - '0';
      if (vis[num]) {
        sum++;
      }
    }
    for (j = 0; j <= 9; j++) {
      int num = (a[0] - '0') * 1000 + (a[1] - '0') * 100 + j * 10 + a[3] - '0';
      if (vis[num]) {
        sum++;
      }
    }
    for (j = 0; j <= 9; j++) {
      int num =
          (a[0] - '0') * 1000 + (a[1] - '0') * 100 + (a[2] - '0') * 10 + j;
      if (vis[num]) {
        sum++;
      }
    }
    if (vis[nums]) {
      sum -= 4;
    }
    printf("Case %d: %d\n", cas++, sum);
  }
  return 0;
}
