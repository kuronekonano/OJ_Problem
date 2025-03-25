#include <stdio.h>
#include <string.h>
int main() {
  char commed[15], wer;
  bool r = false, w = false, x = false;
  while (scanf("%s", commed) != EOF) {
    if (strcmp(commed, "show") == 0) {
      int sum = 0;
      if (r)
        sum += 4;
      if (w)
        sum += 2;
      if (x)
        sum += 1;
      printf("%d\n", sum);
    }
    if (strcmp(commed, "add") == 0) {
      getchar();
      scanf("%c", &wer);
      if (wer == 'a') {
        r = true;
        w = true;
        x = true;
      }
      if (wer == 'r')
        r = true;
      if (wer == 'w')
        w = true;
      if (wer == 'x')
        x = true;
    }
    if (strcmp(commed, "del") == 0) {
      getchar();
      scanf("%c", &wer);
      if (wer == 'a') {
        r = false;
        w = false;
        x = false;
      }
      if (wer == 'r')
        r = false;
      if (wer == 'w')
        w = false;
      if (wer == 'x')
        x = false;
    }
  }
}
