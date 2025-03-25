#include <stdio.h>
#include <string.h>
using namespace std;
char a[150];
int main() {
  //    freopen("ans.txt","w",stdout);
  int cnt = 0, flag = true;
  while (scanf("%s", a) != EOF) {
    if (a[0] == '<') {
      if (a[1] == 'b')
        puts(""), cnt = 0, flag = true;
      else {
        if (!flag)
          puts("");
        printf("---------------------------------------------------------------"
               "-----------------\n");
        cnt = 0;
        flag = true;
      }
    } else {
      if (cnt + strlen(a) + 1 > 80)
        puts(""), cnt = 0, flag = true;
      if (flag == false)
        printf(" "), cnt++;
      else
        flag = false;
      printf("%s", a);
      cnt += strlen(a);
    }
  }
  if (!flag)
    printf("\n");
}
