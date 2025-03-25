#include <bits/stdc++.h>
#define LL long long
#define M(a, b) memset(a, b, sizeof a)
#define pb(x) push_back(x)
using namespace std;
const int maxn = 2e5 + 7;
const int mod = 1000000007;
int n, m, k;
struct node {
  int x, t,
      op; /// op��ʾ������ʶ����ѯ���Ǹ��£�t��ʾ����˳���ţ�x��ʾ����λ�ã�������
  LL y; /// x ��ʾ�У�y��ʾ���ӵ�ֵ
} pro[maxn], update[maxn],
    query[maxn]; /// pro��¼������update������²�����query�����ѯ����
LL ans[maxn], mp[45][maxn], C[maxn][45]; /// ans��¼ÿ����ѯ�����Ľ�������������
                                         /// mp��ʾʵ�ʾ���,C��ʾԤ���������
void init() /// Ԥ���������
{
  for (int i = 0; i <= maxn; i++)
    C[i][0] = 1;
  for (int i = 1; i <= maxn; i++)
    for (int j = 1; j <= 40; j++)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
}
void CDQ(int l, int r) {
  int mid = (l + r) >> 1; /// ���ֲ���
  if (l >= r)
    return;
  if (mid - l + 1 >= 1000) /// CDQ�õ��Ĳ��������Ǵ���2000������
  {
    for (int i = 0; i <= n; i++)
      mp[0][i] = 0; /// ��ʼ��
    for (int i = l; i <= mid; i++)
      if (!pro[i].op)
        mp[0][pro[i].x] =
            (mp[0][pro[i].x] + pro[i].y) % mod; /// ���������(ֻ���µ�һ��)
    for (int i = 1; i <= k + 1;
         i++) /// ֱ�Ӵӵ�һ�д��ݵ���k+1��(�������ݣ��൱��Ҳ������ǰ׺��)
      for (int j = 1; j <= n; j++)
        mp[i][j] = (mp[i - 1][j] + mp[i][j - 1]) % mod; /// ֱ�Ӽ���
    for (int i = mid + 1; i <= r; i++)
      if (pro[i].op)
        ans[pro[i].t] = (ans[pro[i].t] + mp[k + 1][pro[i].x]) % mod;
  } /// �������ѯ�𰸸�ֵ����֮ǰ��ߵ�Ӱ��ֱ�Ӵ��ݵ�ʵ�ʾ����У�������ans
  else {
    int upt = 0, qpt = 0; /// ����������
    for (int i = l; i <= mid; i++)
      if (!pro[i].op)
        update[upt++] = pro[i]; /// �ҵ�������ĸ�����
    for (int i = mid + 1; i <= r; i++)
      if (pro[i].op)
        query[qpt++] = pro[i]; /// ������Ĳ�ѯ��
    for (int i = 0; i < upt; i++)
      for (int j = 0; j < qpt; j++)
        if (update[i].x <= query[j].x)
          ans[query[j].t] =
              (ans[query[j].t] +
               update[i].y * C[k + query[j].x - update[i].x][k] % mod) %
              mod;
  }
  CDQ(l, mid); /// �ȴ�������ٴ����ұߣ������ұ߻�õ���ߵ�Ӱ��
  CDQ(mid + 1, r);
}
int main() {
  M(ans, -1);
  init();
  scanf("%d%d%d", &n, &m, &k); /// n�У�m�β���,��ѯ��k��
  k--;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &pro[i].op, &pro[i].x);
    pro[i].t = i;
    if (pro[i].op)
      ans[i] = 0;
    else
      scanf("%lld", &pro[i].y);
  }
  CDQ(1, m);
  for (int i = 1; i <= m; i++)
    if (ans[i] != -1)
      printf("%lld\n", ans[i]);
}
