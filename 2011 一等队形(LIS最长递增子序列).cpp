#include <stdio.h>  ///��������һ��������ߵ���
#include <string.h> ///�������Լ����ҵ���ֱ��������������У�������nlogn�ķ�������ΪĿ����Ҫ�õ���0����ĳ������λ�����������
int main() /// ����ͷ����һ������������к�ÿ�����ֵ�maxn[i]��minn[i]������ʾ������
{
  int n, a[105], maxn[105], minn[105];
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    memset(maxn, 0, sizeof(maxn));
    memset(minn, 0, sizeof(minn));
    maxn[0] = 1;
    minn[n - 1] = 1;
    for (int i = 1, x = n - 2; i < n; i++, x--) {
      int flag = 0, flag2 = 0;
      for (int j = 0; j < i; j++)
        if (a[i] > a[j] && maxn[j] > flag)
          flag = maxn[j];
      maxn[i] = flag + 1;
      for (int j = n - 1; j > x; j--)
        if (a[x] > a[j] && minn[j] > flag2)
          flag2 = minn[j];
      minn[x] = flag2 + 1;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
      if (ans < maxn[i] + minn[i] - 1)
        ans = maxn[i] + minn[i] - 1;
    printf("%d\n", n - ans);
  }
}
