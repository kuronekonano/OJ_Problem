#include <stdio.h>
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    if (n == 1) {
      printf("-1\n");
      continue;
    }
    printf("%d %d %d\n", n, n + 1, n * (n + 1));
  }
}
/// ��һ��n,��2/n=1/x+1/y+1/z�е�x y z�����ж��
/// 2/n=1/n+1/n��������Ϊx!=y!=z
/// ���԰�����һ��1/n�ֿ��Էֽ��[1/(n+1)]+[1/n*(n+1)]
/// ����������n  n+1   n*(n+1)
