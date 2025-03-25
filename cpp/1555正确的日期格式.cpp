#include <stdio.h>
#include <string.h>
int main() {
  char a[300];
  int i;
  while (gets(a)) {
    bool flag = true;
    int n = strlen(a);
    if (n != 10) {
      printf("No\n");
      continue;
    }
    if (a[4] != '-' || a[7] != '-') {
      printf("No\n");
      continue;
    }
    int sum = 0;
    int year = 0;
    int month = 0;
    int day = 0;
    for (i = 0; i < 10; i++) {
      if (i == 4) {
        year = sum;
        sum = 0;
        continue;
      }
      if (i == 7) {
        month = sum;
        sum = 0;
        continue;
      }
      if (a[i] < '0' || a[i] > '9') {
        printf("No\n");
        flag = false;
        break;
      } else {
        sum = sum * 10 + a[i] - '0';
      }
    }
    day = sum;
    if (year == 0 || month == 0 || day == 0) {
      printf("No\n");
      continue;
    }
    //        printf("%d %d %d\n",year,month,day);
    if (flag && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)) {
      if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||
          month == 10 || month == 12) {
        if (day >= 1 && day <= 31) {
          printf("Yes\n");
        } else {
          printf("No\n");
        }
      } else if (month == 2 || month == 4 || month == 6 || month == 9 ||
                 month == 11) {
        if (month == 2 && day <= 29 && day >= 1) {
          printf("Yes\n");
        } else if ((month == 4 || month == 6 || month == 9 || month == 11) &&
                   day <= 30 && day >= 1) {
          printf("Yes\n");
        } else {
          printf("No\n");
        }
      } else {
        printf("No\n");
      }
    } else if (flag) {
      if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||
          month == 10 || month == 12) {
        if (day >= 1 && day <= 31) {
          printf("Yes\n");
        } else {
          printf("No\n");
        }
      } else if (month == 2 || month == 4 || month == 6 || month == 9 ||
                 month == 11) {
        if (month == 2 && day <= 28 && day >= 1) {
          printf("Yes\n");
        } else if ((month == 4 || month == 6 || month == 9 || month == 11) &&
                   day <= 30 && day >= 1) {
          printf("Yes\n");
        } else {
          printf("No\n");
        }
      } else {
        printf("No\n");
      }
    }
  }
  return 0;
}
// 首先1：该字符串不能有除数字和 ‘ - ’以外的字符。年数，天数，日数不能全为零
//
//     2：有些月份的天数不能超过31，有些月份的天数不能超过30
//
//     3：平年闰年的区别
//
//     4：输入要用gets（坑点）
