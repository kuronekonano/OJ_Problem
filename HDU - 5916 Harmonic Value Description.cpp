#include <stdio.h> ///�����k��2*k��ʹ�ù�Լ��Ϊk��������ʣ�µ����������������Ҳ��������֮��Ϊ1ʱ����
int main() /// ʹʣ�µ�����Լ��Ϊ1��������������С�������ǹ�Լ��ȫΪ1���ڴ˻�����+k�����ǵ�kС�Ĺ�Լ��֮��
{
  int t, n, k, i,
      cas =
          0; /// ���û��������Ʋ���Ҫ�仯�����Ĺ�Լ��Ϊ1��ֻ�ճ���k�Ĺ�Լ������
  scanf("%d", &t);
  while (t--) {
    cas++;
    scanf("%d%d", &n, &k);
    printf("Case #%d: ", cas);
    printf("%d %d", 2 * k, k);
    for (i = k - 1; i >= 1; i--)
      printf(" %d", i);
    for (i = k + 1; i < 2 * k; i++)
      printf(" %d", i);
    for (i = 2 * k + 1; i <= n; i++)
      printf(" %d", i);
    printf("\n");
  }
}
