#include <bits/stdc++.h> ///01�����滮
using namespace std;
const int maxn = 1e5 + 7;
const double eqs = 1e-6;
int n, k, s[maxn], c[maxn];
double mx[maxn];
bool judge(double x) /// ע�����ﲻ��ʽ���ߵ�s[i]���ܵ���
{
  for (int i = 0; i < n; i++)
    mx[i] = s[i] * c[i] -
            x * s[i]; /// ����Ŀ��������ʽ ��(s[i]*c[i])/ ��s[i] �� x���Ƴ�
                      /// ��(s[i]*c[i])- x * ��s[i] �� 0,ֱ�Ӷ���x��ֵ����
  sort(mx, mx + n);
  double ans = 0;
  for (int i = n - 1; i > k - 1; i--)
    ans += mx
        [i]; /// �������ڿγ̿�ѡǰn-k������ͼ��õ�����ʽ����ͣ���0�Ƚϣ�����0��x�Ϸ�����̽�����x
  return ans >= 0;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++)
    scanf("%d", &s[i]);
  for (int i = 0; i < n; i++)
    scanf("%d", &c[i]);
  double l = 0, r = 1e6 + 7; /// ���ַ�Χʱ���ֵ1000*1000*100000/100000
  while (r - l > eqs)        /// ���ִ�
  {
    double mid = (l + r) / 2;
    if (judge(mid))
      l = mid;
    else
      r = mid;
  }
  printf("%f\n", l);
}
