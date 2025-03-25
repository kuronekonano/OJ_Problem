#include <stdio.h> ///给出固定一圈中每个障碍物和定点的位置，
int main() {
  int n, l, i, a[55], b[55], disa[105], disb[105],
      j; /// 四个数组，其中两个用于填入原顺序数字，另外两个，存储两两障碍物之间的距离，将原数组长度翻倍后用于寻找相同的规律，捋顺一个圈的正常顺序
  while (scanf("%d%d", &n, &l) != EOF) /// n个障碍物，圆周长为l
  {
    for (i = 0; i < n; i++) /// 输入部分
    {
      scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++) {
      scanf("%d", &b[i]);
    }
    bool flag;
    for (i = 0; i < n - 1;
         i++) /// 计算每两个障碍物之间的距离，头尾两个单独计算，利用总长来做差
    {
      disa[i] = a[i + 1] - a[i];
      disb[i] = b[i + 1] - b[i];
    }
    disa[n - 1] = l - a[n - 1] + a[0]; /// 最后一个和第0(1)个距离
    disb[n - 1] = l - b[n - 1] + b[0];
    for (i = n; i < 2 * n; i++) /// 处理距离的数组，将其重复两边
    {
      disa[i] = disa[i - n];
      disb[i] = disb[i - n];
    }
    bool yes = false;
    for (i = 0; i < n; i++) /// 开始寻找其规律
    {
      if (disa[0] ==
          disb[i]) /// 从一个数组中的第一个开始一个一个与第二个数组相比，找相同
      {
        flag =
            true; /// 若找到了相同的，从那一个开始，同时增加两个数组的指针，往前比，看看能否在预定个数的障碍物中所有的距离都一样
        int k =
            1; /// 第一个数组从下一个继续比较，先找到了第0个是一样的，那么继续就是从第1个比
        for (j = i + 1; j < i + n; j++) {
          if (disa[k] !=
              disb[j]) /// 一旦遇到不一样的，退出这个循环，从上一个循环继续找开头一样的数字
          {
            flag = false;
            break;
          }
          k++;
        }
        if (flag) /// 如果上一个循环找到了，那么就不用继续找下去了
        {
          yes = true;
          break;
        }
      }
    }
    if (yes) /// 巧妙的运用了数组×2的方法整理顺序错乱的数组，然后再比较是否一样
    {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
