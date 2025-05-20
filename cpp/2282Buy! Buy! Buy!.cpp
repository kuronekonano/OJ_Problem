#include <stdio.h>
struct jump // 商品降价上限和降价度打包处理
{
  int sub;   // 降价价格
  int price; // 达到降价的标准
} a[1005];

int main() {
  int t, m, n, x, y, i;
  scanf("%d", &t);
  a[0].sub = 0,
  a[0].price = 0; // 定义第一个是0的初始化，以保证不能降价的商品原价计算
  while (t--) {
    scanf("%d%d", &n, &m); // 有n个标准，m个物品
    for (i = 1; i <= n; i++) {
      scanf("%d%d", &a[i].sub, &a[i].price);
    }
    int sum = 0, flag;
    for (i = 1; i <= m; i++) {
      scanf("%d", &flag);
      int max = 10000000; // 定义最大值，以取得最接近当前物品售价的最高标准
      int h = 0;          // 保证处于初始化的位置，以达到原价出售的目的
      for (int j = 1; j <= n; j++) {
        if ((max >= flag - a[j].price) &&
            (flag - a[j].price >=
             0)) // 计算当前目标
                 // 商品和当前阅览的降价标准之差，最小值则为最接近的那个标准
        {
          max = flag - a[j].price;
          h = j;
        }
      }
      sum += flag - a[h].sub; // 求和
    }
    printf("%d\n", sum);
  }
  return 0;
}
