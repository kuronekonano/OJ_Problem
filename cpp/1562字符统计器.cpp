#include <stdio.h>
#include <string.h>
struct strings {
  char a[108];
  int upper = 0, lower = 0, punct = 0, blank = 0, digit = 0;
} chuan[108];
int main() {
  int t, i;
  scanf("%d", &t);
  getchar();
  for (i = 1; i <= t; i++) {
    gets(chuan[i].a);
    int n = strlen(chuan[i].a);
    int j;
    for (j = 0; j < n; j++) {
      if (chuan[i].a[j] >= 'A' && chuan[i].a[j] <= 'Z') {
        chuan[i].upper++;
      } else if (chuan[i].a[j] >= 'a' && chuan[i].a[j] <= 'z') {
        chuan[i].lower++;
      } else if (chuan[i].a[j] == ' ') {
        chuan[i].blank++;
      } else if (chuan[i].a[j] >= '0' && chuan[i].a[j] <= '9') {
        chuan[i].digit++;
      } else {
        chuan[i].punct++;
      }
    }
  }
  printf(" UPPER LOWER PUNCT BLANK DIGIT\n");
  for (i = 1; i <= t; i++) {
    printf("%6d%6d%6d%6d%6d\n", chuan[i].upper, chuan[i].lower, chuan[i].punct,
           chuan[i].blank, chuan[i].digit);
  }
  return 0;
}
