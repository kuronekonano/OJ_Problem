#include <bits/stdc++.h> ///��ĿҪ��ÿ�μ�n-1�仨����ô�൱��ÿ����һ�仨�߶�����1�������û�����������л�����߻��Ĳ�࣬�������л�ƽ�ȵĴ���
#define LL                                                                     \
  long long /// ����������ǳ������������ģ�����-1����˶��������Ļ��߶ȣ�����г���3�䶼С�������������ô���ɱ���Ļ���ĳ�仨�����ɸ���
#define M(a, b)                                                                \
  memset(                                                                      \
      a, b,                                                                    \
      sizeof a) /// ���ֻ��Ƚϵ����̵Ļ��Ƿ��ܳ��ܼ���ô��Σ��ͱȽ���ǰ3�仨�Ƿ�С�ڱ�������
#define pb(x) push_back
using namespace std;
const int maxn = 1e5 + 7;
const int mod = 1000000007;
int t, n;
LL a[maxn];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
      scanf("%lld", &a[i]);
    sort(a + 1, a + 1 + n);
    int ma = a[n];
    LL ans = 0;
    for (int i = 1; i < n; i++)
      ans += ma - a[i];
    if (ans > a[3])
      printf("-1\n");
    else
      printf("%lld\n", ans);
  }
}
