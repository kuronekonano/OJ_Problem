#include <bits/stdc++.h>
#define LL long long
#define M(a, b) memset(a, b, sizeof a)
using namespace std;
LL n, dp[15][110][110][110],
    a[15]; /// һά��¼��λ���ȣ���ά��¼��λ�Ӻͣ���ά��¼ʵ����ͬ��ģ����ά��¼����ģ��
LL dfs(int pos, int sum, int numod, bool limit, int calnum) {
  if (pos == -1)
    return sum == calnum &&
           !numod; /// ���������ĵ����жϣ�����λ�Ӻ͵���ģ������ʵ��������ȡģ�����0˵����beautiful
                   /// number
  if (!limit && dp[pos][sum][numod][calnum] != -1)
    return dp[pos][sum][numod][calnum];
  LL ans = 0;
  int maxup =
      limit
          ? a[pos]
          : 9; /// �жϸñ�����λ�Ƿ������ޣ���������ֻ�ܴﵽ����N�ĸ�λ��������Ա���0~9
  for (int i = 0; i <= maxup; i++) {
    if (sum + i > calnum)
      break; /// �Ӻͳ���������ȡģ��
    ans += dfs(pos - 1, sum + i, (numod * 10 + i) % calnum,
               limit && i == a[pos], calnum);
  }
  if (!limit)
    dp[pos][sum][numod][calnum] =
        ans; /// �����������ֵ����ʱ�����ans�����õģ��ܹ���֮��ļ���ֱ��������õģ���¼��dp������
  return ans;
}
int main() {
  int t, cas = 0;
  M(dp, -1);
  scanf("%d", &t);
  while (t--) {
    int cnt = 0;
    scanf("%lld", &n);
    while (n) /// ��ָ�λ
    {
      a[cnt++] = n % 10;
      n /= 10;
    }
    LL ans = 0;
    for (int i = 1; i <= 108; i++)
      ans += dfs(
          cnt - 1, 0, 0, true,
          i); /// ����ÿһ����λ�ͣ�����ͬ��ģ��ģ�������ۼ�ʵ����ȡģΪ0ʱ�Ƿ���������
    printf("Case %d: %lld\n", ++cas, ans);
  }
}
