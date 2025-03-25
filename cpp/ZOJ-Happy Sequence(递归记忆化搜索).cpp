#include <stdio.h> ///�ݹ���仯(�ݹ�+DP)
#include <string.h>
#define MOD 1000000007
#define ll long long
int dp[2003][2003], data[2002][2002];
int t, n, m;
ll ans;
void init() /// 1~2000������������
{
  memset(data, 0, sizeof(data));
  memset(
      dp, 0,
      sizeof(
          dp)); /// DP���������в��������ж�ͨ�ã����ÿ�����ݶ�����Ӧ����DP�����������Թ��´�ʹ��
  for (int i = 1; i <= 2000; i++) {
    int flag = 0;
    for (int j = 1; j <= i; j++)
      if (i % j == 0)
        data[i][++flag] = j;
    data[i][0] =
        flag; /// ģ������0λ���ж������ӣ�Ȼ������������i�����ӷֱ���˭
  }
}
ll dfs(int now, int len) /// DFS������������
{
  if (now == 1 || len == 1)
    return 1; /// ����ǰ������Ϊ1ʱ�������ټ�����1�����ӣ��ݹ���ڣ����������������������г��ȵ�������ʱ(ʣ��1)������������
  ll tmp = 0; /// ��ʱ�洢������NOWʱ������������
  for (int i = 1; i <= data[now][0]; i++) /// DP��¼
  {
    if (dp[len - 1][data[now][i]])
      tmp =
          ((tmp % MOD) + (dp[len - 1][data[now][i]] % MOD)) %
          MOD; /// ��Ҫ���㳤��Ϊlen����ǰֵΪnow�������ж�����ʱ���ý���ɳ���Ϊlen-1����ǰֵΪnow��һ�����ӵ����м̳ж���
    else
      tmp =
          ((tmp % MOD) + (dfs(data[now][i], len - 1) % MOD)) %
          MOD; /// ����Ҫ���ҵ����л�δ�����ж����֣���ô�ݹ�����������е�������
  }
  dp[len][now] =
      tmp; /// �������now���������ӵ��������֮�󣬼���len���ȣ���ǰ��now��
           /// ��������
  return tmp;
}
int main() {
  init();
  scanf("%d", &t);
  while (t--) {
    ans = 0; /// ���մ�
    scanf("%d%d", &n, &m);
    for (int i = n; i >= 1; i--)
      ans =
          ((ans % MOD) + (dfs(i, m) % MOD)) %
          MOD; /// ��������n��������г���m��ʼ����������С�Ȼ�����μ�С���е���ֵ�����ҡ�
    printf("%lld\n", ans);
  }
}
