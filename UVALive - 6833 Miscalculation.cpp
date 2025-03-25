#include <stdio.h>
#include <string.h>
int main() {
  char a[25];
  while (scanf("%s", a) != EOF) {
    int judge;
    scanf("%d", &judge);
    int len = strlen(a), sum = a[0] - '0';
    bool flag = false;
    for (int i = 1; i < len; i++) /// 顺序计算
      if (a[i] >= '0' && a[i] <= '9')
        sum = flag ? sum * (a[i] - '0') : sum + a[i] - '0';
      else
        flag = a[i] == '*' ? true : false;
    int num[20] = {0};
    num[0] = a[0] - '0';
    int ter = 0, nums = 0;
    for (int i = 1; i < len; i += 2) /// 优先级计算
      if (a[i] == '*')
        num[ter] = num[ter] * (a[i + 1] - '0');
      else
        num[++ter] = a[i + 1] - '0';
    for (int i = 0; i <= ter; i++)
      nums += num[i];
    if (judge == nums && judge != sum)
      printf("M\n");
    if (judge == sum && judge != nums)
      printf("L\n");
    if (judge == sum && judge == nums)
      printf("U\n");
    if (judge != sum && judge != nums)
      printf("I\n");
  }
}
