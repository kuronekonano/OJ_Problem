#include <stdio.h>
#include <string.h>
int cal(int y, int m, int d) {
  int sum = 0;
  int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int day[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) {
    for (int i = 1; i < m; i++) {
      sum += day[i];
    }
    sum += d;
  } else {
    for (int i = 1; i < m; i++) {
      sum += days[i];
    }
    sum += d;
  }
  return sum;
}
int calweek(int y, int m, int d) {
  if (m == 1 || m == 2) {
    y--;
    m += 12;
  }
  int w = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400 + 1) %
          7; /// 基姆拉尔森计算公式
  return w;
}
int main() {
  int year, month, day;
  while (scanf("%d-%d-%d", &year, &month, &day) != EOF) {
    int sum = cal(year, month, day);
    char week[6];
    switch (calweek(year, month, day)) {
    case 0:
      strcpy(week, "Sun");
      break;
    case 1:
      strcpy(week, "Mon");
      break;
    case 2:
      strcpy(week, "Tue");
      break;
    case 3:
      strcpy(week, "Wed");
      break;
    case 4:
      strcpy(week, "Thu");
      break;
    case 5:
      strcpy(week, "Fri");
      break;
    case 6:
      strcpy(week, "Sat");
      break;
    }
    printf("%d-%d-%d is the %d day,it's a %s!\n", year, month, day, sum, week);
  }
}
