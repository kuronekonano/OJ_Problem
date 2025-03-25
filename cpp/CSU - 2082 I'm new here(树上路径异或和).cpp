#include <algorithm>
#include <stdio.h> ///����������������ͣ��ɸ������㵽���ڵ������ ���õ�
#include <string.h>
#include <vector>
#define LL long long
using namespace std;
const int maxn = 100005;
struct edge {
  int to, val;
  edge() {}
  edge(int a, int b) {
    to = a;
    val = b;
  }
};
int n, t;
int xorsum[maxn], cnt[40];
vector<edge> q[maxn];
void dfs(int rt, int pre) {
  for (int i = 0; i < q[rt].size(); i++) {
    edge tmp = q[rt][i];
    if (tmp.to != pre) {
      xorsum[tmp.to] = xorsum[rt] ^ tmp.val; /// ���ڵ㵽ÿ���ڵ������
      dfs(tmp.to, rt);
    }
  }
  for (int i = 0; i < 31; i++)
    if (xorsum[rt] & (1 << i))
      cnt[i + 1]++; /// ��¼ÿ�����͵Ķ�����λ��1���ֵĴ���
}
LL binary[40];
int main() {
  for (int i = 0; i < 31; i++)
    binary[i + 1] = 1 << i;
  scanf("%d", &t);
  while (t--) {
    memset(cnt, 0, sizeof cnt);
    int from, to, val;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
      q[i].clear();
    for (int i = 1; i < n; i++) {
      scanf("%d%d%d", &from, &to, &val);
      q[from].push_back(edge(to, val));
      q[to].push_back(edge(from, val));
    }
    xorsum[1] = 0;
    dfs(1, 0);
    LL ans = 0;
    for (int i = 1; i <= 31; i++)
      ans += binary[i] * (n - cnt[i]) * cnt[i];
    printf("%lld\n", ans);
  }
}
/// �õ����ڵ㵽ÿ���ڵ�λ�õ����ͺ���ô�����������������ֻ��Ҫ��������·�����ͽ���������������Ϊ����Ҫ�����������·�����͵ļӺ�
/// ������������·�����֮��ֻȡ������λ��λ1��ֵ���㣬��ôֻ��0��1�������Ż��ڶ�����λ�ϵõ�1��ֱ��������1��0ƥ�䣬�õ�����1�����������ת��Ϊʮ������͡�
