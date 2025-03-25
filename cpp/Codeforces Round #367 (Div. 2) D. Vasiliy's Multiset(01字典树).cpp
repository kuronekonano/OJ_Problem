#include <bits/stdc++.h> ///01字典树
#define LL long long
#define M(a, b) memset(a, b, sizeof a)
using namespace std;
const int maxn = 1e5 + 7;
int tre[maxn << 5][2];
int cnt[maxn << 5]; /// 标记节点走过次数，就不用关心原节点链接向哪个标号了
int q, tot = 0;
char flag[3];
void insert(int a, int rt, int add) {
  for (int i = 31; i >= 0; i--) {
    int x = (a >> i) & 1;
    if (!tre[rt][x]) {
      tre[rt][x] = ++tot;
      M(tre[tre[rt][x]], 0);
    }
    rt = tre[rt][x];
    cnt[rt] += add; /// 删除和插入就是对某个节点的经过次数计数
  }
}
int finds(int a, int rt) {
  int ans = 0;
  for (int i = 31; i >= 0; i--) {
    ans <<= 1;
    int x = (a >> i) & 1;
    if (tre[rt][!x] && cnt[tre[rt][!x]])
      rt = tre[rt][!x], ans |= 1; /// 必须同时符合两个条件才能往这条子树上走
    else
      rt = tre[rt][x];
  }
  return ans;
}
int main() {
  int tmp, rt = ++tot;
  M(tre[rt], 0);
  M(cnt, 0);
  scanf("%d", &q);
  while (q--) {
    scanf("%s", flag);
    scanf("%d", &tmp);
    if (flag[0] == '+')
      insert(tmp, rt, 1);
    else if (flag[0] == '-')
      insert(tmp, rt, -1);
    else
      printf(
          "%d\n",
          max(tmp,
              finds(
                  tmp,
                  rt))); /// 因为0一直在根部，因此必须检查一下这个数异或0(输出自己)和异或集合中某个数来取最大值
  }
  return 0;
}
