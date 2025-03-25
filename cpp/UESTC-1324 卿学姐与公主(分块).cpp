#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>
using namespace std;
const int maxn = 1e5 + 10;
int block, belong[maxn], l[maxn], r[maxn], n, q, num;
long long a[maxn], Max[maxn];
int build() {
  block = sqrt(n); /// �ֳ�sqrt(n)�飬Ҳ����block��ÿ��ĸ���
  num = n / block; /// num��ʾ���ֳɵĿ���
  if (num % block)
    num++; /// ���µĸ�������block����ʣ��ĵ����ֳ�һ��
  for (
      int i = 1; i <= num;
      i++) /// ��ÿ����ϱ߽磬ÿ�����߽����i-1����block(����)+1������i��ĵ�һ����
    l[i] = (i - 1) * block + 1,
    r[i] = i * block;          /// �ұ߽缴������i*block�ĸ���
  r[num] = n;                  /// ���һ����ұ߽�ֱ�ӱ��Ϊ��ֵn
  for (int i = 1; i <= n; i++) /// ��ÿ������Ǹ��������ĸ���
    belong[i] =
        (i - 1) / block + 1;     /// ��i����(i��1��ʼ)���ڵ�(i-1)/blcok+1�Ŀ�
  for (int i = 1; i <= num; i++) /// ��ʼ��ÿ������ֵ
  {
    /// ����num����
    for (int j = l[i]; j <= r[i];
         j++) /// ����ÿ�������߽�������ұ߽磬ȡ���ֵ��¼
      Max[i] = max(Max[i], a[j]);
  }
}
void updata(int x, int y) /// ����
{
  a[x] += y;
  Max[belong[x]] = max(Max[belong[x]], a[x]);
}
long long query(int x, int y) /// ��ѯ
{
  long long ans = 0;
  if (belong[x] == belong[y]) /// ����ѯ������ͬ��
  {
    for (int i = x; i <= y; i++) /// С��Χֱ�ӱ���
      ans = max(ans, a[i]);
    return ans;
  }
  for (int i = x; i <= r[belong[i]]; i++) /// ��ѯ�����䲻ͬ�飬�ȶ����������
    ans = max(ans, a[i]);
  for (int i = belong[x] + 1; i < belong[y];
       i++) /// �м��������鲿��ֱ�ӶԱȿ�����ֵ
    ans = max(ans, Max[i]);
  for (int i = l[belong[y]]; i <= y;
       i++) /// ���û��������Խ�Ŀ�Ҫ��������߽��������ѯλ��
    ans = max(ans, a[i]);
  return ans;
}
int main() {
  scanf("%d%d", &n, &q);
  int flag, x, y;
  memset(a, 0, sizeof(a));
  while (q--) {
    scanf("%d", &flag);
    if (flag == 1) {
      scanf("%d%d", &x, &y);
      updata(x, y);
    } else {
      scanf("%d%d", &x, &y);
      printf("%lld\n", query(x, y));
    }
  }
}
