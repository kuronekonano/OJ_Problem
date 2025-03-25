#include <stdio.h>
void dfs(int x) {
  if (x == 0)
    printf("0");
  else {
    int tmp = x, bin[30], i = 0;
    while (tmp) /// ����ת��
    {
      bin[i++] = tmp % 2;
      tmp /= 2;
    }
    bool flag = false; /// �Ӻű��
    for (
        int j = i - 1; j >= 0;
        j--) /// �����λ��ʼ����������λ������һ���µ��ݴΣ�������1Ҳ����2���������еݹ�������㣬����ֱ���������
    {
      if (bin[j]) {
        if (flag)
          printf("+");
        if (!flag)
          flag = true;
        if (j != 1) {
          printf("2(");
          dfs(j);
          printf(")");
        } else
          printf("2");
      }
    }
  }
  return;
}
int main() /// ����ÿ�����������Ϊ2���ƣ�Ȼ����Եõ�����2�ļ��η��ӺͶ��ɵ�
{
  int n;
  while (scanf("%d", &n) != EOF) {
    dfs(n);
    printf("\n");
  }
}
