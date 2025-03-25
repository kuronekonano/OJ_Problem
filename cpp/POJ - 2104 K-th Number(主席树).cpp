#include <algorithm>
#include <stdio.h> ///区间第k大值:主席树
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
    k; /// cnt表示线段树节点数量，也是节点标号
vector<int> q;
int getid(int x) { return lower_bound(q.begin(), q.end(), x) - q.begin() + 1; }
void update(
    int l, int r, int &x, int y,
    int pos) /// 参数:左边界，右边界，标号为x的节点，历史版本节点，离散化之后的值
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
    scanf("%d", &a[i]), q.pb(a[i]); /// 输入序列
  sort(q.begin(), q.end()),
      q.erase(unique(q.begin(), q.end()), q.end()); /// 去重离散化
  for (int i = 1; i <= n; i++)
    update(1, n, root[i], root[i - 1],
           getid(a[i])); /// 按序列a顺序遍历，并取得离散化后的值更新主席树
  for (
      int i = 1; i <= m;
      i++) /// 从1到n的区间，root[i]表示第i个线段树，他的依存是上一个线段树，需要更新的位置是
           /// 值a[i]离散化之后的位置，维护的是前缀和
  {
    scanf("%d%d%d", &x, &y, &k);
    printf("%d\n", q[query(1, n, root[x - 1], root[y], k) - 1]);
  }
  return 0;
}
/***
我们也可以利用前缀和这个思想来解决建树这个问题，我们只需要建立n颗“前缀”线段树就行，第i树
维护[1,i]序列，这样我们处理任意区间l, r时就可以通过处理区间[1,l - 1],
[1,r]，就行，然后两者
的处理结果进行相加相减就行。为什么满足相加减的性质，我们简单分析一下就很容易得出。如果在区间[1,l
- 1] 中有x个数小于一个数，在[1,r]中有y个数小于那个数，那么在区间[l,r]中就有y - x
个数小于那个数了，
这样就很好理解为什么可以相加减了，另外，每颗树的结构都一样，都是一颗叶节点为n个的线段树。
***/
