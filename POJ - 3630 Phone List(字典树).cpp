#include <stdio.h> ///字典树建树同时检索
#include <string.h>
int tot, tre[100040][12]; /// 号码只有0-9因此比26个字母还要简单
bool vis[100050], ans;
int insert(
    char str[],
    int rt) { /// 要预防两种前缀重复的情况，一种是短的先出现，一种是长的先出现，如911和911245
  int len = strlen(str);
  for (int i = 0; i < len; i++) {
    int x = str[i] - '0';
    if (tre[rt][x] == 0) {
      tre[rt][x] = ++tot;
      memset(
          tre[tre[rt][x]], 0,
          sizeof(
              tre[tre[rt]
                     [x]])); /// 有t次输入，因此不清空树会造成混乱，因此每次申请新的节点要清空当前节点的孩子
    }
    rt = tre[rt][x];
    if (vis[rt] == true)
      ans =
          false; /// 预防短的号码先出现，在建长号码的树时时刻检查当前路过的节点rt是否曾被作为结束位置
  } /// 不用排序，在两处判断即可，注意这里是rt<tot!!
  if (rt < tot)
    ans =
        false; /// 预防长的号码先出现，如果这个短号码的的最终结束节点是曾被长串走过的一个节点，也就是说这个节点上标记的号数小于最大节点号数
  vis[rt] = true; /// 则说明这个终结节点曾被走过，此短号码是已出现长号码的前缀！
}
int main() {
  int t, n, num;
  char phone[12];
  scanf("%d", &t);
  while (t--) {
    tot = 0;
    num = ++tot;
    ans = true;
    memset(vis, false, sizeof(vis));
    memset(tre[num], 0, sizeof(tre[num])); /// 这里是num也行是tot也行
    scanf("%d", &n);
    for (int i = 0; i < n; i++) /// 在建树同时检索之前的号码是否和前缀重复
    {
      scanf("%s", phone);
      insert(phone, num);
    }
    printf("%s\n", ans ? "YES" : "NO");
  }
}
