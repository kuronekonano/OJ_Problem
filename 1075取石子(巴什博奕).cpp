#include <stdio.h>
int main() {
  int m, n;
  while (scanf("%d%d", &n, &m) != EOF) {
    if (n % (m + 1) !=
        0) // ��ʲ���ȣ�Bash Game����
           // ��Ȼ�����n=m+1����ô����һ�����ֻ��ȡm�������ԣ�������ȡ�����߶��ٸ���ȡ�߶��ܹ�һ������ʣ�����Ʒ������ȡʤ��������Ƿ��������ȡʤ�ķ���
    {
      printf("JiaozhuV5!\n"); // Ҫ���Է�����m+1�ı�������ʱ��ȡ����ʤ
    } else
      printf("LeyniV5!\n");
  }
  return 0;
}
