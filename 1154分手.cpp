#include <math.h>
#include <stdio.h>
#include <string.h>
bool a[1000089];
void inti() {
  memset(
      a, true,
      sizeof(
          a)); /// ���ü򵥵���ѧ��
               /// ������㷨��ͨ���˻�����ʽ�������������������һ��Ϳ��Ա�����
  a[0] = a[1] = false;
  for (int i = 2; i <= 1000000; i++) {
    if (a[i]) {
      for (int j = i + i; j <= 1000000; j += i) {
        a[j] = false;
      }
    }
  }
}
int main() {
  int n, num;
  inti();
  while (scanf("%d", &n) != EOF) {
    num = sqrt(n);
    bool flag = true;
    for (int i = 2; i <= num; i++) /// ������Ҳ���ҳ�����һ�������ж���һ������
    {
      if (a[i] && n % i == 0) {
        int ans = n / i;
        if (a[ans]) {
          printf("Yes\n");
          flag = false;
          break;
        }
      }
    }
    if (flag) {
      printf("No\n");
    }
  }
  return 0;
}
