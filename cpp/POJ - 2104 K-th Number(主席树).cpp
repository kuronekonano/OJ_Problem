#include <algorithm>
#include <stdio.h> ///�����k��ֵ:��ϯ��
#include <vector>
#define LL long long
#define M(a, b) memset(a, b, sizeof a)
#define pb(x) push_back(x)
using namespace std;
const int maxn = 1e6 + 7;
struct node {
  int l, r, sum;
} tre[maxn << 2];
int n, m, cnt, root[maxn], a[maxn], x, y,
    k; /// cnt��ʾ�߶����ڵ�������Ҳ�ǽڵ���
vector<int> q;
int getid(int x) { return lower_bound(q.begin(), q.end(), x) - q.begin() + 1; }
void update(
    int l, int r, int &x, int y,
    int pos) /// ����:��߽磬�ұ߽磬���Ϊx�Ľڵ㣬��ʷ�汾�ڵ㣬��ɢ��֮���ֵ
{
  tre[++cnt] = tre[y];
  tre[cnt].sum++;
  x = cnt;
  if (l == r)
    return;
  int mid = (l + r) >> 1;
  if (mid >= pos)
    update(l, mid, tre[x].l, tre[y].l, pos);
  else
    update(mid + 1, r, tre[x].r, tre[y].r, pos);
}
int query(int l, int r, int x, int y, int k) {
  if (l == r)
    return l;
  int mid = (l + r) >> 1;
  int sum = tre[tre[y].l].sum - tre[tre[x].l].sum;
  if (sum >= k)
    return query(l, mid, tre[x].l, tre[y].l, k);
  else
    return query(mid + 1, r, tre[x].r, tre[y].r, k - sum);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]), q.pb(a[i]); /// ��������
  sort(q.begin(), q.end()),
      q.erase(unique(q.begin(), q.end()), q.end()); /// ȥ����ɢ��
  for (int i = 1; i <= n; i++)
    update(1, n, root[i], root[i - 1],
           getid(a[i])); /// ������a˳���������ȡ����ɢ�����ֵ������ϯ��
  for (
      int i = 1; i <= m;
      i++) /// ��1��n�����䣬root[i]��ʾ��i���߶�����������������һ���߶�������Ҫ���µ�λ����
           /// ֵa[i]��ɢ��֮���λ�ã�ά������ǰ׺��
  {
    scanf("%d%d%d", &x, &y, &k);
    printf("%d\n", q[query(1, n, root[x - 1], root[y], k) - 1]);
  }
  return 0;
}
/***
����Ҳ��������ǰ׺�����˼�����������������⣬����ֻ��Ҫ����n�š�ǰ׺���߶������У���i��
ά��[1,i]���У��������Ǵ�����������l, rʱ�Ϳ���ͨ����������[1,l - 1],
[1,r]�����У�Ȼ������
�Ĵ������������������С�Ϊʲô������Ӽ������ʣ����Ǽ򵥷���һ�¾ͺ����׵ó������������[1,l
- 1] ����x����С��һ��������[1,r]����y����С���Ǹ�������ô������[l,r]�о���y - x
����С���Ǹ����ˣ�
�����ͺܺ����Ϊʲô������Ӽ��ˣ����⣬ÿ�����Ľṹ��һ��������һ��Ҷ�ڵ�Ϊn�����߶�����
***/
