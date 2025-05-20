#include <algorithm>
#include <math.h>
#include <stdio.h> ///莫队
#include <string.h>
#define LL long long
using namespace std;
const LL maxn = 2000000; /// 因为有异或操作，最大值开大
struct node              /// 记录询问的左右边界和询问的id
{
  int l, r, id;
} qu[maxn];
int pos[maxn]; /// 对数列中每个数进行分块处理，并记录每个id被分到的块序号
LL ans[maxn];  /// 记录每个询问的ans
LL flag[maxn]; /// 记录异或结果出现的次数
bool cmp(node a, node b) /// 分块排序
{
  if (pos[a.l] == pos[b.l])
    return a.r < b.r;
  return pos[a.l] < pos[b.l];
}
LL a[maxn]; /// 异或前缀和，可能会超int
int L = 1, R = 0, n, m,
    k; /// 边界指针作为全局变量不断在原来基础上移动，初始化为1和0，因为L可能左移，而R只会右移
LL cnt =
    0; /// 记录当L和R边界指针指向一定范围时的序列数存储，这个值将根据边界变化不断变化
void add(int x) {
  cnt += flag
      [a[x] ^
       k]; /// add操作中，增加一个位置的信息，因为a[x]^a[y]=k则表示前缀和中x+1异或到y这段区间的异或和，那么a[x]^k=a[y],如果是异或值超出了LR区间范围，那么因为没有被更新到该结果，因此目前那个位置的异或值前缀和为0，不会造成影响
  flag[a[x]]++; /// 对于当前位置的前缀异或和的值，出现次数增加
}
void del(int x) {
  flag[a[x]]--;
  cnt -= flag[a[x] ^ k];
}
int main() {
  while (scanf("%d%d%d", &n, &m, &k) != EOF) {
    int sz = sqrt(n);
    for (int i = 1; i <= n; i++) {
      scanf("%lld", &a[i]);
      a[i] = a[i - 1] ^ a[i]; /// 异或前缀和
      pos[i] = i / sz;        /// 分块,记录每个下标属于哪个分块的数字pos
    }
    for (int i = 1; i <= m; i++) /// 输入并记录M次询问
    {
      scanf("%d%d", &qu[i].l, &qu[i].r);
      qu[i].id = i;
    }
    flag[0] = 1;
    sort(qu + 1, qu + m + 1, cmp);
    for (int i = 1; i <= m; i++) {
      while (L < qu[i].l)
        del(L - 1),
            L++; /// 若已知范围的左边界小于询问范围的左边界，说明已知范围较大，删除左边界-1位置信息，并移动左边界指针
      while (L > qu[i].l)
        L--,
            add(L -
                1); /// 若已知范围左边界大于询问范围的左边界，说明已知范围较小，应左移L指针拓宽范围计数增加L-1位置对ans查询结果的影响
      while (R < qu[i].r)
        add(++R); /// 若已知范围右边界小于询问范围右边界，说明已知范围较小，应右移右边界指针增加R+1位置对当前结果的影响
      while (R > qu[i].r)
        del(R--); /// 若已知范围右边界大于询问范围右边界，说明已知范围较大，应左移右边界指针消除多余范围对结果的影响
      ans[qu[i].id] = cnt; /// 最后移动指针到询问位置，则得到cnt即当前询问结果
    }
    for (int i = 1; i <= m; i++)
      printf("%lld\n", ans[i]);
  }
}
