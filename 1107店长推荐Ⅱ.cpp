#include <stdio.h>
#include <string.h>
int main() {
  char a[10008], b[205];
  int i, n, s, flag = 0, c[100], d[100];
  while (scanf("%s", a) != EOF) {
    memset(c, 0, sizeof(c)); // �ǵ��������
    memset(d, 0, sizeof(d));
    scanf("%s", b);
    s = strlen(a);
    n = strlen(b);
    for (i = 0; i < s; i++) {
      c[a[i] - '0']++;
    }
    for (i = 0; i < n; i++) {
      d[b[i] - '0']++; // �ֱ�洢�ؼ��ֺ��ַ������ַ�����Ƶ��
    }
    int k = 54181;
    for (i = 0; i < 80; i++) // ��󲻹�74���á�z��-'0'
    {
      if (d[i] != 0 &&
          c[i] / d[i] <
              k) // ����ÿ��������洢���ַ�����������������С����Сֵ���������С����ɵĹؼ��ֵ�����
      {
        k = c[i] / d[i];
      }
    }
    flag++;
    printf("Case %d: %d\n", flag, k);
  }
  return 0;
}
