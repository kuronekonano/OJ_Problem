#include <algorithm>
#include <stdio.h>
using namespace std;
int main() {
  int n, i, j, a[1005];
  while (scanf("%d", &n) != EOF) {
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    sort(a, a + n);          /// ����
    int flag = 0, i = n - 1; /// �����ֵ��ʼ���
    while (flag != n) {
      flag++; /// ���������
      printf("%d%c", a[i], flag == n ? '\n' : ' ');
      if (flag == n)
        break;
      flag++;
      printf("%d%c", a[n - i - 1], flag == n ? '\n' : ' ');
      i--;
    }
  }
  return 0;
}
