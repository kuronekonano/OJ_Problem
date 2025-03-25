#include <stdio.h>
int a[2][13] = {
    0,  31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 0,
    31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; /// 两个数组，一个平年一个闰年
int rp(int x) {
  if (x % 4 == 0 && x % 100 != 0 || x % 400 == 0) /// 平润判断
    return 1;
  return 0;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int year, month, day, s, i, j, k;
    int maxday;
    scanf("%d-%d-%d", &year, &month, &day); /// 输入初始年月日
    scanf("%d", &s);                        /// 输入秒数
    int add = s / 86400;                    /// 增加的天数
    i = month;                              /// 月份
    j = day;                                /// 天数
    while (add--)                           /// 增加天数依次减少
    {

      j++;                 /// 初始天数增加
      int flag = rp(year); /// 判断当年平润
      if (j > a[flag][i])  /// 当 当月天数大于当月最大天数时
      {
        j = 1; /// 初始化成1日
        i++;   /// 月份增加
      }
      if (i > 12) /// 判断月份大于12时，年份增加，初始化月份数
      {
        i = 1;
        year++;
      }
    }
    printf("%d-%02d-%02d\n", year, i, j);
  }
  return 0;
}
