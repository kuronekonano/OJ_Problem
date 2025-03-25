#include <stdio.h>  //667
int yeardays(int y) // 计算每年多少天的函数
{
  if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
    return 366;
  else
    return 365;
}
int main() {
  int t, y, m, d, i;
  int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 平年
  int b[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 闰年
  scanf("%d", &t);                                                 // t组数据
  while (t--) {
    int sum = 0;
    scanf("%d%d%d", &y, &m, &d); // 年月日

    if (y == 2017) // 第一种情况，当年份为2017年时
    {
      if (m == 10) {
        printf("%d\n", 28 - d);
      } else {
        for (i = m + 1; i < 10;
             i++) // 当月除外，从下个月加到9月，这是完整的月份
        {
          sum = sum + a[i];
        }
        sum = sum + a[m] - d +
              28; // 从m月开始，因此m月只剩下a[m]-d天，最后加上十月份天数
        printf("%d\n", sum);
      }
    }

    else if (y == 2016) // 第二种情况，当年份为2016年时
    {
      for (i = 1; i < m; i++) // 因为是2016年，因此2017年完整的确定为301天
      {
        sum = sum + b[i]; // 只需要计算此时日期是16年的第几天
      }
      sum = sum + d;
      sum = 366 - sum + 301; // 然后计算今年剩余的天数，再加上17年的301天
      printf("%d\n", sum);
    }

    else // 第三种情况,当年份为2016年之前时
    {
      if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) // 判断平年闰年
      {
        for (i = 1; i < m; i++) {
          sum = sum + b[i];
        }
        sum = sum + d;
        sum = 366 - sum; // 与之前一样，判断当年剩下的天数
        for (i = y + 1; i < 2016; i++) {
          sum = sum + yeardays(i); // 从当年之后的年份往后加
        }
        printf("%d\n", sum + 667);
      } else {
        for (i = 1; i < m; i++) {
          sum = sum + a[i];
        }
        sum = sum + d;
        sum = 365 - sum; // 与之前一样，判断当年剩下的天数
        for (i = y + 1; i < 2016; i++) {
          sum = sum + yeardays(i);
        }
        printf("%d\n", sum + 667);
      }
    }
  }
  return 0;
}
