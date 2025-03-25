#include <bits/stdc++.h> ///��n�����ӣ�ÿ�����ӳ��ִ�СΪdi�ĸ���Ϊpi����id˳��������ӣ�ÿ�������ȵ�ǰ��ʯ��ľͻ������ʸ�����������
#define LL                                                                     \
  long long /// ��״�����д洢��id����ʯû��di��ô��ĸ��ʣ���ô�����ڵ�id��λ�ø�����di��ô�����ʯ����Ҫ��֤����֮ǰ����ʯ����diС
#define M(a, b) memset(a, b, sizeof a)
#define pb(x) push_back(x)
#define lowbit(x) x & (-x)
using namespace std;
const int maxn = 1e5 + 7;
const int p = 998244353;
LL qp(LL a, LL b) {
  LL ans = 1;
  while (b) {
    if (b & 1)
      ans = ans * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return ans;
}
struct node {
  LL val, id, pp;
  bool operator<(const node &a) const {
    if (val == a.val)
      return id < a.id;
    return val > a.val;
  }
} a[maxn];
LL tre[maxn];
int n;
LL inv = qp(
    100,
    p - 2); /// ע����Ŀ�����Ķ���*100֮��ĸ��ʣ����Ҫ*100����Ԫ���������ĸ���
void update(int pos, LL val) {
  for (int i = pos; i <= n; i += lowbit(i))
    tre[i] = tre[i] * val % p; /// ��״�������ǰ׺��
}
LL query(int pos) {
  LL ans = 1;
  for (int i = pos; i; i -= lowbit(i))
    ans = ans * tre[i] % p;
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%lld%lld", &a[i].pp, &a[i].val), a[i].id = i;
  sort(a + 1, a + 1 + n);
  fill_n(tre, n, 1LL); /// ��ʼ��ȫΪ1
  LL ans = 0;
  for (int i = 1; i <= n; i++) /// ����ʯ�Ӵ�С��˳�������״���飬����ÿ�β�ѯʱ���ǲ�ѯ��id֮ǰ��û��ȡ��
                               /// С���Լ�id���Ҵ�С���Լ������ʯ�ĸ���
  {
    ans = (ans + query(a[i].id - 1) * a[i].pp % p * inv % p) %
          p; /// �Ȳ�ѯ���Լ�С��id�ı��Լ������ʯ��ȡ�ĸ���
    update(a[i].id, ((LL)100 - a[i].pp) * inv %
                        p); /// Ȼ���ٸ���ȡ��������ʯ�ĸ��ʵ���״������
  }
  printf("%lld\n", ans);
}
