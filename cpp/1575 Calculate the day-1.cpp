#include <stdio.h>
#include <string.h> ///当年为闰年
int main() {
  char week[9][15] = {{"Sunday"},   {"Monday"}, {"Tuesday"}, {"Wednesday"},
                      {"Thursday"}, {"Friday"}, {"Saturday"}};
  char now[11];
  while (scanf("%s", now) != EOF) {
    int nownum;
    for (int i = 0; i < 7; i++) {
      if (strcmp(now, week[i]) == 0) {
        nownum = i;
        break;
      }
    }
    int year;
    scanf("%d", &year);
    int day = year / 4;
    year = year - day;
    printf("%s\n", week[(nownum + 2 * day + year) % 7]);
  }
}
