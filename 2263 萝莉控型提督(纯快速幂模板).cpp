#include <stdio.h>
const long long Maxn = 1000000007; /// ģ���������ô��ʱ�������������
int main() {
  long long t, a, n;
  scanf("%lld", &t); /// ע��������������ͺܴ���
  while (t--)        /// ������ģ��
  {
    scanf("%lld%lld", &a, &n);
    long long ans = 1; /// ���ڴ洢���
    while (n != 0)     /// ֻҪ�ݴβ�Ϊ0�ͼ�����
    {
      if (n % 2 != 0) /// ���������ݴ�
      {
        ans = ((ans % Maxn) * (a % Maxn)) % Maxn; /// ������һ��a����������
      }
      a = ((a % Maxn) * (a % Maxn)) %
          Maxn; /// Ȼ��ʣ�µ��ݴξ���ż������,��ż���ݴγ˵�һ���������γ�һ���������٣�ֵ�ϴ�Ĵ��ͳ���
      n /= 2;   /// ÿ�κϲ��ݴΣ��ݴ���ԭ����һ��
    }
    printf("%lld\n", ans);
  }
}
