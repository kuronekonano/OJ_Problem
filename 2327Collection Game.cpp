#include <stdio.h>
#include <string.h>
int main() {
  int n, m, k, i, a[10008]; /// 递推数组
  bool vis[10008];          /// 标记数组，可以快速记录并找出当前砖块是否broken
  while (scanf("%d%d", &n, &m) != EOF) {
    memset(vis, false, sizeof(vis)); /// 初始化标记数组
    for (i = 1; i <= m; i++) {
      scanf("%d", &k); /// 标记
      vis[k] = true;
    }
    a[2] = 1; /// 递推边界
    a[3] = 2;
    a[4] = 4;
    for (i = 2; i <= n; i++) /// 从第二块砖开始计入方法数
    {
      if (i <=
          4) /// 小于4的砖块是边界点，应特殊考虑，防止被broken归零后导致末尾递推混乱
      {
        if (i == 2) /// 就是1种方法，变成0也行，不影响
          a[i] = 1;
        if (i ==
            3) /// 因为第二个砖块的方法数是动态变化的，因此是决定了第二个砖块是否broken后，再由第二个砖块推出第三个
          a[i] = a[i - 1] + 1; /// 是前面的砖块方法数+1 (加上的是一次两步的方法)
        if (i ==
            4) /// 由前两个砖块方法数推出，因为前两个方法数也不是固定的，因此递推相加而得
          a[i] = a[i - 1] + a[i - 2] + 1; /// 加上一步走三个的方法
      } else                              /// 普通情况直接递推即可
        a[i] = (a[i - 1] + a[i - 2] + a[i - 3]) % 10007; /// 记得求模
      if (vis[i] == true) /// 判断当前遍历的砖块是否broken，若broken则归零
        a[i] = 0;
    }
    printf("%d\n", a[n]);
  }
  return 0;
}
