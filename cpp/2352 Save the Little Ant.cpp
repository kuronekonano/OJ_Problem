#include <stdio.h>
int main() {
  int a[100005], n;
  while (scanf("%d", &n) != EOF) {
    long long Max = 0, maxi = 0,
              ans = 0; /// �ӵ㣬��ƽ����0�����Ը������ǿӣ����ܱ�Ե��˭
    for (int i = 0; i < n; i++) /// ������2e5*1e5��Ҫ��long long
    {
      scanf("%d", &a[i]);
      if (a[i] < 0)
        ans += -a[i],
            a[i] =
                0; /// �ҵ�һ�����������ֵ��λ�ã�Ȼ��������������ֵ��λ��ɨ
      if (a[i] >
          Max) /// ÿ�θ�������ɨ��ȥ�����ֵ������������ֵ���������ֵ�������ȥ����ӣ������Ͱ�����һ���߽綼��Ϊ���ֵ����һ�����ҵı߽��ǻ���±仯�����ֵ
      {
        Max = a[i];
        maxi = i;
      }
    } /// �������е����ֵ���ڼ��㷶Χ�ڣ���Ϊ����Ϊ�˱߽�
    int maxx = 0;
    for (int i = 0; i < maxi; i++)
      if (a[i] > maxx)
        maxx = a[i];
      else
        ans += maxx - a[i];
    maxx = 0;
    for (int i = n - 1; i > maxi; i--)
      if (a[i] > maxx)
        maxx = a[i];
      else
        ans += maxx - a[i];
    printf("%lld\n", ans);
  }
}
