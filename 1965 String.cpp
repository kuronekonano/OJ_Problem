#include <stdio.h>  ///gets����������һ��scanf��������������
#include <string.h> ///����ֹͣwhile�ã�=NULL��������Ϊgets��ȡ�س�����ʲô���������ʱ����жϳ�yes����ʱӦ��ʲô�������
int main() {
  char a[1005];
  int n, i, j, flag;
  while (gets(a) != NULL) {
    if (strlen(a) ==
        NULL) /// Ϊ���������⣬Ҫ�ж����sΪ�գ����ͷ��ʼ�������Ͳ����������
    {
      continue;
    }
    flag = 0;
    n = strlen(a);
    for (i = 1; i < n; i++) {
      for (j = 0; j < i; j++) {
        if (a[i] == a[j]) {
          flag++;
          continue;
        }
      }
    }
    if (flag != 0) {
      printf("no\n");
    } else if (flag == 0) {
      printf("yes\n");
    }
  }
  return 0;
}
