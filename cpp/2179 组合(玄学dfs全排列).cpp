#include <stdio.h>
#include <string.h>
int a[25], n, k;
bool vis[25];
int dfs(int num) {
  if (num > k) {
    for (int i = 1; i <= k; i++) {
      printf("%d%c", a[i], i == k ? '\n' : ' ');
    }
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i] &&
        a[num - 1] <
            i) /// 因为是集合，因此不会有重复的元素，有相同元素但排序不同的都被认为是同一个集合，并且题目要求字典序
    { /// 因此只能是升序排列，这样不会重复，且按字典序，得出，每一个全排列都是升序序列，这里注意加一个判断条件防止重复选择元素
      vis[i] = true;
      a[num] = i;
      dfs(num + 1);
      vis[i] = false;
    }
  }
}
int main() {
  int t, i;
  scanf("%d", &t);
  while (t--) {
    memset(vis, false, sizeof(vis));
    scanf("%d%d", &n, &k);
    dfs(1); /// dfs只需要一个参数，那就是递归位置
  } /// 貌似原因是把n和k都定为全局变量了，这两个值只是作为一个限度，限制搜寻的长度，限制输出的长度
} /// 并且，每次dfs都是一个升序全排列的过程，通过一个入口递归可以得到所有的情况。
