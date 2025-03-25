#include <stdio.h>
#include <string.h>
int tree[50050], n;
int lowbit(int x) /// 寻找下一个2的节点
{                 /// lowbit2=2   lowbit4=4  lowbit8=8
  return x & (-x);
} /// 如果是-掉，那么就是找其本身，如果是+上，就是找其双倍，也就是2的下一个次方
void update(int p, int x) /// 更新每个节点的和
{
  while (p <= n) {
    tree[p] += x;   /// 对每个节点增加(减少)上更新的值
    p += lowbit(p); /// 寻找下一个节点
  }
}
int sum(int p) /// 求和，若是奇数节点，向前加上上一个总和节点的值
{              /// 若本身就是总和节点，直接返回那个节点存储的总和
  int sum = 0;
  while (p > 0) {
    sum += tree[p];
    p -= lowbit(p); /// lowbit过程减掉了其本身
  }
  return sum;
}
int main() {
  int t, cas = 0;
  scanf("%d", &t);
  while (t--) {
    int i, j;
    memset(tree, 0, sizeof(tree));
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
      scanf("%d", &j);
      update(i, j); /// 赋值的同时就开始建立树
    }
    //        for(i=1;i<=n;i++)///输出树状数组的每一个节点存储的值
    //        {
    //            printf("
    //            %d",tree[i]);///树状数组每一个2的倍数的节点，都存储着这之前所有数的和
    //        }///而奇数节点则存储其本身
    printf("Case %d:\n", ++cas);
    char a[10];
    while (scanf("%s", a) != EOF) {
      if (a[0] == 'E') {
        break;
      }
      if (a[0] == 'A') {
        scanf("%d%d", &i, &j);
        update(i, j);
      }
      if (a[0] == 'S') {
        scanf("%d%d", &i, &j);
        update(i, -j);
      }
      if (a[0] == 'Q') {
        scanf("%d%d", &i, &j);
        printf(
            "%d\n",
            sum(j) -
                sum(i -
                    1)); /// 输出时因为是一个区间内的求和，因此是两个节点存储的总和之差
      } /// 减一是因为，j表示从1到j所有营地人数总和，i表示从1到i所有人数总和，如果用j直接-i，那么会多减掉第i个营地的人数，因此要找i-1处人数总和，避免减掉i营地人数本身
    }
  }
  return 0;
}
