#include <stdio.h> /// ֱ��whileģ�⣬ע�⵱����'��"ʱ��Ҫ������һλ�����һλ�����������֮��ҲҪ����'��"�����ж������ַ�
#include <string.h>
int main() {
  char a[2000];
  while (gets(a) != NULL) {
    int n = strlen(a);
    bool flag1 = false, flag2 = false;
    int i = 0;
    while (i < n) {
      while (a[i] == ' ')
        i++;
      if (a[i] == '\'')
        flag1 = true;
      if (a[i] == '"')
        flag2 = true;
      if (!flag1 && !flag2) {
        while (a[i] == ' ' && i < n)
          i++;
        while (a[i] != ' ' && a[i] != '\'' && a[i] != '"' && i < n)
          printf("%c", a[i++]);
        printf("\n");
      } else if (flag1) {
        i++;
        while (a[i] != '\'' && i < n)
          printf("%c", a[i++]);
        i++;
        printf("\n");
        flag1 = false;
      } else if (flag2) {
        i++;
        while (a[i] != '"' && i < n)
          printf("%c", a[i++]);
        i++;
        printf("\n");
        flag2 = false;
      }
    }
    printf("\n");
  }
}
