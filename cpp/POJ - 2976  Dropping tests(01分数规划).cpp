#include <algorithm>
#include <stdio.h>   ///01�����滮
using namespace std; /// ��ĿҪ�� ai / �� bi ֵ�����ô�в���ʽ �� ai / ��
                     /// bi �� x ��������ֵx������
const int maxn =
    1e3 +
    8; /// ����ʽ���Ի�Ϊ   �� ai �� �� bi *x  ---->   �� ai - �� bi *x ��0
       /// ��ô���㦲 ai - �� bi *x ��ֵ �ж����ǰn-k������Ƿ���ڵ���0,
const double eqs =
    1e-6; /// ���ڵ���0��ʾ�������������������ָ����x�������ִ𰸣�Ҳ������ȷɾ��k��������»�ø����x
int a[maxn],
    b[maxn]; /// ��������ͽ��С��0��˵������ʽ��������ѡ������ֵ̫��ai�޷�����
double mx[maxn];
int n, k;
bool judge(double x) /// �������ֵ
{
  for (int i = 1; i <= n; i++)
    mx[i] = a[i] - x * b[i];
  sort(mx + 1, mx + 1 + n);
  double ans = 0;
  for (int i = n; i > k; i--)
    ans += mx[i]; /// ȡǰn-k�����ֵ���������
  return ans >= 0;
}
int main() {
  while (scanf("%d%d", &n, &k) && (n || k)) {
    for (int i = 1; i <= n; i++)
      scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
      scanf("%d", &b[i]);
    double l = 0, r = 1;
    while (r - l > eqs) {
      double mid = (l + r) / 2;
      if (judge(mid))
        l = mid;
      else
        r = mid;
    }
    printf("%.0f\n", l * 100);
  }
}
