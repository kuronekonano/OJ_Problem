#include <algorithm>
#include <iostream>
#include <stdio.h> ///�ɱ�������������Ų�����ͬ������������ɸ��Ԥ�������ÿ�����ֱ���Ϊ�����Ĵ���
#include <string.h>
using namespace std;
int a[10008];
int n;
void inti() {
  a[1] = 1;
  for (int i = 2; i <= 10000; i++) {
    if (!a[i])
      a[i] = a[1] + 1;
    for (int j = i * 2; j <= 10000; j += i)
      a[j] = 1 + a[i];
  }
}
int main() {
  inti();
  while (scanf("%d", &n) != EOF) {
    int ans = 0;
    for (int i = 1; i <= n; i++)
      if (a[i] > ans)
        ans = a[i];
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++)
      printf("%d%c", a[i], i == n ? '\n' : ' ');
  }
}
