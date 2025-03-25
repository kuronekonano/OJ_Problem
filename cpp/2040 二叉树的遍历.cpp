#include <stdio.h>
int num = 0, a[108], n, b[108], c[108];
int find(int tmp, int l, int r) {
  for (int i = l; i < r; i++)
    if (a[i] == tmp)
      return i;
}
int halfpath(int bl, int br, int al, int ar) {
  // �ó�ǰ�������Ԫ�ص���������в�ѯλ��
  if (al == ar)
    return 0;
  int root =
      find(b[bl], al, ar); // �ҳ�ǰ������е�bl��Ԫ����������������е�λ��
  int len = root - al;     // ��������е�bl��Ԫ�ص�λ���
  halfpath(bl + 1, bl + 1 + len, al, al + len); // ������
  halfpath(bl + 1 + len, br, al + len + 1, ar); // ������
  c[num++] = a[root];
}
int main() {
  while (scanf("%d", &n) != EOF) {
    num = 0;
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]); // �������
    for (int i = 0; i < n; i++)
      scanf("%d", &b[i]); // ǰ�����
    halfpath(0, n, 0, n);
    for (int i = 0; i < n; i++)
      printf("%d ", c[i]);
    printf("\n");
  }
}
