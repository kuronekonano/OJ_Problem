#include <stdio.h> ///БЉСІев
int main() {
  char a[5][5];
  int i, j;
  while (scanf("%s", a[0]) != EOF) {
    for (j = 0; j < 4; j++) {
      if (a[0][j] == '#') {
        a[0][j] = '1';
      } else {
        a[0][j] = '0';
      }
    }
    for (i = 1; i < 4; i++) {
      scanf("%s", a[i]);
      for (j = 0; j < 4; j++) {
        if (a[i][j] == '#') {
          a[i][j] = '1';
        } else {
          a[i][j] = '0';
        }
      }
    }
    bool flag = false;
    for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
        int sum = 0;
        sum = a[i][j] - '0' + a[i][j + 1] - '0' + a[i + 1][j] - '0' +
              a[i + 1][j + 1] - '0';
        if (sum == 0 || sum == 1 || sum == 3 || sum == 4) {
          printf("YES\n");
          flag = true;
          break;
        }
      }
      if (flag) {
        break;
      }
    }
    if (flag == false) {
      printf("NO\n");
    }
  }
}
