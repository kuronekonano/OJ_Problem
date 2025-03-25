#include <stdio.h>
#include <string.h>
int main() {
  char str[100005], str2[100005];
  int i, j, t, n;
  scanf("%d", &t);
  while (t--) {
    memset(str2, ' ', sizeof(str2));
    memset(str, ' ', sizeof(str));
    scanf("%s", str);
    n = strlen(str);
    j = 0;
    for (i = 0; i < n; i++) {
      if (str[i] == '@') {
        j = 0;
        continue;
      } else if (str[i] == '#') {
        j--;
        continue;
      } else {
        str2[j] = str[i];
      }
      j++;
    }
    str2[j] = '\0';
    printf("%s\n", str2);
  }
  return 0;
}
