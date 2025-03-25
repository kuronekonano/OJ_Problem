#include <stdio.h>
#include <string.h>
int main() {
  char a[105];
  char s[105];
  int n, t;
  while (gets(a)) {
    gets(s);
    n = strlen(a);
    t = strlen(s);
    int flag = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == ' ')
        continue;
      if (a[i] >= 'A' && a[i] <= 'Z') {
        a[flag] = a[i] + 32;
        flag++;
      } else {
        a[flag] = a[i];
        flag++;
      }
    }
    int flag1 = 0;
    for (int i = 0; i < t; i++) {
      if (s[i] == ' ')
        continue;
      if (s[i] >= 'A' && s[i] <= 'Z') {
        s[flag1] = s[i] + 32;
        flag1++;
      } else {
        s[flag1] = s[i];
        flag1++;
      }
    }
    bool flag3 = false;
    for (int j = 0; j < flag; j++) {
      if (a[j] != s[j])
        flag3 = true;
    }
    if (flag3 == true) {
      printf("no\n");
    }
    if (flag3 == false) {
      printf("yes\n");
    }
  }
  return 0;
}
